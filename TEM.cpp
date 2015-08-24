////////////////////////////////////////////////////////////////////////////////////////
/* 
 *  TEM.cpp
 *  main program for running DOS-TEM
 *  
 *  It runs at 2 run-mods:
 *      (1) site-specific
 * 		(2) regional (multiple sites)
 * 
 * Authors: Shuhua Yi - the original codes
 * 		    Fengming Yuan - re-coding for (1) easily code managing;
 *                                        (2) java interface developing for calibration;
 *                                        (3) stand-alone application of TEM (java-c++)
 *                                        (4) inputs/outputs using netcdf format, have to be modified
 *                                        to fix memory-leaks
 *
 * Affilation: Spatial Ecology Lab, University of Alaska Fairbanks 
 *
 * started: 10/31/2006 
 * last modified: 09/25/2009
 */
/////////////////////////////////////////////////////////////////////////////////////////         

//include        

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <exception>
using namespace std;

#include "TEMMOD.h"         // set run-mode and output option(s) for site-run 
#ifdef SITERUN
#include "runmodes/Siter.h"
#endif

#ifdef REGNRUN
#include "runmodes/Regioner.h"
#endif

/////////////////////////////////////////////////////////////////////////////////

int main(int argc, char* argv[]) {

#ifdef REGNRUN
	time_t stime;
	time_t etime;
	stime=time(NULL);
	cout <<"run TEM regionally - start @"<<ctime(&stime)<<"\n";

	string controlfile="";
	if(argc==1) { //if there is no control file specified
		controlfile ="config/regncontrol.txt";
	} else if(argc ==2) {
		controlfile =argv[1];
	}

	Regioner regner;

	regner.init(controlfile);

	regner.run();

	etime=time(NULL);
	cout <<"run TEM regionally - done @"<<ctime(&etime)<<"\n";
	cout <<"total seconds: "<<difftime(etime, stime)<<"\n";

#endif

#ifdef SITERUN

	time_t stime;
	time_t etime;
	stime = time(NULL);
	cout << "run TEM stand-alone - start @" << ctime(&stime) << "\n";

	/////////////////////////////////////////////////////////////////////
	///////////////parameter////////////////////////////////////////////
#ifdef INVERSE
	ofstream mfile;

	for (int icount = 0; icount < 3; icount++) {
		if (argc == 1)
			mfile.open("config/sitecontrol.txt");
		else
			mfile.open(argv[1]);

		if (icount == 0) {
			if (mfile.is_open()) {
				mfile << "Test_Siter/output/" << endl;
				mfile << "Test_Siter/regiondata/" << endl;
				mfile << "Test_Siter/griddata/" << endl;
				mfile << "Test_Siter/cohort/eq/" << endl;
				mfile << "Test_Siter/cohort/sp/" << endl;
				mfile << "Test_Siter/cohort/tr/" << endl;
				mfile << "Test_Siter/output/restart-eq.nc" << endl;
				mfile << "config/" << endl;
				mfile << "eq" << endl;
				mfile << "lookup" << endl;
                mfile<<"normal"<<endl; //climate, dynamic or normal
                mfile<<"initial"<<endl; //CO2, dynamic or initial
				mfile << "Test-TEM-GUI" << endl;
				mfile.close();
			} else {
				cout << "Failed to open control file for equilibrium run" << endl;
				exit(-1);
			}
		} else if (icount == 1){
			if (mfile.is_open()) {
				mfile<<"Test_Siter/output/"<<endl;
				mfile<<"Test_Siter/regiondata/"<<endl;
				mfile<<"Test_Siter/griddata/"<<endl;
				mfile<<"Test_Siter/cohort/eq/"<<endl;
				mfile<<"Test_Siter/cohort/sp/"<<endl;
				mfile<<"Test_Siter/cohort/tr/"<<endl;
				mfile<<"Test_Siter/output/restart-eq.nc"<<endl;
				mfile<<"config/"<<endl;
				mfile<<"sp"<<endl;
				mfile<<"restart"<<endl;
                mfile<<"normal"<<endl; //climate, dynamic or normal
                mfile<<"initial"<<endl; //CO2, dynamic or initial
				mfile<<"Test-TEM-GUI"<<endl;
				mfile.close();
			} else {
				cout << "Failed to open control file for spinup run" << endl;
				exit(-1);
			}
		} else if (icount == 2){
			if (mfile.is_open()) {
				mfile<<"Test_Siter/output/"<<endl;
				mfile<<"Test_Siter/regiondata/"<<endl;
				mfile<<"Test_Siter/griddata/"<<endl;
				mfile<<"Test_Siter/cohort/eq/"<<endl;
				mfile<<"Test_Siter/cohort/sp/"<<endl;
				mfile<<"Test_Siter/cohort/tr/"<<endl;
				mfile<<"Test_Siter/output/restart-sp.nc"<<endl;
				mfile<<"config/"<<endl;
				mfile<<"tr"<<endl;
				mfile<<"restart"<<endl;
				mfile<<"normal"<<endl; //climate, dynamic or normal
				mfile<<"dynamic"<<endl; //CO2, dynamic or initial
				mfile<<"Test-TEM-GUI"<<endl;
				mfile.close();
			} else {
				cout << "Failed to open control file for transient run" << endl;
				exit(-1);
			}
		}
#endif
		/////////////////////////////////////////////////////////////////////
		string controlfile="";
		if (argc == 1) { //if there is no control file specified
			controlfile = "config/sitecontrol.txt";
		} else if (argc == 2) {
			controlfile = argv[1];
		}

		Siter siter;
		siter.init(controlfile);

		siter.run();

#ifdef INVERSE
		if (icount==0)
			cout<<"==========End of Equlibrium Run=========="<<endl;
		else if (icount == 1)
			cout<<"==========End of Spinup Run=========="<<endl;
		else if (icount == 2)
			cout<<"==========End of Transient Run=========="<<endl;

	}
#endif

	etime = time(NULL);
	cout << "run TEM stand-alone - done @" << ctime(&etime) << "\n";
	cout << "total seconds: " << difftime(etime, stime) << "\n";

#endif

	return 0;

}
