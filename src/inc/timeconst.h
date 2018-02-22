#ifndef TIMECONST_H_
#define TIMECONST_H_

#define PROJECTION
//#undef PROJECTION

	const int DYINY =365;  // DINY does not work
	const int MINY =12;	

#ifdef PROJECTION
	const int MAX_FSIZE_DRV_YR = 199; //109 // maximum number of years of fire size history at regional-scale (YUAN);
	const int MAX_CO2_DRV_YR = 199;  //109 // maximum number of years of CO2 at regional-scale (YUAN);
	const int MAX_ATM_DRV_YR = 199;//109 // maximum number of years of atmopsheric driving data
//    const int END_TR_YR = 2099;//2009
    const int END_TR_YR = 2100;//2009
#endif

#ifndef PROJECTION
//    const int END_TR_YR = 2011;//2009
    const int END_TR_YR = 2014;//2009
	const int MAX_FSIZE_DRV_YR = 111; //109 // maximum number of years of fire size history at regional-scale (YUAN);
	const int MAX_CO2_DRV_YR = 111;  //109 // maximum number of years of CO2 at regional-scale (YUAN);
	const int MAX_ATM_DRV_YR = 111;//109 // maximum number of years of atmopsheric driving data
#endif

	//YUAN: moving the constants in Timer here

//   const int MAX_EQ_YR = 800;  // 20000 maximum number of years for equilibrium run
//   const int MAX_SP_YR = 900;    // 900 maximum number of years of spinup run;
//
//   const int BEG_TR_YR = 1901;
//   const int BEG_SC_YR = 2010;
//   const int END_SC_YR = 2099;


    const int MAX_EQ_YR = 800;  // 20000 maximum number of years for equilibrium run
	const int MAX_SP_YR = 900;    // 900 maximum number of years of spinup run;

    const int BEG_TR_YR = 1901;
    const int BEG_SC_YR = 2015;
    const int END_SC_YR = 2100;

    const int MAX_ATM_NOM_YR = 30;  // maximum number of years of NORMAL atmopsheric driving data (YUAN: used for spin-up)

    //YUAN: the following is upon the above and modified from the original definition
    const int END_SP_YR = BEG_TR_YR - 1;
	const int BEG_SP_YR = END_SP_YR - MAX_SP_YR+1;   //NOTE: not -1, which reserved for non fire year

    const int MAX_TR_YR = END_TR_YR-BEG_TR_YR+1; // maximum number of years of transient run;
	const int MAX_SC_YR = END_SC_YR-BEG_SC_YR+1; // maximum number of years of scenario run;
	
	const int MAX_TR_FIR_OCR_NUM = 8; // maximum number of fire occurrence in transient run
	const int MAX_SP_FIR_OCR_NUM = 15; // maximum number of fire occurrence in spin-up run
	const int MAX_FIR_OCR_NUM    = MAX_SP_FIR_OCR_NUM+MAX_TR_FIR_OCR_NUM; // maximum number of fire occurrence in model run

#endif /*TIMECONST_H_*/
