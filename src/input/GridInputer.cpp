#include "GridInputer.h"

GridInputer::GridInputer(){
	
};

GridInputer::~GridInputer(){

}

void GridInputer::init(){
  if(md!=NULL){
  	initLatlon(md->grdinputdir);
  	initFire(md->grdinputdir);
  	initSoil(md->grdinputdir);
  	initClimate(md->grdinputdir);
  	  	  	
  }else{
  	throw Exception("GridInputer::init - ModelData is NULL", I_VAR_NULL);
  }
	
}

void GridInputer::initLatlon(string& dir){
	//netcdf error
	NcError err(NcError::silent_nonfatal);

	grdfilename = dir +"latlon.nc";
	NcFile gridFile(grdfilename.c_str(), NcFile::ReadOnly);
 	if(!gridFile.is_valid()){
 		string msg = grdfilename+" is not valid";
 		char* msgc = const_cast< char* > ( msg.c_str());
 		throw Exception( msgc, I_NCFILE_NOT_EXIST);
 	}

 	NcDim* grdD = gridFile.get_dim("GRDID");
 	if(!grdD->is_valid()){
 		throw Exception("GRDID Dimension is not Valid in latlon data", I_NCDIM_NOT_EXIST);
 	}

}

void GridInputer::initFire(string & dir){
	//netcdf error
	NcError err(NcError::silent_nonfatal);

	firefilename = dir +"fire.nc";
	NcFile fireFile(firefilename.c_str(), NcFile::ReadOnly);
 	if(!fireFile.is_valid()){
 		string msg = firefilename+" is not valid";
 		char* msgc = const_cast< char* > ( msg.c_str());
 		throw Exception(msgc, I_NCFILE_NOT_EXIST);
 	}

}

void GridInputer::initSoil(string& dir){
	//netcdf error
	NcError err(NcError::silent_nonfatal);

	soilfilename = dir +"soil.nc";
	NcFile soilFile(soilfilename.c_str(), NcFile::ReadOnly);
 	if(!soilFile.is_valid()){
 		string msg = soilfilename+" is not valid";
 		char* msgc = const_cast< char* > ( msg.c_str());
 		throw Exception(msgc, I_NCFILE_NOT_EXIST);
 	}
 	
 	NcDim* grdD = soilFile.get_dim("GRDID");
 	if(!grdD->is_valid()){
 		throw Exception("GRDID Dimension is not Valid in Soil data", I_NCDIM_NOT_EXIST);
 	}

}


void GridInputer::initClimate(string& dir){
	//netcdf error
	NcError err(NcError::silent_nonfatal);

	clmfilename = dir +"climate.nc";
	NcFile climateFile(clmfilename.c_str(), NcFile::ReadOnly);
 	if(!climateFile.is_valid()){
 		string msg = clmfilename+" is not valid";
 		char* msgc = const_cast< char* > ( msg.c_str());
 		throw Exception( msgc, I_NCFILE_NOT_EXIST);
 	}
 	
 	NcDim* grdD = climateFile.get_dim("GRDID");
 	if(!grdD->is_valid()){
 		throw Exception("GRDID Dimension is not Valid in Climate data", I_NCDIM_NOT_EXIST);
 	}
 		
 	NcDim* yrD = climateFile.get_dim("YEAR");
 	if(!yrD->is_valid()){
 		throw Exception("YEAR Dimension is not Valid in Climate data", I_NCDIM_NOT_EXIST);
 	}

 	NcDim* monD = climateFile.get_dim("MONTH");
 	if(!monD->is_valid()){
 		throw Exception("MONTH Dimension is not Valid in Climate data",  I_NCDIM_NOT_EXIST);
 	}

}

//YUAN: recid - the order (from ZERO) in the .nc file, gid - the grid id
int GridInputer::getGridRecID(const int &gid){
	//netcdf error
	NcError err(NcError::silent_nonfatal);

	NcFile gridFile(grdfilename.c_str(), NcFile::ReadOnly);

	NcVar* grdidV = gridFile.get_var("GRDID");
	if(grdidV==NULL){
		throw Exception("Cannot get GRDID in GridInputer", I_NCVAR_NOT_EXIST);
	}

	int id=-1;
	for (int i=0; i<(int)grdidV->num_vals(); i++){
		grdidV->set_cur(i);
		grdidV->get(&id,1);
		if(id==gid) return i;
	}
	return -1;
}

