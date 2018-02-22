/*
 * This class is for output variables in TEM regional run
 * in netcdf format
 * 
 */

#include "RegnOutputer.h"

RegnOutputer::RegnOutputer() {

}
;

RegnOutputer::~RegnOutputer() {
	if (rFile != NULL) {
		rFile->close();
		delete rFile;
	}

}
;

void RegnOutputer::missingValues(const int & MAX_DRV_YR, const int & chtcount) {
	regnod->status = -1;
	for (int iy = 0; iy < MAX_DRV_YR; iy++) {

		regnod->yrorgn = -999;
		regnod->yravln = -999;
		regnod->yrvegn = -999;
		regnod->yrnpp = -999;
		regnod->yrgpp = -999;
		regnod->yrrh = -999;
		regnod->yrrg = -999;
		regnod->yrrm = -999;
		regnod->yrburnvegc = -999;
		regnod->yrburnsoic = -999;

		regnod->yrtmin10 = -999;
		regnod->yrtrock34 = -999;
		regnod->yrunfrzcolumn = -999;

		regnod->yrtshlw = -999;
		regnod->yrtdeep = -999;
		regnod->yrtmine = -999;

		regnod->yrvwcshlw = -999;
		regnod->yrvwcdeep = -999;
		regnod->yrvwcmine = -999;
		regnod->yrvwcmin10 = -999;

		regnod->yrvegc = -999;
		regnod->yrminc = -999;
		regnod->yrshlwc = -999;
		regnod->yrdeepc = -999;

		regnod->yreet = -999;
		regnod->yrpet = -999;
		regnod->yrwtd = -999;
		regnod->yrch4flux = -999;
		regnod->yrhco2flux = -999;
		regnod->yraco2flux = -999;
		regnod->yrdfratio = -999;
		regnod->yrco2ch4 = -999;
		regnod->yroxid = -999;
		regnod->yrald = -999;
		regnod->yrperm = -999;
		regnod->yrmossdz = -999;
		regnod->yrshlwdz = -999;
		regnod->yrdeepdz = -999;
		regnod->yrgrowstart = -999;
		regnod->yrgrowend = -999;

		regnod->yrqdrain = -999;
		regnod->yrqrunoff = -999;

		regnod->yrninput = -999;
		regnod->yrnlost = -999;

		regnod->yrlai = -999;
		regnod->yrnetnmin = -999;
		regnod->yrnuptake = -999;
		regnod->yrltrfalc = -999;
		regnod->yrltrfaln = -999;
		regnod->yrburnthick = -999;
		regnod->yrysf = -999;

		outputYearCohortVars(iy, chtcount);
	}

}
;

inline string itos(int n) {
	stringstream ss;
	ss << n;
	return ss.str();
}

