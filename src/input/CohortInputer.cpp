#include "CohortInputer.h"

CohortInputer::CohortInputer(){
	useseverity =0;
};

CohortInputer::~CohortInputer(){

}

void CohortInputer::init(){
	useseverity = md->useseverity;
  	if(md!=NULL){
  		if(md->runsp){
  			initSpChtidFile(md->spchtinputdir);
    		initSpinupFire(md->spchtinputdir);
	  	}
  
  		if(md->runtr){
  			initSpChtidFile(md->spchtinputdir);
    		initTransientFire(md->trchtinputdir);
    		initTrChtidFile(md->trchtinputdir);
  		}
  
  		initCRUIDFile(md->eqchtinputdir);
  		initVegetation(md->eqchtinputdir);
  		initDrainage(md->eqchtinputdir);
  
  	}else{
  		throw Exception("inputer in CohortInputer::init is null", I_VAR_NULL);
  	}
	
}

void CohortInputer::initCRUIDFile(string & dir){

	cruidfname = dir +"cruid.nc";

	NcError err(NcError::silent_nonfatal);
	NcFile cruidFile(cruidfname.c_str(), NcFile::ReadOnly);
 	if(!cruidFile.is_valid()){
 		string msg = cruidfname+" is not valid";
 		char* msgc = const_cast< char* > ( msg.c_str());
 		throw Exception( msgc, I_NCFILE_NOT_EXIST);
 	}

 	NcDim* eqchtD = cruidFile.get_dim("EQCHTID");
  	if(!eqchtD->is_valid()){
  		throw Exception("CHTD Dimension is not Valid in CRUidFile", I_NCDIM_NOT_EXIST);
 	}

}
void CohortInputer::initVegetation(string & dir){
	vegidfname = dir +"vegetation.nc";

	NcError err(NcError::silent_nonfatal);
	NcFile vegetationFile(vegidfname.c_str(), NcFile::ReadOnly);
 	if(!vegetationFile.is_valid()){
 		string msg = vegidfname+" is not valid";
 		char* msgc = const_cast< char* > ( msg.c_str());
 		throw Exception( msgc, I_NCFILE_NOT_EXIST);
 	}
 	
 	NcDim* chtD = vegetationFile.get_dim("EQCHTID");
 	if(!chtD->is_valid()){
 		throw Exception("CHTD Dimension is not Valid in Vegetation file", I_NCDIM_NOT_EXIST);
 	}
 	
}

void CohortInputer::initDrainage(string& dir){
	drgidfname = dir +"drainage.nc";

	NcError err(NcError::silent_nonfatal);
	NcFile drainageFile(drgidfname.c_str(), NcFile::ReadOnly);
 	if(!drainageFile.is_valid()){
 		string msg = drgidfname+" is not valid";
 		char* msgc = const_cast< char* > ( msg.c_str());
 		throw Exception( msgc, I_NCFILE_NOT_EXIST);
 	}
 	
 	NcDim* chtD = drainageFile.get_dim("EQCHTID");
 	if(!chtD->is_valid()){
 		throw Exception("CHTD Dimension is not Valid in Drainage file", I_NCDIM_NOT_EXIST);
 	}
 	
}

void CohortInputer::initSpChtidFile(string& dir){
	spidfname = dir +"cohortid.nc";

	NcError err(NcError::silent_nonfatal);
	NcFile spchtidFile(spidfname.c_str(), NcFile::ReadOnly);
 	if(!spchtidFile.is_valid()){
 		string msg = spidfname+" is not valid";
 		char* msgc = const_cast< char* > ( msg.c_str());
 		throw Exception( msgc, I_NCFILE_NOT_EXIST);
 	}
 	
 	NcDim* spchtD = spchtidFile.get_dim("SPCHTID");
 	if(!spchtD->is_valid()){
 		throw Exception("CHTD Dimension is no Valid in SpChtidFile", I_NCDIM_NOT_EXIST);
 	}
 	
}

void CohortInputer::initSpinupFire(string& dir){
	spffname = dir +"fire.nc";

	NcError err(NcError::silent_nonfatal);
	NcFile spfireFile(spffname.c_str(), NcFile::ReadOnly);
 	if(!spfireFile.is_valid()){
 		string msg = spffname+" is not valid";
 		char* msgc = const_cast< char* > ( msg.c_str());
 		throw Exception(msgc, I_NCFILE_NOT_EXIST);
 	}

 	NcDim* chtD = spfireFile.get_dim("SPCHTID");
 	if(!chtD->is_valid()){
 		throw Exception("CHTD Dimension is not Valid in spFIRE", I_NCDIM_NOT_EXIST);
 	}

 	NcDim* numfireD = spfireFile.get_dim("NUMFIRE");
 	if(!numfireD->is_valid()){
 		throw Exception("NUMFIRE Dimension is not Valid in spFIRE", I_NCDIM_NOT_EXIST);
 	}

}

