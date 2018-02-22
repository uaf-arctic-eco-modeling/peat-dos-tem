#ifndef MODELDATA_H_
	#define MODELDATA_H_
	#include <string>
	#include <iostream>
	#include <fstream>
	#include <sstream>

#include <cstdlib>
#include <cstring>
#include <cstdio>


	using namespace std;
	
	class ModelData{
 		public:
 
    		ModelData();
    		~ModelData();

    		bool runeq;
    		bool runsp;
    		bool runtr; //run transient
    		bool runsc; //run scenario
 
    		bool changeco2;
    		bool changeclimate;
    
    		bool useseverity; //pass to cohortinputer and firedata
  
    		int myid;
    		int numprocs;
    		int initmode;
    
    		bool consoledebug;
            
  			string outputdir, casename, cctypes;
  			string reginputdir, grdinputdir;
  			string runchtfile;       //must be *.nc format file
  
  			string initmodes, runstages;
  
  			string initialfile;      //either the restart.nc, or sitein.nc file, upon initmodes
  			string eqchtinputdir;
  			string spchtinputdir;
  			string trchtinputdir;
  
  			string calibrationdir;
 
			void checking4run();

		//this is for java interface
  			char* joutputdir;
  			char* jcasename;
  			char* jcctypes;
  			char* jreginputdir;
  			char* jgrdinputdir;
  			char* jrunchtfile;       
  			char* jinitmodes;
  			char* jrunstages; 
  			char* jinitialfile;
  			char* jeqchtinputdir;
  			char* jspchtinputdir;
  			char* jtrchtinputdir;
  			char* jcalibrationdir;

			void stringtochar();

 		private:
	
	};

#endif /*MODELDATA_H_*/