void RegnOutputer::init(string& outputdir, const int & myid, string & stage,
		int MAX_DRV_YR) {

	string moncfn = outputdir + "output" + stage + ".nc";

	rFile = new NcFile(moncfn.c_str(), NcFile::Replace);

	chtD = rFile->add_dim("CHTID");
	yearD = rFile->add_dim("YEAR", MAX_DRV_YR);

	chtidCYV = rFile->add_var("CHTID", ncInt, chtD);
	statusCYV = rFile->add_var("STATUS", ncInt, chtD);
	nppCYV = rFile->add_var("NPP", ncFloat, chtD, yearD);
	gppCYV = rFile->add_var("GPP", ncFloat, chtD, yearD);
	rhCYV = rFile->add_var("RH", ncFloat, chtD, yearD);
	rmCYV = rFile->add_var("RM", ncFloat, chtD, yearD);
	rgCYV = rFile->add_var("RG", ncFloat, chtD, yearD);
	burnsoicCYV = rFile->add_var("BURNSOIC", ncFloat, chtD, yearD);
	burnvegcCYV = rFile->add_var("BURNVEGC", ncFloat, chtD, yearD);

	vegcCYV = rFile->add_var("VEGC", ncFloat, chtD, yearD);
	mincCYV = rFile->add_var("MINEC", ncFloat, chtD, yearD);
	shlwcCYV = rFile->add_var("SHLWC", ncFloat, chtD, yearD);
	deepcCYV = rFile->add_var("DEEPC", ncFloat, chtD, yearD);

	orgnCYV = rFile->add_var("ORGN", ncFloat, chtD, yearD);
	avlnCYV = rFile->add_var("AVLN", ncFloat, chtD, yearD);
	vegnCYV = rFile->add_var("VEGN", ncFloat, chtD, yearD);
	ysfCYV = rFile->add_var("YSF", ncFloat, chtD, yearD);

	eetCYV = rFile->add_var("EET", ncFloat, chtD, yearD);
	petCYV = rFile->add_var("PET", ncFloat, chtD, yearD);
	wtdCYV = rFile->add_var("WATERTAB", ncFloat, chtD, yearD);
	ch4fluxCYV = rFile->add_var("CH4FLUX", ncFloat, chtD, yearD);
	hco2fluxCYV = rFile->add_var("HCO2FLUX", ncFloat, chtD, yearD);
	aco2fluxCYV = rFile->add_var("ACO2FLUX", ncFloat, chtD, yearD);
	dfratioCYV = rFile->add_var("DFRATIO", ncFloat, chtD, yearD);
	co2ch4CYV = rFile->add_var("CO2CH4", ncFloat, chtD, yearD);
	oxidCYV = rFile->add_var("OXID", ncFloat, chtD, yearD);
	permCYV = rFile->add_var("PERMAFROST", ncFloat, chtD, yearD);
	aldCYV = rFile->add_var("ALD", ncFloat, chtD, yearD);

	unfrzcolumnCYV = rFile->add_var("UNFRZCOLUMN", ncFloat, chtD, yearD);
	trock34CYV = rFile->add_var("TROCK34M", ncFloat, chtD, yearD);

	tshlwCYV = rFile->add_var("TSHLW", ncFloat, chtD, yearD);
	tdeepCYV = rFile->add_var("TDEEP", ncFloat, chtD, yearD);
	tmineCYV = rFile->add_var("TMINE", ncFloat, chtD, yearD);
	tmin10CYV = rFile->add_var("TMIN10CM", ncFloat, chtD, yearD);

	vwcshlwCYV = rFile->add_var("VWCSHLW", ncFloat, chtD, yearD);
	vwcdeepCYV = rFile->add_var("VWCDEEP", ncFloat, chtD, yearD);
	vwcmineCYV = rFile->add_var("VWCMINE", ncFloat, chtD, yearD);
	vwcmin10CYV = rFile->add_var("VWCMIN10CM", ncFloat, chtD, yearD);

	growstartCYV = rFile->add_var("GROWSTART", ncFloat, chtD, yearD);
	growendCYV = rFile->add_var("GROWEND", ncFloat, chtD, yearD);

	laiCYV = rFile->add_var("LAI", ncFloat, chtD, yearD);
	netnminCYV = rFile->add_var("NETNMIN", ncFloat, chtD, yearD);
	nuptakeCYV = rFile->add_var("NUPTAKE", ncFloat, chtD, yearD);
	ltrfalcCYV = rFile->add_var("LTRFALC", ncFloat, chtD, yearD);
	ltrfalnCYV = rFile->add_var("LTRFALN", ncFloat, chtD, yearD);

	mossdzCYV = rFile->add_var("MOSSDZ", ncFloat, chtD, yearD);
	shlwdzCYV = rFile->add_var("SHLWDZ", ncFloat, chtD, yearD);
	deepdzCYV = rFile->add_var("DEEPDZ", ncFloat, chtD, yearD);

	qdrainCYV = rFile->add_var("DRAINAGE", ncFloat, chtD, yearD);
	qrunoffCYV = rFile->add_var("RUNOFF", ncFloat, chtD, yearD);

	ninputCYV = rFile->add_var("NINPUT", ncFloat, chtD, yearD);
	nlostCYV = rFile->add_var("NLOST", ncFloat, chtD, yearD);

	burnthickCYV = rFile->add_var("BURNTHICK", ncFloat, chtD, yearD);

}
;