void CohortInputer::initTrChtidFile(string& dir){
	tridfname = dir +"cohortid.nc";

	NcError err(NcError::silent_nonfatal);
	NcFile trchtidFile(tridfname.c_str(), NcFile::ReadOnly);
 	if(!trchtidFile.is_valid()){
 		string msg = tridfname+" is not valid";
 		char* msgc = const_cast< char* > ( msg.c_str());
 		throw Exception( msgc, I_NCFILE_NOT_EXIST);
 	}

 	NcDim* trchtD=trchtidFile.get_dim("TRCHTID");
 	if(!trchtD->is_valid()){
 		throw Exception("CHTD Dimension is not Valid in TrChtidFile", I_NCDIM_NOT_EXIST);
 	}

}

void CohortInputer::initTransientFire(string& dir){
	trffname = dir +"fire.nc";

	NcError err(NcError::silent_nonfatal);
	NcFile trfireFile(trffname.c_str(), NcFile::ReadOnly);
 	if(!trfireFile.is_valid()){
 		string msg = trffname+" is not valid";
 		char* msgc = const_cast< char* > ( msg.c_str());
 		throw Exception(msgc, I_NCFILE_NOT_EXIST);
 	}

 	NcDim* chtD = trfireFile.get_dim("TRCHTID");
 	if(!chtD->is_valid()){
 		throw Exception("CHTD Dimension is no Valid in initFIRE", I_NCDIM_NOT_EXIST);
 	}

 	NcDim* numfireD = trfireFile.get_dim("NUMFIRE");
 	if(!numfireD->is_valid()){
  		throw Exception("NUMFIRE Dimension is no Valid in initFIRE", I_NCDIM_NOT_EXIST);
 	}

}

///////////////////////////////////////////////////////////////////////
//YUAN: recid - the order (from ZERO) in the .nc file, chtid - the cohort id
int CohortInputer::getEqRecID(const int &chtid){
	NcError err(NcError::silent_nonfatal);

	NcFile cruidFile(cruidfname.c_str(), NcFile::ReadOnly);
 	NcVar* eqchtidV = cruidFile.get_var("EQCHTID");
 	if(eqchtidV==NULL){
 	   throw Exception("Cannot get eqchtid  in initcruididFile ", I_NCVAR_NOT_EXIST);
 	}

 	int id = -1;
	for (int i=0; i<(int)eqchtidV->num_vals(); i++){
		eqchtidV->set_cur(i);
		eqchtidV->get(&id, 1);
		if(id==chtid) return i;
	}
	return -1;
}

void CohortInputer::getCRUID(int & cruid,  const int & recid){
	NcError err(NcError::silent_nonfatal);

	NcFile cruidFile(cruidfname.c_str(), NcFile::ReadOnly);
 	NcVar* cruidV = cruidFile.get_var("CRUID");
 	if(cruidV==NULL){
 	   throw Exception("Cannot get cruid  in initcruididFile ", I_NCVAR_NOT_EXIST);
 	}

 	cruidV->set_cur(recid);
	cruidV->get(&cruid, 1);

}

void CohortInputer::getVegetation(int & vtype,  const int &recid){
	NcError err(NcError::silent_nonfatal);

	NcFile vegetationFile(vegidfname.c_str(), NcFile::ReadOnly);
 	NcVar* vegV = vegetationFile.get_var("VEGID");
 	if(vegV==NULL){
  	   throw Exception("Cannot get vegetation  in initFire ", I_NCVAR_NOT_EXIST);
 	}

	vegV->set_cur(recid);
	vegV->get(&vtype, 1);

}

void CohortInputer::getDrainage(int & dtype, const int & recid){
	NcError err(NcError::silent_nonfatal);

	NcFile drainageFile(drgidfname.c_str(), NcFile::ReadOnly);
 	NcVar* drainV = drainageFile.get_var("DRAINID");
 	if(drainV==NULL){
  	   throw Exception("Cannot get drainage  in initDrainage ", I_NCVAR_NOT_EXIST);
 	}

	drainV->set_cur(recid);
	drainV->get(&dtype, 1);

}

