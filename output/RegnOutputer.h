#ifndef REGNOUTPUTER_H_
#define REGNOUTPUTER_H_
/*! this class is used to output modeling results in the netcdf format
 * when running TEM at regional-mode (i.e., multiple sites)
 * 
 */

#include "netcdfcpp.h"
#include <iostream>
#include <string>
using namespace std;

#include "../run/RegnOutData.h"

class RegnOutputer{
	
	public:
		RegnOutputer();
		~RegnOutputer();
	
 		void init(string& outputdir, const int & myid, string& stage, int MAX_DRV_YR);
  
 		void outputYearCohortVars(const int & yrind, const int & chtid);
  
  		void missingValues(const int & MAX_YR, const int & chtid);
  		void setOutData(RegnOutData *regnodp);
  		  
    	NcFile* rFile;

		NcDim * chtD;
		NcDim * yearD;
 
    	NcVar* chtidCYV;
   		NcVar* statusCYV;
   		NcVar* ysfCYV;
   		NcVar* rhCYV;
   		NcVar* rmCYV;
   		NcVar* rgCYV;
   		NcVar* gppCYV;
   		NcVar* nppCYV;
   		NcVar* burnsoicCYV;
   		NcVar* burnvegcCYV;
   
   		NcVar* vegcCYV;
   		NcVar* mincCYV;
   		NcVar* shlwcCYV;
   		NcVar* deepcCYV;
   
   		NcVar* orgnCYV;
   		NcVar* avlnCYV;
   		NcVar* vegnCYV;
   
   		NcVar* eetCYV;
   		NcVar* petCYV;
   		NcVar* aldCYV;
   		NcVar* wtdCYV;
   		NcVar* ch4fluxCYV;
   		NcVar* hco2fluxCYV;
   		NcVar* aco2fluxCYV;
   		NcVar* dfratioCYV;
   		NcVar* co2ch4CYV;
   		NcVar* oxidCYV;
   		NcVar* permCYV;

   		NcVar* tmin10CYV;
   		NcVar* tshlwCYV;
   		NcVar* tdeepCYV;
   		NcVar* tmineCYV;
   
    	NcVar* trock34CYV;
      	NcVar* unfrzcolumnCYV;

      	NcVar* vwcmin10CYV;
   		NcVar* vwcshlwCYV;
   		NcVar* vwcdeepCYV;
   		NcVar* vwcmineCYV;

      	NcVar* laiCYV;      	
       	NcVar* netnminCYV;
        NcVar* nuptakeCYV;
        NcVar* ltrfalcCYV;
        NcVar* ltrfalnCYV;
    
   		NcVar* growstartCYV;
   		NcVar* growendCYV;
   
   		NcVar* mossdzCYV;
   		NcVar* shlwdzCYV;
   		NcVar* deepdzCYV;
   		NcVar* burnthickCYV;

   		NcVar* qdrainCYV;
      	NcVar* qrunoffCYV;
      	NcVar* ninputCYV;
      	NcVar* nlostCYV;

   		RegnOutData *regnod;
   		
};

#endif /*REGNOUTPUTER_H_*/
