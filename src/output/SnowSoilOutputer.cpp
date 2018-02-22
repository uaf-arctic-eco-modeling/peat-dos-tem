/*! \file 
 */

#include "SnowSoilOutputer.h"

SnowSoilOutputer::SnowSoilOutputer() {

}
;

void SnowSoilOutputer::outputCohortErrorCode(int errorids[]) {

#ifdef ODAY
	errorCDV->put_rec(&errorids[0]);
#endif

	if (OMONTH) {
		errorCMV->put_rec(&errorids[0]);
	}

	if (OYEAR) {
		errorCYV->put_rec(&errorids[0]);
	}

}
;

#ifdef ODAY
void SnowSoilOutputer::outputDayCohortVars(const int & yrcnt) {
	//int yrcnt = outputer->getYrInd();
	frzfntCDV->put_rec(&sslod->frzfnt[0][0], yrcnt);
	thwfntCDV->put_rec(&sslod->thwfnt[0][0], yrcnt);
	growCDV->put_rec(&sslod->growd[0], yrcnt);
	numiterCDV->put_rec(&sslod->numiter[0], yrcnt);
	numiterliqCDV->put_rec(&sslod->numiterliq[0], yrcnt);
	snowthickCDV->put_rec(&sslod->snowthick[0], yrcnt);

	sweCDV->put_rec(&sslod->swed[0], yrcnt);
	ssublCDV->put_rec(&sslod->ssubld[0], yrcnt);
	smeltCDV->put_rec(&sslod->smeltd[0], yrcnt);
	sevapCDV->put_rec(&sslod->sevapd[0], yrcnt);
	snradreflCDV->put_rec(&sslod->snradrefld[0], yrcnt);
	slradreflCDV->put_rec(&sslod->slradrefld[0], yrcnt);

	infilCDV->put_rec(&sslod->infild[0], yrcnt);
	wtCDV->put_rec(&sslod->wtd[0], yrcnt);
	ch4fluxCDV->put_rec(&sslod->dch4flux[0], yrcnt);
	hco2fluxCDV->put_rec(&sslod->dhco2flux[0], yrcnt);
	aco2fluxCDV->put_rec(&sslod->daco2flux[0], yrcnt);
	dfratioCDV->put_rec(&sslod->ddfratio[0], yrcnt);
	co2ch4CDV->put_rec(&sslod->dco2ch4[0], yrcnt);
	oxidCDV->put_rec(&sslod->doxid[0], yrcnt);
	fsatCDV->put_rec(&sslod->fsatd[0], yrcnt);
	qoverCDV->put_rec(&sslod->qoverd[0], yrcnt);
	qdrainCDV->put_rec(&sslod->qdraind[0], yrcnt);

	liqCDV->put_rec(&sslod->liqd[0][0], yrcnt);
	iceCDV->put_rec(&sslod->iced[0][0], yrcnt);

	tsCDV->put_rec(&sslod->tsd[0][0], yrcnt);
	ch4CDV->put_rec(&sslod->ch4[0][0], yrcnt);
	tcondCDV->put_rec(&sslod->tcondd[0][0], yrcnt);

}