int CohortInputer::getSpRecID(const int &chtid){
	NcError err(NcError::silent_nonfatal);

	NcFile spchtidFile(spidfname.c_str(), NcFile::ReadOnly);
 	NcVar* spchtidV = spchtidFile.get_var("SPCHTID");
 	if(spchtidV==NULL){
 	   throw Exception("Cannot get spchtid  in SpChtidFile ", I_NCVAR_NOT_EXIST);
 	}

	int id=-1;
	for (int i=0; i<(int)spchtidV->num_vals(); i++){
		spchtidV->set_cur(i);
		spchtidV->get(&id, 1);
		if(id==chtid) return i;
	}

	return -1;
}

int CohortInputer::getTrRecID(const int &chtid){
	NcError err(NcError::silent_nonfatal);

	NcFile trchtidFile(tridfname.c_str(), NcFile::ReadOnly);
 	NcVar* trchtidV = trchtidFile.get_var("TRCHTID");
 	if(trchtidV==NULL){
 	   throw Exception("Cannot get trchtid  in TrChtidFile ", I_NCVAR_NOT_EXIST);
 	}

	int id=-1;
	for (int i=0; i<(int)trchtidV->num_vals(); i++){
		trchtidV->set_cur(i);
		trchtidV->get(&id, 1);
		if(id==chtid) return i;
	}

	return -1;
}

void CohortInputer::getEqchtid5SpFile(int & eqchtid,  const int &recid){
	NcError err(NcError::silent_nonfatal);

	NcFile spchtidFile(spidfname.c_str(), NcFile::ReadOnly);
 	NcVar* eqchtid5spV = spchtidFile.get_var("EQCHTID");
 	if(eqchtid5spV==NULL){
 	   throw Exception("Cannot get eqchtid in SpChtidFile ", I_NCVAR_NOT_EXIST);
 	}

	eqchtid5spV->set_cur(recid);
	eqchtid5spV->get(&eqchtid, 1);

}

void CohortInputer::getSpchtid5TrFile(int & spchtid,  const int &recid){
	NcError err(NcError::silent_nonfatal);

	NcFile trchtidFile(tridfname.c_str(), NcFile::ReadOnly);
 	NcVar* spchtid5trV = trchtidFile.get_var("SPCHTID");
 	if(spchtid5trV==NULL){
 	   throw Exception("Cannot get spchtid  in TrChtidFile ", I_NCVAR_NOT_EXIST);
 	}

    spchtid5trV->set_cur(recid);
    spchtid5trV->get(&spchtid, 1);

}

//////////////////////////////////Fire Occur////////////////////////////
void CohortInputer::getSpinupFireOccur(int spoccur[MAX_SP_FIR_OCR_NUM], const int &recid){
	NcError err(NcError::silent_nonfatal);

	NcFile spfireFile(spffname.c_str(), NcFile::ReadOnly);
 	NcVar* spoccurV = spfireFile.get_var("FIRE");
 	if(spoccurV==NULL){
 	   throw Exception("Cannot get Fire in spFire ", I_NCVAR_NOT_EXIST);
 	}

	spoccurV->set_cur(recid);
	NcBool nb1 = spoccurV->get(&spoccur[0],1, MAX_SP_FIR_OCR_NUM);
	if(!nb1){
	    throw Exception("problem in reading spfire year data",I_NCVAR_NOT_EXIST);
	}
	
}

void CohortInputer::getSpinupFireSeason(int spseason[MAX_SP_FIR_OCR_NUM], const int &recid){
	NcError err(NcError::silent_nonfatal);

	NcFile spfireFile(spffname.c_str(), NcFile::ReadOnly);
 	NcVar* spseasonV = spfireFile.get_var("SEASON");
 	if(spseasonV==NULL){
 	   throw Exception("Cannot get Fire Season in spFire ", I_NCVAR_NOT_EXIST);
  	}
	
	spseasonV->set_cur(recid);
	NcBool nb1 = spseasonV->get(&spseason[0],1, MAX_SP_FIR_OCR_NUM);
	if(!nb1){
	    throw Exception("problem in reading fire data",I_NCVAR_NOT_EXIST);	
	}

}

void CohortInputer::getSpinupVegSeverity(double spvegsev[MAX_SP_FIR_OCR_NUM], const int &recid){
	NcError err(NcError::silent_nonfatal);

	NcFile spfireFile(spffname.c_str(), NcFile::ReadOnly);
	NcVar* spvegsevV = spfireFile.get_var("VEGSEVERITY");
	if(spvegsevV==NULL){
   		throw Exception("Cannot get veg severity in spFire ", I_NCVAR_NOT_EXIST);
	}

	spvegsevV->set_cur(recid);
	NcBool nb1 = spvegsevV->get(&spvegsev[0],1, MAX_SP_FIR_OCR_NUM);
	if(!nb1){
	    throw Exception("problem in reading spfire veg severity data",I_NCVAR_NOT_EXIST);
	}
	
}

