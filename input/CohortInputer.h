#ifndef COHORTINPUTER_H_
#define COHORTINPUTER_H_

/*! this class is used to readin input of parameters, forcings for TEM
 * \file
 */

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;

#include "netcdfcpp.h"

//local header
#include "../run/ModelData.h"

//from TEMcore.dll
#include "../util/Exception.h"
#include "../inc/layerconst.h"
#include "../inc/timeconst.h"
#include "../inc/ErrorCode.h"

class CohortInputer{
	public:
		CohortInputer();
		~CohortInputer();

		void init( );

		int  getEqRecID(const int &chtid);
		void getCRUID(  int & cruid,  const int & cid);
		void getVegetation(  int & vtype,  const int & eqcid);
		void getDrainage(  int & dtype,  const int & eqcid);
	
		int  getSpRecID(const int &chtid);
		void getEqchtid5SpFile(int & eqchtid,  const int &recid);
  
		int  getTrRecID(const int &chtid);
		void getSpchtid5TrFile( int & spchtid,  const int &recid);

		void getSpinupFireOccur(int season[MAX_SP_FIR_OCR_NUM], const int &spcid);
		void getSpinupFireSeason(int season[MAX_SP_FIR_OCR_NUM], const int &spcid);
		void getSpinupVegSeverity(double vegseverity[MAX_SP_FIR_OCR_NUM], const int &spcid);
		void getSpinupSoiSeverity(double soiseverity[MAX_SP_FIR_OCR_NUM], const int &spcid);

		void getTransientFireOccur(int season[MAX_TR_FIR_OCR_NUM], const int &trcid);
		void getTransientFireSeason(int season[MAX_TR_FIR_OCR_NUM], const int &trcid);
		void getTransientVegSeverity(double vegseverity[MAX_TR_FIR_OCR_NUM], const int &trcid);
		void getTransientSoiSeverity(double soiseverity[MAX_TR_FIR_OCR_NUM], const int &trcid);

		void setModelData(ModelData* mdp);

	private:
	 
		 int useseverity;
		 string cruidfname;
		 string vegidfname;
		 string drgidfname;
		 string spidfname;
		 string spffname;
		 string tridfname;
		 string trffname;

		 void initCRUIDFile(string& dir);
		 void initVegetation(string& dir);
		 void initDrainage(string& dir);

		 void initSpChtidFile(string& dir);
		 void initTrChtidFile(string& dir);
		 void initSpinupFire(string& dir);
		 void initTransientFire(string& dir);

		 ModelData* md;
	
};


#endif /*COHORTINPUTER_H_*/
