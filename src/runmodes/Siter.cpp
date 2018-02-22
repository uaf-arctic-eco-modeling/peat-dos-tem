#include "Siter.h"

Siter::Siter() {

}
;

Siter::~Siter() {

}
;

void Siter::init(const string &controlfile) {

	try {
		cout << "Starting initialization in Siter::init\n";

		//Input and processing for reading parameters and passing them to controller
		configin.controlfile = controlfile;
		configin.ctrl4siterun(&md); //read in model configure info from "/config/sitecontrol.txt"

		md.myid = 0;
		md.numprocs = 1;

		md.consoledebug = true;

		md.checking4run();

		fd.useseverity = md.useseverity;

		//region-level input
		rin.setModelData(&md); //for getting the directory infos from ModelData
		rin.getCO2(&rd); //checking and passing it to RegionData ?

		//grid-level input
		gin.setModelData(&md); //for getting the directory infos from ModelData
		gin.init();

		//cohort-level input : cin is for netcdf format file inputting
		//           while, scht is for after-inputting data processing and model running
		cin.setModelData(&md);
		cin.init();

		if (md.initmode == 2) {
			sitein.initSiteinFile(md.initialfile);
			runcht.setSiteinInputer(&sitein);
		} else if (md.initmode == 3) {
			if (md.runeq) {
				cout << "cannot set initmode as restart for equlibrium run  \n";
				cout << "reset to 'lookup'\n";
				md.initmode = 1;
			} else {
				resin.init(md.initialfile);
				runcht.setRestartInputer(&resin);
			}
		} else {
			md.initmode = 1;
		}

		runcht.setGridInputer(&gin); // pass gin to cht
		runcht.setCohortInputer(&cin); // pass cin to cht

		//output setting-up
		// 1)for general outputs
		sout.setModelData(&md); //get directory infos from ModelData
		sout.init(); //set netcdf files for output
		satmout.setOutputer(&sout); //define netcdf file output vars for atmosphere module
		svegout.setOutputer(&sout); //define netcdf file output vars for plant eological module
		ssslout.setOutputer(&sout); //define netcdf file output vars for ground module
		runcht.cht.setSiteOutData(&atmod, &vegod, &sslod); //output data sets connenction		
		runcht.setOutputer(&sout, &satmout, &svegout, &ssslout);
		// 2)for restart.nc outputs
		string stage = "";
		if (md.runeq) {
			stage = "-eq";
		} else { //Note: in this way, 'sp' and 'tr' can be combined, but NOT with 'eq'
			if (md.runsp) {
				stage = "-sp";
			}
			if (md.runtr) {
				stage = "-tr";
			}
		}
		resout.setRestartOutData(&resod);
		resout.init(md.outputdir, stage, md.numprocs, md.myid); //define netcdf file for restart output
		runcht.cht.setRestartOutData(&resod); //restart output data sets connenction
		runcht.setRestartOutputer(&resout);

		// 3) for soilclm.nc outputs, if needed

		//set up data connection (initialization)
		bd.setEnvData(&ed);
		sgrid.setEnvData(&ed); //define data-structures for ONE common grid
		sgrid.setRegionData(&rd);
		sgrid.setGridData(&gd);

		runcht.cht.setTime(&timer); //define data-structures for ONE common cohort
		runcht.cht.setProcessData(&ed, &bd, &fd);
		runcht.cht.setModelData(&md);
		runcht.cht.setInputData(&rd, &gd, &cd);
		runcht.cht.setAtmData(&sgrid);

		//initializing ONE common cohort 		 		 		
		runcht.cht.init();

	} catch (Exception &exception) {
		cout << "problem in initialize in Siter::init\n";
		exception.mesg();
		exit(-1);
	}

}
;

void Siter::run() {

	// cohort id consistency in different run modes
	int chtid = 1;
	int error = 0;

	int eqcid = 0; //the record order in the input files, NOT the cohort ID (chtid)
	int cid = 0; //the record order in the input files, NOT the cohort ID (chtid)
	int rescid = 0; //the record order in the input files, NOT the cohort ID (chtid)

	if (md.runeq) {
		cd.eqchtid = chtid;
		cid = eqcid;
		eqcid = cin.getEqRecID(cd.eqchtid);
	} else {
		if (md.runtr) {
			cd.trchtid = chtid;
			cid = cin.getTrRecID(cd.trchtid);
			cin.getSpchtid5TrFile(cd.spchtid, cid);

			int spcid = cin.getSpRecID(cd.spchtid);
			cin.getEqchtid5SpFile(cd.eqchtid, spcid);
			eqcid = cin.getEqRecID(cd.eqchtid);

			cd.reschtid = cd.spchtid; //restart id is of sp-run's spchtid
			if (md.initmode == 3)
				rescid = resin.getRecordId(cd.reschtid);
		} else if (md.runsp) {
			cd.spchtid = chtid;
			cid = cin.getSpRecID(cd.spchtid);
			cin.getEqchtid5SpFile(cd.eqchtid, cid);
			eqcid = cin.getEqRecID(cd.eqchtid);

			cd.reschtid = cd.eqchtid; //restart id is of eq-run's eqchtid
			if (md.initmode == 3)
				rescid = resin.getRecordId(cd.reschtid);
		}
	}
	cin.getCRUID(cd.cruid, eqcid);

	//loop through grids
	int gid = 0;

	try {
		gid = gin.getGridRecID(cd.cruid);
		if (gid < 0) {
			cout << "grid not exists in Siter::run\n";
			exit(-1);
		}
		gin.getGridData(&gd, gid); //reading the grid-data for gid

		error = sgrid.reinit(gid); //reinit for a new grid
		if (error < 0) {
			cout << "problem in reinitialize grid in Siter::run\n";
			exit(-1);
		}

	} catch (Exception &exception) {
		cout << "problem in reinitialize grid in Siter::run\n";
		exception.mesg();
		exit(-1);
	}

	//loop through cohorts
	try {
		runcht.jcalifilein = true; //switch for reading input Jcalinput.txt, the default is true (must be done before re-initiation)
		runcht.ccdriverout = false; //switch for update cali. driver file, the default is false

		error = runcht.reinit(cid, eqcid, rescid); //reinit for a new cohort
	} catch (Exception &exception) {
		cout << "problem in reinitialize cohort in Siter::run\n";
		exception.mesg();
		exit(-1);
	}

	if (error != 0) {
		cout << "Error for reinit cohort: " << chtid << " - EXIT code "
				<< error << "\n";
		exit(-1);
	} else {
		cout << "cohort: " << chtid << " - running! \n";
		runcht.run();
	}

	runcht.cht.cohortcount++;

}