void SnowSoilOutputer::defineDayCohortVars() {
	daycf = siteoutputer->dayChtFile;
	dcyearD = daycf->get_dim("year");
	dcdayD = daycf->get_dim("day");
	dcfrontD = daycf->get_dim("FRONTLAYER");
	dclayerD = daycf->get_dim("dlayer");
	dcsnlayD = daycf->get_dim("snlayer");
	errorCDV = daycf->add_var("ERRORID", ncInt);

	growCDV = daycf->add_var("GROW", ncFloat, dcyearD, dcdayD);

	snowthickCDV = daycf->add_var("SNOWTHICK", ncFloat, dcyearD, dcdayD);
	snowthickCDV->add_att("units", "m");
	snowthickCDV->add_att("title", "Snow Thickness");
	snowthickCDV->add_att("valid_min", 0);
	snowthickCDV->add_att("valid_max", 0.8);

	sweCDV = daycf->add_var("SWE", ncFloat, dcyearD, dcdayD);
	smeltCDV = daycf->add_var("SMELT", ncFloat, dcyearD, dcdayD);
	ssublCDV = daycf->add_var("SSUBL", ncFloat, dcyearD, dcdayD);
	sevapCDV = daycf->add_var("SEVAP", ncFloat, dcyearD, dcdayD);

	infilCDV = daycf->add_var("INFIL", ncFloat, dcyearD, dcdayD);
	wtCDV = daycf->add_var("WATTAB", ncFloat, dcyearD, dcdayD);
	ch4fluxCDV = daycf->add_var("CH4FLUX", ncFloat, dcyearD, dcdayD);
	hco2fluxCDV = daycf->add_var("HCO2FLUX", ncFloat, dcyearD, dcdayD);
	aco2fluxCDV = daycf->add_var("ACO2FLUX", ncFloat, dcyearD, dcdayD);
	dfratioCDV = daycf->add_var("DFRATIO", ncFloat, dcyearD, dcdayD);
	co2ch4CDV = daycf->add_var("CO2CH4", ncFloat, dcyearD, dcdayD);
	oxidCDV = daycf->add_var("OXID", ncFloat, dcyearD, dcdayD);
	fsatCDV = daycf->add_var("FRASAT", ncFloat, dcyearD, dcdayD);
	qoverCDV = daycf->add_var("QOVER", ncFloat, dcyearD, dcdayD);
	qdrainCDV = daycf->add_var("QDRAIN", ncFloat, dcyearD, dcdayD);

	snradreflCDV = daycf->add_var("SNRADREFL", ncFloat, dcyearD, dcdayD);
	slradreflCDV = daycf->add_var("SLRADREFL", ncFloat, dcyearD, dcdayD);

	numiterCDV = daycf->add_var("NUMITER", ncFloat, dcyearD, dcdayD);
	numiterliqCDV = daycf->add_var("NUMITERLIQ", ncFloat, dcyearD, dcdayD);
	//	snmassV = daycf->add_var("SNOMAS", ncFloat, dcyearD,   dcdayD);

	snzCDV = daycf->add_var("SNOLAY", ncFloat, dcyearD, dcdayD, dcsnlayD);
	//sndenCDV =daycf->add_var("SNODEN", ncFloat, dcyearD,  dcdayD, dcsnlayD);
	frzfntCDV = daycf->add_var("FRZFNT", ncFloat, dcyearD, dcdayD, dcfrontD);
	thwfntCDV = daycf->add_var("THWFNT", ncFloat, dcyearD, dcdayD, dcfrontD);

	liqCDV = daycf->add_var("SOILLIQ", ncFloat, dcyearD, dcdayD, dclayerD);
	iceCDV = daycf->add_var("SOILICE", ncFloat, dcyearD, dcdayD, dclayerD);

	tsCDV = daycf->add_var("TS", ncFloat, dcyearD, dcdayD, dclayerD);
	ch4CDV = daycf->add_var("CH4", ncFloat, dcyearD, dcdayD, dclayerD);
	tcondCDV = daycf->add_var("TCOND", ncFloat, dcyearD, dcdayD, dclayerD);

}

#endif