// read grid-level data (netcdf format) into GridData class
void GridInputer::getGridData(GridData* gd, const int &recid){

  	gd->lat = getLAT(recid);
  	gd->lon = getLON(recid);

  	gd->topsoil = getTOPSOIL(recid);
  	gd->botsoil = getBOTSOIL(recid);

  	getClimate(gd->ta, gd->prec, gd->nirr, gd->vap, recid);

  	gd->fri = getFRI(recid);
 	getFireSize(gd->fireyear, gd->fireseason, gd->firesize, recid);

};

/////////////////////////////////////////////////////////////////

float GridInputer::getLAT(const int & recid ){
	float lat=-1;

	NcError err(NcError::silent_nonfatal);

	NcFile gridFile(grdfilename.c_str(), NcFile::ReadOnly);
 	NcVar* latV = gridFile.get_var("LAT");
 	if(latV==NULL){
 	   throw Exception("Cannot get LAT in GridInputer ", I_NCVAR_NOT_EXIST);
 	   return -1;
 	}

//	float lat= (latV->get_rec(recid))->as_float(0);   //Yuan: memory-leaky???
 	latV->set_cur(recid);
	latV->get(&lat, 1);
	return lat;
} 

float GridInputer::getLON(const int & recid ){
	float lon=-1;

	NcError err(NcError::silent_nonfatal);

	NcFile gridFile(grdfilename.c_str(), NcFile::ReadOnly);
 	NcVar* lonV = gridFile.get_var("LON");
 	if(lonV==NULL){
 	   throw Exception("Cannot get LON in GridInputer ", I_NCVAR_NOT_EXIST);
 	   return -1;
 	}
 	lonV->set_cur(recid);
	lonV->get(&lon, 1);
//	float lon= (lonV->get_rec(recid))->as_float(0);
	return lon;
} 

int GridInputer::getTOPSOIL(const int & recid ){
	int topsoil = -1;
	NcError err(NcError::silent_nonfatal);

	NcFile soilFile(soilfilename.c_str(), NcFile::ReadOnly);
 	NcVar* topsoilV = soilFile.get_var("TOPSOIL");
 	if(topsoilV==NULL){
 	   throw Exception("Cannot get TOPSOIL in initSoil ", I_NCVAR_NOT_EXIST);
 	   return -1;
 	}

// 	int topsoil=  (topsoilV->get_rec(recid))->as_int(0);
 	topsoilV->set_cur(recid);
	topsoilV->get(&topsoil, 1);
	return topsoil;
} 

int GridInputer::getBOTSOIL(const int & recid ){
	int botsoil = -1;
	NcError err(NcError::silent_nonfatal);

	NcFile soilFile(soilfilename.c_str(), NcFile::ReadOnly);
 	NcVar* botsoilV = soilFile.get_var("BOTSOIL");
 	if(botsoilV==NULL){
 	   throw Exception("Cannot get BOTSOIL in initSoil ", I_NCVAR_NOT_EXIST);
 	   return -1;
  	}

// 	int botsoil= (int)(botsoilV->get_rec(recid))->as_int(0);
 	botsoilV->set_cur(recid);
	botsoilV->get(&botsoil, 1);
	return botsoil;
} 