void RegnOutputer::outputYearCohortVars(const int & yrind, const int & chtcount) {

	chtidCYV->set_cur(chtcount);
	chtidCYV->put(&regnod->chtid, 1);

	statusCYV->set_cur(chtcount);
	statusCYV->put(&regnod->status, 1);

	nppCYV->set_cur(chtcount, yrind);
	nppCYV->put(&regnod->yrnpp, 1, 1);

	gppCYV->set_cur(chtcount, yrind);
	gppCYV->put(&regnod->yrgpp, 1, 1);

	rhCYV->set_cur(chtcount, yrind);
	rhCYV->put(&regnod->yrrh, 1, 1);

	rmCYV->set_cur(chtcount, yrind);
	rmCYV->put(&regnod->yrrm, 1, 1);

	rgCYV->set_cur(chtcount, yrind);
	rgCYV->put(&regnod->yrrg, 1, 1);

	burnsoicCYV->set_cur(chtcount, yrind);
	burnsoicCYV->put(&regnod->yrburnsoic, 1, 1);

	burnvegcCYV->set_cur(chtcount, yrind);
	burnvegcCYV->put(&regnod->yrburnvegc, 1, 1);

	orgnCYV->set_cur(chtcount, yrind);
	orgnCYV->put(&regnod->yrorgn, 1, 1);

	avlnCYV->set_cur(chtcount, yrind);
	avlnCYV->put(&regnod->yravln, 1, 1);

	vegnCYV->set_cur(chtcount, yrind);
	vegnCYV->put(&regnod->yrvegn, 1, 1);

	vegcCYV->set_cur(chtcount, yrind);
	vegcCYV->put(&regnod->yrvegc, 1, 1);

	mincCYV->set_cur(chtcount, yrind);
	mincCYV->put(&regnod->yrminc, 1, 1);

	shlwcCYV->set_cur(chtcount, yrind);
	shlwcCYV->put(&regnod->yrshlwc, 1, 1);

	deepcCYV->set_cur(chtcount, yrind);
	deepcCYV->put(&regnod->yrdeepc, 1, 1);

	ysfCYV->set_cur(chtcount, yrind);
	ysfCYV->put(&regnod->yrysf, 1, 1);

	eetCYV->set_cur(chtcount, yrind);
	eetCYV->put(&regnod->yreet, 1, 1);

	petCYV->set_cur(chtcount, yrind);
	petCYV->put(&regnod->yrpet, 1, 1);

	wtdCYV->set_cur(chtcount, yrind);
	wtdCYV->put(&regnod->yrwtd, 1, 1);

	ch4fluxCYV->set_cur(chtcount, yrind);
	ch4fluxCYV->put(&regnod->yrch4flux, 1, 1);

	hco2fluxCYV->set_cur(chtcount, yrind);
	hco2fluxCYV->put(&regnod->yrhco2flux, 1, 1);

	aco2fluxCYV->set_cur(chtcount, yrind);
	aco2fluxCYV->put(&regnod->yraco2flux, 1, 1);

	dfratioCYV->set_cur(chtcount, yrind);
	dfratioCYV->put(&regnod->yrdfratio, 1, 1);

	co2ch4CYV->set_cur(chtcount, yrind);
	co2ch4CYV->put(&regnod->yrco2ch4, 1, 1);

	oxidCYV->set_cur(chtcount, yrind);
	oxidCYV->put(&regnod->yroxid, 1, 1);

	permCYV->set_cur(chtcount, yrind);
	permCYV->put(&regnod->yrperm, 1, 1);

	aldCYV->set_cur(chtcount, yrind);
	aldCYV->put(&regnod->yrald, 1, 1);

	growstartCYV->set_cur(chtcount, yrind);
	growstartCYV->put(&regnod->yrgrowstart, 1, 1);

	growendCYV->set_cur(chtcount, yrind);
	growendCYV->put(&regnod->yrgrowend, 1, 1);

	trock34CYV->set_cur(chtcount, yrind);
	trock34CYV->put(&regnod->yrtrock34, 1, 1);

	unfrzcolumnCYV->set_cur(chtcount, yrind);
	unfrzcolumnCYV->put(&regnod->yrunfrzcolumn, 1, 1);

	tshlwCYV->set_cur(chtcount, yrind);
	tshlwCYV->put(&regnod->yrtshlw, 1, 1);

	tdeepCYV->set_cur(chtcount, yrind);
	tdeepCYV->put(&regnod->yrtdeep, 1, 1);

	tmineCYV->set_cur(chtcount, yrind);
	tmineCYV->put(&regnod->yrtmine, 1, 1);

	tmin10CYV->set_cur(chtcount, yrind);
	tmin10CYV->put(&regnod->yrtmin10, 1, 1);

	vwcshlwCYV->set_cur(chtcount, yrind);
	vwcshlwCYV->put(&regnod->yrvwcshlw, 1, 1);

	vwcdeepCYV->set_cur(chtcount, yrind);
	vwcdeepCYV->put(&regnod->yrvwcdeep, 1, 1);

	vwcmineCYV->set_cur(chtcount, yrind);
	vwcmineCYV->put(&regnod->yrvwcmine, 1, 1);

	vwcmin10CYV->set_cur(chtcount, yrind);
	vwcmin10CYV->put(&regnod->yrvwcmin10, 1, 1);

	laiCYV->set_cur(chtcount, yrind);
	laiCYV->put(&regnod->yrlai, 1, 1);

	netnminCYV->set_cur(chtcount, yrind);
	netnminCYV->put(&regnod->yrnetnmin, 1, 1);

	nuptakeCYV->set_cur(chtcount, yrind);
	nuptakeCYV->put(&regnod->yrnuptake, 1, 1);

	ltrfalcCYV->set_cur(chtcount, yrind);
	ltrfalcCYV->put(&regnod->yrltrfalc, 1, 1);

	ltrfalnCYV->set_cur(chtcount, yrind);
	ltrfalnCYV->put(&regnod->yrltrfaln, 1, 1);

	mossdzCYV->set_cur(chtcount, yrind);
	mossdzCYV->put(&regnod->yrmossdz, 1, 1);

	shlwdzCYV->set_cur(chtcount, yrind);
	shlwdzCYV->put(&regnod->yrshlwdz, 1, 1);

	deepdzCYV->set_cur(chtcount, yrind);
	deepdzCYV->put(&regnod->yrdeepdz, 1, 1);

	qdrainCYV->set_cur(chtcount, yrind);
	qdrainCYV->put(&regnod->yrqdrain, 1, 1);

	qrunoffCYV->set_cur(chtcount, yrind);
	qrunoffCYV->put(&regnod->yrqrunoff, 1, 1);

	ninputCYV->set_cur(chtcount, yrind);
	ninputCYV->put(&regnod->yrninput, 1, 1);

	nlostCYV->set_cur(chtcount, yrind);
	nlostCYV->put(&regnod->yrnlost, 1, 1);

	burnthickCYV->set_cur(chtcount, yrind);
	burnthickCYV->put(&regnod->yrburnthick, 1, 1);

}
;

void RegnOutputer::setOutData(RegnOutData *regnodp) {
	regnod = regnodp;
}
;