void SnowSoilOutputer::outputMonthCohortVars(const int & yrcnt) {

	tsCMV->put_rec(&sslod->ts[0][0], yrcnt);
	ch4CMV->put_rec(&sslod->ch4[0][0], yrcnt);
	liqCMV->put_rec(&sslod->liq[0][0], yrcnt);
	vwcCMV->put_rec(&sslod->vwc[0][0], yrcnt);

	iceCMV->put_rec(&sslod->ice[0][0], yrcnt);
	dzCMV->put_rec(&sslod->dz[0][0], yrcnt);
	zCMV->put_rec(&sslod->z[0][0], yrcnt);
	porCMV->put_rec(&sslod->por[0][0], yrcnt);
	typeCMV->put_rec(&sslod->type[0][0], yrcnt);
	reacCMV->put_rec(&sslod->reac[0][0], yrcnt);
	noncCMV->put_rec(&sslod->nonc[0][0], yrcnt);

	rhmoistCMV->put_rec(&sslod->rhmoist[0][0], yrcnt);
	rhq10CMV->put_rec(&sslod->rhq10[0][0], yrcnt);
	ksoilCMV->put_rec(&sslod->ksoil[0][0], yrcnt);
	kdlCMV->put_rec(&sslod->kdl[0][0], yrcnt);
	kdrCMV->put_rec(&sslod->kdr[0][0], yrcnt);
	kdnCMV->put_rec(&sslod->kdn[0][0], yrcnt);

	kdlCMV_m->put_rec(&sslod->kdl_m[0][0], yrcnt);
	kdrCMV_m->put_rec(&sslod->kdr_m[0][0], yrcnt);
	kdnCMV_m->put_rec(&sslod->kdn_m[0][0], yrcnt);

	rrhCMV->put_rec(&sslod->rrh[0][0], yrcnt);
	nrhCMV->put_rec(&sslod->nrh[0][0], yrcnt);

	growpctCMV->put_rec(&sslod->growpct[0], yrcnt);
	watertabCMV->put_rec(&sslod->watertab[0], yrcnt);
	ch4fluxCMV->put_rec(&sslod->mch4flux[0], yrcnt);
	hco2fluxCMV->put_rec(&sslod->mhco2flux[0], yrcnt);
	aco2fluxCMV->put_rec(&sslod->maco2flux[0], yrcnt);
	dfratioCMV->put_rec(&sslod->mdfratio[0], yrcnt);
	co2ch4CMV->put_rec(&sslod->mco2ch4[0], yrcnt);
	oxidCMV->put_rec(&sslod->moxid[0], yrcnt);

	orgnCMV->put_rec(&sslod->orgn[0], yrcnt);
	avlnCMV->put_rec(&sslod->avln[0], yrcnt);
	netnminCMV->put_rec(&sslod->netnmin[0], yrcnt);
	nimmobCMV->put_rec(&sslod->nimmob[0], yrcnt);

	nlostCMV->put_rec(&sslod->nlost[0], yrcnt);
	ninputCMV->put_rec(&sslod->ninput[0], yrcnt);

	reacsumCMV->put_rec(&sslod->reacsum[0], yrcnt);
	noncsumCMV->put_rec(&sslod->noncsum[0], yrcnt);
	shlwcsumCMV->put_rec(&sslod->shlwcsum[0], yrcnt);
	deepcsumCMV->put_rec(&sslod->deepcsum[0], yrcnt);
	minecsumCMV->put_rec(&sslod->minecsum[0], yrcnt);

	sninflCMV->put_rec(&sslod->sninfl[0], yrcnt);

	sevapCMV->put_rec(&sslod->sevap[0], yrcnt);
	ssublCMV->put_rec(&sslod->ssubl[0], yrcnt);

	mossdzCMV->put_rec(&sslod->mossdz[0], yrcnt);
	shlwdzCMV->put_rec(&sslod->shlwdz[0], yrcnt);
	deepdzCMV->put_rec(&sslod->deepdz[0], yrcnt);

}