void CohortInputer::getSpinupSoiSeverity(double spsoilsev[MAX_SP_FIR_OCR_NUM], const int &recid){
	NcError err(NcError::silent_nonfatal);

	NcFile spfireFile(spffname.c_str(), NcFile::ReadOnly);
	NcVar* spsoisevV = spfireFile.get_var("SOISEVERITY");
	if(spsoisevV==NULL){
   		throw Exception("Cannot get Fire soi severity  in initFire ", I_NCVAR_NOT_EXIST);
	}

	spsoisevV->set_cur(recid);
	NcBool nb1 = spsoisevV->get(&spsoilsev[0],1, MAX_SP_FIR_OCR_NUM);
	if(!nb1){
	    throw Exception("problem in reading spfire soil severity data",I_NCVAR_NOT_EXIST);
	}
	
}

//////////////////////////////////Fire Occur////////////////////////////
void CohortInputer::getTransientFireOccur(int troccur[MAX_TR_FIR_OCR_NUM], const int &recid){
	NcError err(NcError::silent_nonfatal);

	NcFile trfireFile(trffname.c_str(), NcFile::ReadOnly);
 	NcVar* troccurV = trfireFile.get_var("FIRE");
 	if(troccurV==NULL){
 	   throw Exception("Cannot get Fire Occur in trFire ", I_NCVAR_NOT_EXIST);
 	}

	troccurV->set_cur(recid);
	NcBool nb1 = troccurV->get(&troccur[0],1, MAX_TR_FIR_OCR_NUM);
	if(!nb1){
	    throw Exception("problem in reading fire data",I_NCVAR_NOT_EXIST);
	}

}

void CohortInputer::getTransientFireSeason(int trseason[MAX_TR_FIR_OCR_NUM], const int &recid){
	NcError err(NcError::silent_nonfatal);

	NcFile trfireFile(trffname.c_str(), NcFile::ReadOnly);
 	NcVar* trseasonV = trfireFile.get_var("SEASON");
 	if(trseasonV==NULL){
 	   throw Exception("Cannot get Fire Season in trFire ", I_NCVAR_NOT_EXIST);
 	}

	trseasonV->set_cur(recid);
	NcBool nb1 = trseasonV->get(&trseason[0],1, MAX_TR_FIR_OCR_NUM);
	if(!nb1){
	    throw Exception("problem in reading fire season data",I_NCVAR_NOT_EXIST);
	}

}

void CohortInputer::getTransientVegSeverity(double trvegsev[MAX_TR_FIR_OCR_NUM], const int &recid){
	NcError err(NcError::silent_nonfatal);

	NcFile trfireFile(trffname.c_str(), NcFile::ReadOnly);
	NcVar* trvegsevV = trfireFile.get_var("VEGSEVERITY");
		if(trvegsevV==NULL){
	   		throw Exception("Cannot get trFire veg severity", I_NCVAR_NOT_EXIST);
		}
	
	trvegsevV->set_cur(recid);
	NcBool nb1 = trvegsevV->get(&trvegsev[0],1, MAX_SP_FIR_OCR_NUM);
	if(!nb1){
	    throw Exception("problem in reading trfire veg severity data",I_NCVAR_NOT_EXIST);
	}
	
}

void CohortInputer::getTransientSoiSeverity(double trsoilsev[MAX_TR_FIR_OCR_NUM], const int &recid){

	NcError err(NcError::silent_nonfatal);

	NcFile trfireFile(trffname.c_str(), NcFile::ReadOnly);
	NcVar* trsoilsevV = trfireFile.get_var("SOILSEVERITY");
	if(trsoilsevV==NULL){
		throw Exception("Cannot get trFire soil severity", I_NCVAR_NOT_EXIST);
	}
	
	trsoilsevV->set_cur(recid);
	NcBool nb1 = trsoilsevV->get(&trsoilsev[0],1, MAX_SP_FIR_OCR_NUM);
	if(!nb1){
	    throw Exception("problem in reading trfire soil severity data",I_NCVAR_NOT_EXIST);
	}

}

void CohortInputer::setModelData(ModelData* mdp){
   md = mdp;
};