void GridInputer::getClimate(float ta[][12], float prec[][12], float nirr[][12], float vap[][12] , const int & recid ){
	int numyr = MAX_ATM_DRV_YR;
	int nummon =12;

	//read the data from netcdf file
	NcError err(NcError::silent_nonfatal);

	NcFile climateFile(clmfilename.c_str(), NcFile::ReadOnly);
 	NcVar* taV = climateFile.get_var("TAIR");
 	if(taV==NULL){
 	    throw Exception("Cannot get TAIR in GridInputer \n",I_NCVAR_NOT_EXIST);
 	}

 	NcVar* nirrV = climateFile.get_var("NIRR");
 	if(nirrV==NULL){
 	    throw Exception("Cannot get NIRR in GridInputer \n",I_NCVAR_NOT_EXIST);
 	}

 	NcVar* precV = climateFile.get_var("PREC");
 	if(precV==NULL){
 	   throw Exception("Cannot get PREC in GridInputer \n", I_NCVAR_NOT_EXIST);
 	}

 	NcVar* vapV = climateFile.get_var("VAPO");
 	if(vapV==NULL){
 	    throw Exception("Cannot get VAPO in GridInputer ", I_NCVAR_NOT_EXIST);
 	}

 	//get the data for recid
	taV->set_cur(recid);
	NcBool nb1 = taV->get(&ta[0][0],1, numyr, nummon);
	if(!nb1){
	 	throw Exception("problem in reading TA in  GridInputer::getClimate",  I_NCVAR_GET_ERROR);	
	}
	
	precV->set_cur(recid);
	NcBool nb2 = precV->get(&prec[0][0],1, numyr, nummon);
	if(!nb2){
		throw Exception("problem in reading PREC in  GridInputer::getClimate ",  I_NCVAR_GET_ERROR);	
	}
	
	nirrV->set_cur(recid);
	NcBool nb3 = nirrV->get(&nirr[0][0], 1,numyr, nummon);
	if(!nb3){
		throw Exception("problem in reading NIRR in  GridInputer::getClimate",  I_NCVAR_GET_ERROR);	
	}
	
	vapV->set_cur(recid);
	NcBool nb4 = vapV->get(&vap[0][0],1, numyr, nummon);
	if(!nb4){
	 //cout <<"problem in reading VAPO in Inputer::getDriving Vars \n";
	 	throw Exception("problem in reading VAPO in  GridInputer::getClimate",  I_NCVAR_GET_ERROR);	
	}
	
} 

int GridInputer::getFRI(const int & recid ){
	int fri = -1;
	NcError err(NcError::silent_nonfatal);

	NcFile fireFile(firefilename.c_str(), NcFile::ReadOnly);

	NcVar* friV = fireFile.get_var("FRI");
 	if(friV==NULL){
 	   throw Exception("Cannot get FRI in FRI data file", I_NCVAR_NOT_EXIST);
 	}

// 	float fri= (friV->get_rec(recid))->as_float(0);
 	friV->set_cur(recid);
	friV->get(&fri, 1);

	return fri;
}

void GridInputer::getFireSize(int fyear[], int fseason[], int fsize[], const int & recid){
	int numyr = MAX_FSIZE_DRV_YR;

	//netcdf error
	NcError err(NcError::silent_nonfatal);

	NcFile fireFile(firefilename.c_str(), NcFile::ReadOnly);

 	NcVar* fsyrV = fireFile.get_var("YEAR");
 	NcVar* fsizeV = fireFile.get_var("SIZE");
 	NcVar* fseasonV = fireFile.get_var("SEASON");
 	if(fsyrV==NULL || fsizeV==NULL || fseasonV==NULL){
 	   throw Exception("Cannot get Fire size data in GridInputer::getFireSize", I_NCVAR_NOT_EXIST);
 	}

 	//get the data for recid
	fsyrV->set_cur((long)0);
	NcBool nb1 = fsyrV->get(&fyear[0],numyr);
	if(!nb1){
	 	throw Exception("problem in reading fire year in GridInputer::getFireSize",  I_NCVAR_GET_ERROR);
	}

	fsizeV->set_cur(recid);
	NcBool nb2 = fsizeV->get(&fsize[0],1, numyr);
	if(!nb2){
	 	throw Exception("problem in reading fire size in  GridInputer::getFireSize",  I_NCVAR_GET_ERROR);
	}

	fseasonV->set_cur(recid);
	NcBool nb3 = fseasonV->get(&fseason[0],1, numyr);
	if(!nb3){
	 	throw Exception("problem in reading fire season in  GridInputer::getFireSize",  I_NCVAR_GET_ERROR);
	}

};


void GridInputer::setModelData(ModelData* mdp){
	md = mdp;
};