void SnowSoilOutputer::defineMonthCohortVars() {
	moncf = siteoutputer->monChtFile;
	mcyearD = moncf->get_dim("year");
	mclayerD = moncf->get_dim("layer");
	mcmonD = moncf->get_dim("month");

	growpctCMV = moncf->add_var("GROWPCT", ncFloat, mcyearD, mcmonD);
	tsCMV = moncf->add_var("TS", ncFloat, mcyearD, mcmonD, mclayerD);
	ch4CMV = moncf->add_var("CH4", ncFloat, mcyearD, mcmonD, mclayerD);
	liqCMV = moncf->add_var("LIQVWC", ncFloat, mcyearD, mcmonD, mclayerD);
	vwcCMV = moncf->add_var("VWC", ncFloat, mcyearD, mcmonD, mclayerD);

	iceCMV = moncf->add_var("ICEVWC", ncFloat, mcyearD, mcmonD, mclayerD);
	dzCMV = moncf->add_var("DZ", ncFloat, mcyearD, mcmonD, mclayerD);
	zCMV = moncf->add_var("Z", ncFloat, mcyearD, mcmonD, mclayerD);
	porCMV = moncf->add_var("PORO", ncFloat, mcyearD, mcmonD, mclayerD);
	typeCMV = moncf->add_var("TYPE", ncFloat, mcyearD, mcmonD, mclayerD);
	reacCMV = moncf->add_var("REAC", ncFloat, mcyearD, mcmonD, mclayerD);
	noncCMV = moncf->add_var("NONC", ncFloat, mcyearD, mcmonD, mclayerD);

	orgnCMV = moncf->add_var("ORGN", ncFloat, mcyearD, mcmonD);
	avlnCMV = moncf->add_var("AVLN", ncFloat, mcyearD, mcmonD);

	nimmobCMV = moncf->add_var("NIMMOB", ncFloat, mcyearD, mcmonD);
	netnminCMV = moncf->add_var("NETNMIN", ncFloat, mcyearD, mcmonD);
	reacsumCMV = moncf->add_var("REACSUM", ncFloat, mcyearD, mcmonD);
	noncsumCMV = moncf->add_var("NONCSUM", ncFloat, mcyearD, mcmonD);

	shlwcsumCMV = moncf->add_var("SHLWCSUM", ncFloat, mcyearD, mcmonD);
	deepcsumCMV = moncf->add_var("DEEPCSUM", ncFloat, mcyearD, mcmonD);
	minecsumCMV = moncf->add_var("MINECSUM", ncFloat, mcyearD, mcmonD);

	nlostCMV = moncf->add_var("NLOST", ncFloat, mcyearD, mcmonD);
	ninputCMV = moncf->add_var("NINPUT", ncFloat, mcyearD, mcmonD);

	rrhCMV = moncf->add_var("RRH", ncFloat, mcyearD, mcmonD, mclayerD);
	nrhCMV = moncf->add_var("NRH", ncFloat, mcyearD, mcmonD, mclayerD);

	rhmoistCMV = moncf->add_var("RHMOIST", ncFloat, mcyearD, mcmonD, mclayerD);
	rhq10CMV = moncf->add_var("RHQ10", ncFloat, mcyearD, mcmonD, mclayerD);
	ksoilCMV = moncf->add_var("KSOIL", ncFloat, mcyearD, mcmonD, mclayerD);
	kdlCMV = moncf->add_var("KDL", ncFloat, mcyearD, mcmonD, mclayerD);
	kdrCMV = moncf->add_var("KDR", ncFloat, mcyearD, mcmonD, mclayerD);
	kdnCMV = moncf->add_var("KDN", ncFloat, mcyearD, mcmonD, mclayerD);

	kdlCMV_m = moncf->add_var("KDL_M", ncFloat, mcyearD, mcmonD, mclayerD);
	kdrCMV_m = moncf->add_var("KDR_M", ncFloat, mcyearD, mcmonD, mclayerD);
	kdnCMV_m = moncf->add_var("KDN_M", ncFloat, mcyearD, mcmonD, mclayerD);

	sninflCMV = moncf->add_var("SNINFL", ncFloat, mcyearD, mcmonD);

	sevapCMV = moncf->add_var("SEVAP", ncFloat, mcyearD, mcmonD);
	ssublCMV = moncf->add_var("SSUBL", ncFloat, mcyearD, mcmonD);

	mossdzCMV = moncf->add_var("MOSSDZ", ncFloat, mcyearD, mcmonD);
	shlwdzCMV = moncf->add_var("SHLWDZ", ncFloat, mcyearD, mcmonD);
	deepdzCMV = moncf->add_var("DEEPDZ", ncFloat, mcyearD, mcmonD);
	watertabCMV = moncf->add_var("WATERTAB", ncFloat, mcyearD, mcmonD);
	ch4fluxCMV = moncf->add_var("CH4FLUX", ncFloat, mcyearD, mcmonD);
	hco2fluxCMV = moncf->add_var("HCO2FLUX", ncFloat, mcyearD, mcmonD);
	aco2fluxCMV = moncf->add_var("ACO2FLUX", ncFloat, mcyearD, mcmonD);
	dfratioCMV = moncf->add_var("DFRATIO", ncFloat, mcyearD, mcmonD);
	co2ch4CMV = moncf->add_var("CO2CH4", ncFloat, mcyearD, mcmonD);
	oxidCMV=moncf->add_var("OXID", ncFloat, mcyearD, mcmonD);
}
;

