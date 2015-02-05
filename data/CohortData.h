#ifndef COHORTDATA_H_
#define COHORTDATA_H_

#include "../inc/timeconst.h"

class CohortData{
  	public:
  		CohortData();
  		~CohortData();
  
  		int cruid;
  		int trchtid; // transient cohortid
  		int eqchtid; //equilibrium cohort id
  		int spchtid; //spinup cohort id
  		int scchtid; //scenario cohort id 
  		int reschtid;  //cohort id for restart

  		int drgtype;
  		int vegtype;
  	
		int trfireyear[MAX_TR_FIR_OCR_NUM];
		int trseason[MAX_TR_FIR_OCR_NUM];
		double trvegseverity[MAX_TR_FIR_OCR_NUM];
		double trsoiseverity[MAX_TR_FIR_OCR_NUM];

		int spfireyear[MAX_SP_FIR_OCR_NUM];
		int spseason[MAX_SP_FIR_OCR_NUM];

		double spvegseverity[MAX_SP_FIR_OCR_NUM];
		double spsoiseverity[MAX_SP_FIR_OCR_NUM];
	
};

#endif /*COHORTDATA_H_*/