void SnowSoilOutputer::outputYearCohortVars(const int & yrcnt) {

	tsaveCYV->put_rec(&sslod->yrtsave, yrcnt);
	liqsumCYV->put_rec(&sslod->yrliqsum, yrcnt);
	icesumCYV->put_rec(&sslod->yricesum, yrcnt);
	reacsumCYV->put_rec(&sslod->yrreacsum, yrcnt);
	noncsumCYV->put_rec(&sslod->yrnoncsum, yrcnt);

	shlwcsumCYV->put_rec(&sslod->yrshlwcsum, yrcnt);
	deepcsumCYV->put_rec(&sslod->yrdeepcsum, yrcnt);
	minecsumCYV->put_rec(&sslod->yrminecsum, yrcnt);

	orgnCYV->put_rec(&sslod->yrorgn, yrcnt);
	avlnCYV->put_rec(&sslod->yravln, yrcnt);

	nlostCYV->put_rec(&sslod->yrnlost, yrcnt);
	ninputCYV->put_rec(&sslod->yrninput, yrcnt);

	tmin10CYV->put_rec(&sslod->yrtmin10, yrcnt);
	tshlwCYV->put_rec(&sslod->yrtshlw, yrcnt);
	tdeepCYV->put_rec(&sslod->yrtdeep, yrcnt);
	tmineCYV->put_rec(&sslod->yrtmine, yrcnt);

	vwcmin10CYV->put_rec(&sslod->yrvwcmin10, yrcnt);
	vwcshlwCYV->put_rec(&sslod->yrvwcshlw, yrcnt);
	vwcdeepCYV->put_rec(&sslod->yrvwcdeep, yrcnt);
	vwcmineCYV->put_rec(&sslod->yrvwcmine, yrcnt);

	sevapCYV->put_rec(&sslod->yrsevap, yrcnt);
	qdrainCYV->put_rec(&sslod->yrqdrain, yrcnt);
	qoverCYV->put_rec(&sslod->yrqover, yrcnt);
	ssublCYV->put_rec(&sslod->yrssubl, yrcnt);
	rrhsumCYV->put_rec(&sslod->yrrrhsum, yrcnt);
	nrhsumCYV->put_rec(&sslod->yrnrhsum, yrcnt);
	netnminCYV->put_rec(&sslod->yrnetnmin, yrcnt);
	snuptakeCYV->put_rec(&sslod->yrsnuptake, yrcnt);

	watertabCYV->put_rec(&sslod->yrwatertab, yrcnt);
	ch4fluxCYV->put_rec(&sslod->yrch4flux, yrcnt);
	hco2fluxCYV->put_rec(&sslod->yrhco2flux, yrcnt);
	aco2fluxCYV->put_rec(&sslod->yraco2flux, yrcnt);
	dfratioCYV->put_rec(&sslod->yrdfratio, yrcnt);
	co2ch4CYV->put_rec(&sslod->yrco2ch4, yrcnt);
	oxidCYV->put_rec(&sslod->yroxid, yrcnt);

	mossdzCYV->put_rec(&sslod->yrmossdz, yrcnt);
	shlwdzCYV->put_rec(&sslod->yrshlwdz, yrcnt);
	deepdzCYV->put_rec(&sslod->yrdeepdz, yrcnt);

	mossnumCYV->put_rec(&sslod->yrmossnum, yrcnt);
	shlwnumCYV->put_rec(&sslod->yrshlwnum, yrcnt);
	deepnumCYV->put_rec(&sslod->yrdeepnum, yrcnt);

	burnthickCYV->put_rec(&sslod->yrburnthick, yrcnt);
	burnsoilcCYV->put_rec(&sslod->yrburnsoilc, yrcnt);
	burnsoilnCYV->put_rec(&sslod->yrburnsoiln, yrcnt);
	orgnreturnCYV->put_rec(&sslod->yrorgnreturn, yrcnt);

	wdebrisCYV->put_rec(&sslod->yrwdebris, yrcnt);
	wdrhCYV->put_rec(&sslod->yrwdrh, yrcnt);

	permCYV->put_rec(&sslod->yrperm, yrcnt);
	aldCYV->put_rec(&sslod->yrald, yrcnt);

}
;

void SnowSoilOutputer::defineYearCohortVars() {
	yrcf = siteoutputer->yrChtFile;

	ycyearD = yrcf->get_dim("year");
	yclayerD = yrcf->get_dim("layer");

	errorCYV = yrcf->add_var("ERRORID", ncInt);

	tsaveCYV = yrcf->add_var("TSAVE", ncFloat, ycyearD);
	liqsumCYV = yrcf->add_var("LIQSUM", ncFloat, ycyearD);
	icesumCYV = yrcf->add_var("ICESUM", ncFloat, ycyearD);
	reacsumCYV = yrcf->add_var("REACSUM", ncFloat, ycyearD);
	noncsumCYV = yrcf->add_var("NONCSUM", ncFloat, ycyearD);

	shlwcsumCYV = yrcf->add_var("SHLWCSUM", ncFloat, ycyearD);
	deepcsumCYV = yrcf->add_var("DEEPCSUM", ncFloat, ycyearD);
	minecsumCYV = yrcf->add_var("MINECSUM", ncFloat, ycyearD);

	orgnCYV = yrcf->add_var("ORGN", ncFloat, ycyearD);
	avlnCYV = yrcf->add_var("AVLN", ncFloat, ycyearD);

	nlostCYV = yrcf->add_var("NLOST", ncFloat, ycyearD);
	ninputCYV = yrcf->add_var("NINPUT", ncFloat, ycyearD);

	tmin10CYV = yrcf->add_var("TMIN10", ncFloat, ycyearD);
	tshlwCYV = yrcf->add_var("TSHLW", ncFloat, ycyearD);
	tdeepCYV = yrcf->add_var("TDEEP", ncFloat, ycyearD);
	tmineCYV = yrcf->add_var("TMINE", ncFloat, ycyearD);

	vwcmin10CYV = yrcf->add_var("VWCMIN10", ncFloat, ycyearD);
	vwcshlwCYV = yrcf->add_var("VWCSHLW", ncFloat, ycyearD);
	vwcdeepCYV = yrcf->add_var("VWCDEEP", ncFloat, ycyearD);
	vwcmineCYV = yrcf->add_var("VWCMINE", ncFloat, ycyearD);

	sevapCYV = yrcf->add_var("SEVAP", ncFloat, ycyearD);
	qdrainCYV = yrcf->add_var("QDRAIN", ncFloat, ycyearD);
	qoverCYV = yrcf->add_var("QOVER", ncFloat, ycyearD);
	ssublCYV = yrcf->add_var("SSUBL", ncFloat, ycyearD);
	rrhsumCYV = yrcf->add_var("RRHSUM", ncFloat, ycyearD);
	nrhsumCYV = yrcf->add_var("NRHSUM", ncFloat, ycyearD);
	netnminCYV = yrcf->add_var("NETNMIN", ncFloat, ycyearD);
	snuptakeCYV = yrcf->add_var("SNUPTAKE", ncFloat, ycyearD);

	permCYV = yrcf->add_var("PERMAFROST", ncFloat, ycyearD);
	aldCYV = yrcf->add_var("ALD", ncFloat, ycyearD);
	watertabCYV = yrcf->add_var("WATERTAB", ncFloat, ycyearD);
	ch4fluxCYV = yrcf->add_var("CH4FLUX", ncFloat, ycyearD);
	hco2fluxCYV = yrcf->add_var("HCO2FLUX", ncFloat, ycyearD);
	aco2fluxCYV = yrcf->add_var("ACO2FLUX", ncFloat, ycyearD);
	dfratioCYV = yrcf->add_var("DFRATIO", ncFloat, ycyearD);
	co2ch4CYV = yrcf->add_var("CO2CH4", ncFloat, ycyearD);
	oxidCYV = yrcf->add_var("OXID", ncFloat, ycyearD);

	mossdzCYV = yrcf->add_var("MOSSDZ", ncFloat, ycyearD);
	shlwdzCYV = yrcf->add_var("SHLWDZ", ncFloat, ycyearD);
	deepdzCYV = yrcf->add_var("DEEPDZ", ncFloat, ycyearD);
	mossnumCYV = yrcf->add_var("MOSSNUM", ncFloat, ycyearD);
	shlwnumCYV = yrcf->add_var("SHLWNUM", ncFloat, ycyearD);
	deepnumCYV = yrcf->add_var("DEEPNUM", ncFloat, ycyearD);

	burnthickCYV = yrcf->add_var("BURNTHICK", ncFloat, ycyearD);
	burnsoilcCYV = yrcf->add_var("BURNSOILC", ncFloat, ycyearD);
	burnsoilnCYV = yrcf->add_var("BURNSOILN", ncFloat, ycyearD);
	orgnreturnCYV = yrcf->add_var("ORGNRETURN", ncFloat, ycyearD);

	wdebrisCYV = yrcf->add_var("WDEBRIS", ncFloat, ycyearD);
	wdrhCYV = yrcf->add_var("WDRH", ncFloat, ycyearD);

}
;

void SnowSoilOutputer::setOutputer(SiteOutputer * outputerp) {
	siteoutputer = outputerp;

#ifdef ODAY
	defineDayCohortVars();
#endif

	if (OMONTH) {
		defineMonthCohortVars();
	}

	if (OYEAR) {
		defineYearCohortVars();
	}

}
;

void SnowSoilOutputer::setOutdata(SnowSoilOutData* outdata) {
	sslod = outdata;
}
;
