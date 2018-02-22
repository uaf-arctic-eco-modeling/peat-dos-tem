#include "RestartInputer.h"

/*! constructor */
 RestartInputer::RestartInputer(){
 
};

 RestartInputer::~RestartInputer(){
 	//cout<< "closing output files in RestartInputer \n";
   
    if(restartFile!=NULL){
    	restartFile->close();
	delete restartFile;
    }

};

void RestartInputer::init(string & dirfile){
 	
//	string filename =outputdir+ "restart.nc";
	string filename =dirfile;    //Yuan: input file name with dir 

	restartFile = new NcFile(filename.c_str(), NcFile::ReadOnly);
	if(!restartFile->is_valid()){
 		string msg = filename+" is not valid";
 		char* msgc = const_cast< char* > ( msg.c_str());
 		throw Exception(msgc, I_NCFILE_NOT_EXIST);
 	}
	
	chtD = restartFile->get_dim("CHTID");
 	if(!chtD->is_valid()){
 		throw Exception("Cohort Dimension is no Valid in RestartInputer::init", I_NCDIM_NOT_EXIST);
 	}
 	
 	snowlayerD = restartFile->get_dim("SNOWLAYER");
 	if(!snowlayerD->is_valid()){
 		throw Exception("snowlayer Dimension is no Valid in reaterinputer::init", I_NCDIM_NOT_EXIST);
 	}
 	
    soillayerD = restartFile->get_dim("SOILLAYER");
 	if(!soillayerD->is_valid()){
 		throw Exception("soillayer Dimension is no Valid in reaterinputer::init", I_NCDIM_NOT_EXIST);
 	}
 	
 	rocklayerD = restartFile->get_dim("ROCKLAYER");
 	if(!rocklayerD->is_valid()){
  		throw Exception("rocklayer Dimension is no Valid in reaterinputer::init", I_NCDIM_NOT_EXIST);
 	}
 	
    frontD = restartFile->get_dim("FRONTLAYER");
 	if(!frontD->is_valid()){
 		throw Exception(" front Dimension is no Valid in reaterinputer::init", I_NCDIM_NOT_EXIST);
 	}
 	
 	meanyearD = restartFile->get_dim("MEANYEAR");
 	if(!meanyearD->is_valid()){
  		throw Exception(" mean yearDimension is no Valid in reaterinputer::init", I_NCDIM_NOT_EXIST);
 	}
 	
 	chtidV = restartFile->get_var("CHTID");
 	if(chtidV==NULL){
 	   throw Exception("Cannot get chtidv in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
 	errcodeV = restartFile->get_var("ERRCODE");
 	if(chtidV==NULL){
 	   throw Exception("Cannot get chtidv in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}

 	TSsnowV = restartFile->get_var("TSsnow");
 	if(TSsnowV==NULL){
 	   throw Exception("Cannot get TSsnow in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
 	DZsnowV = restartFile->get_var("DZsnow");
 	if(DZsnowV==NULL){
 	   throw Exception("Cannot get DZsnow in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
 	LIQsnowV = restartFile->get_var("LIQsnow");
 	if(LIQsnowV==NULL){
 	   throw Exception("Cannot get LIQsnow in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
 	ICEsnowV = restartFile->get_var("ICEsnow");
 	if(ICEsnowV==NULL){
 	   throw Exception("Cannot get ICEsnow in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
 	AGEsnowV = restartFile->get_var("AGEsnow");
 	if(AGEsnowV==NULL){
 	   throw Exception("Cannot get AGEsnow in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
 	RHOsnowV = restartFile->get_var("RHOsnow");
 	if(RHOsnowV==NULL){
 	   throw Exception("Cannot get RHOsnow in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
 	TSsoilV = restartFile->get_var("TSsoil");
 	if(TSsoilV==NULL){
 	   throw Exception("Cannot get TSsoil in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
 	DZsoilV = restartFile->get_var("DZsoil");
 	if(DZsoilV==NULL){
 	   throw Exception("Cannot get DZsoil in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
 	LIQsoilV = restartFile->get_var("LIQsoil");
 	if(LIQsoilV==NULL){
 	   throw Exception("Cannot get LIQsoil in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
 	frontFTV = restartFile->get_var("frontFT");
 	if(frontFTV==NULL){
 	   throw Exception("Cannot get frontFT in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
 	frontZV = restartFile->get_var("frontZ");
 	if(frontZV==NULL){
 	   throw Exception("Cannot get frontZ in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
 	ICEsoilV = restartFile->get_var("ICEsoil");
 	if(ICEsoilV==NULL){
 	   throw Exception("Cannot get ICEsoil in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
 	TYPEsoilV = restartFile->get_var("TYPEsoil");
 	if(TYPEsoilV==NULL){
 	   throw Exception("Cannot get TYPEsoil in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
 	TYPEminV = restartFile->get_var("TYPEmin");
 	if(TYPEminV==NULL){
 	   throw Exception("Cannot get TYPEmin in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
 	FROZENsoilV = restartFile->get_var("FROZENsoil");
 	if(FROZENsoilV==NULL){
 	   throw Exception("Cannot get FROZENsoil in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
 	NONCsoilV = restartFile->get_var("NONCsoil");
 	if(NONCsoilV==NULL){
 	   throw Exception("Cannot get NONCsoil in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	REACsoilV = restartFile->get_var("REACsoil");
 	if(REACsoilV==NULL){
 	   throw Exception("Cannot get REACsoil in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	/*
 	ROOTsoilV = restartFile->get_var("ROOTsoil");
 	if(ROOTsoilV==NULL){
 	   throw Exception("Cannot get ROOTsoil in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	*/
 	TSrockV = restartFile->get_var("TSrock");
 	if(TSrockV==NULL){
 	   throw Exception("Cannot get TSrock in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
 	DZrockV = restartFile->get_var("DZrock");
 	if(DZrockV==NULL){
 	   throw Exception("Cannot get DZrock in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
	frontZV = restartFile->get_var("frontZ");
 	if(frontZV==NULL){
 	   throw Exception("Cannot get frontZ in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
 	frontFTV = restartFile->get_var("frontFT");
 	if(frontFTV==NULL){
 	   throw Exception("Cannot get frontFT in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
	
	solnV = restartFile->get_var("SOLN");
 	if(solnV==NULL){
 	   throw Exception("Cannot get soln in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
 	avlnV = restartFile->get_var("AVLN");
 	if(avlnV==NULL){
 	   throw Exception("Cannot get avln in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
 	wdebrisV = restartFile->get_var("WDEBRIS");
 	if(wdebrisV==NULL){
 	   throw Exception("Cannot get wdebris in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
	
	strnV = restartFile->get_var("STRN");
 	if(strnV==NULL){
 	   throw Exception("Cannot get strn in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
 	stonV = restartFile->get_var("STON");
 	if(stonV==NULL){
 	   throw Exception("Cannot get ston in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	vegcV = restartFile->get_var("VEGC");
 	if(vegcV==NULL){
 	   throw Exception("Cannot get vegc in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	deadcV = restartFile->get_var("DEADC");
 	if(deadcV==NULL){
 	   throw Exception("Cannot get deadc in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	deadnV = restartFile->get_var("DEADN");
 	if(deadnV==NULL){
 	   throw Exception("Cannot get deadn in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
	
	/*
	petV = restartFile->get_var("PET");
 	if(petV==NULL){
 	   throw Exception("Cannot get pet in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
 	
 	eetV = restartFile->get_var("EET");
 	if(eetV==NULL){
 	   throw Exception("Cannot get eet in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	*/
 	
 	laiV = restartFile->get_var("LAI");
 	if(laiV==NULL){
 	   throw Exception("Cannot get lai in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
	prveetmxV = restartFile->get_var("PRVEETMX");
 	if(prveetmxV==NULL){
 	   throw Exception("Cannot get prveetmx in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
 	prvpetmxV = restartFile->get_var("PRVPETMX");
 	if(prvpetmxV==NULL){
 	   throw Exception("Cannot get prvpetmx in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
 	foliagemxV = restartFile->get_var("FOLIAGEMX");
 	if(foliagemxV==NULL){
 	   throw Exception("Cannot get foliage in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
 	unnormleafV = restartFile->get_var("UNNORMLEAF");
 	if(unnormleafV==NULL){
 	   throw Exception("Cannot get unnormleaf in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
 		prvunnormleafmxV = restartFile->get_var("PRVUNNORMLEAFMX");
 	if(prvunnormleafmxV==NULL){
 	   throw Exception("Cannot get prvunnormleafmx in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 		prvtoptV = restartFile->get_var("PRVTOPT");
 	if(prvtoptV==NULL){
 	   throw Exception("Cannot get prvtopt in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
 	c2nV = restartFile->get_var("C2N");
 	if(c2nV==NULL){
 	   throw Exception("Cannot get c2n in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
 	 kdfibV = restartFile->get_var("KDFIB");
 	if(kdfibV==NULL){
 	   throw Exception("Cannot get kdfib in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
 	 kdhumV = restartFile->get_var("KDHUM");
 	if(kdhumV==NULL){
 	   throw Exception("Cannot get kdhum in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	 kdminV = restartFile->get_var("KDMIN");
 	if(kdminV==NULL){
 	   throw Exception("Cannot get kdmin in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	 kdslowV = restartFile->get_var("KDSLOW");
 	if(kdslowV==NULL){
 	   throw Exception("Cannot get kdslow in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
	 kdfibV_m = restartFile->get_var("KDFIB_m");
	if(kdfibV_m==NULL){
	   throw Exception("Cannot get kdfib_m in restartinputer::init ", I_NCVAR_NOT_EXIST);
	}

	 kdhumV_m = restartFile->get_var("KDHUM_m");
	if(kdhumV_m==NULL){
	   throw Exception("Cannot get kdhum_m in restartinputer::init ", I_NCVAR_NOT_EXIST);
	}
	 kdminV_m = restartFile->get_var("KDMIN_m");
	if(kdminV_m==NULL){
	   throw Exception("Cannot get kdmin_m in restartinputer::init ", I_NCVAR_NOT_EXIST);
	}
	 kdslowV_m = restartFile->get_var("KDSLOW_m");
	if(kdslowV_m==NULL){
	   throw Exception("Cannot get kdslow_m in restartinputer::init ", I_NCVAR_NOT_EXIST);
	}
	 RPcV = restartFile->get_var("RP");
	if(RPcV==NULL){
	   throw Exception("Cannot get RPcV in restartinputer::init ", I_NCVAR_NOT_EXIST);
	}
	 TVEGcV = restartFile->get_var("TVEG");
	if(TVEGcV==NULL){
	   throw Exception("Cannot get TVEGcV in restartinputer::init ", I_NCVAR_NOT_EXIST);
	}
	/*
	EnvLaiV = restartFile->get_var("EnvLai");
 	if(EnvLaiV==NULL){
 	   throw Exception("Cannot get EnvLai in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	*/
 	
	ysfV = restartFile->get_var("YSF");
 	if(ysfV==NULL){
 	   throw Exception("Cannot get ysf in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
	burnednV = restartFile->get_var("BURNEDN");
 	if(burnednV==NULL){
 	   throw Exception("Cannot get burnedn in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
  
 	toptAV = restartFile->get_var("TOPTA");
 	if(toptAV==NULL){
 	   throw Exception("Cannot get toptA in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
 	unnormleafmxAV = restartFile->get_var("UNNORMLEAFMXA");
 	if(unnormleafmxAV==NULL){
 	   throw Exception("Cannot get unnormleafmxA in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
 	petmxAV = restartFile->get_var("PETMXA");
 	if(petmxAV==NULL){
 	   throw Exception("Cannot get petmxA in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
 	
 	eetmxAV = restartFile->get_var("EETMXA");
 	if(eetmxAV==NULL){
 	   throw Exception("Cannot get eetmxA in restartinputer::init ", I_NCVAR_NOT_EXIST);
 	}
  
 	
};

////////////////////////////////////////////////////////////////////////////////////////
//Yuan: cid is the cohort id, but not exactly the record id in the .nc file
int RestartInputer::getRecordId(const int &chtid){

	int chtno = (int)chtD->size();
	int id;
	for (int i=0; i<chtno; i++){
		getChtId(id, i);
		if (id==chtid) return i;
//		if ((chtidV->get_rec(i))->as_int(0)==chtid) return i;   //Yuan: memory consumption very large
		
	}
	cout << "cohort "<< chtid<<" NOT exists in RestartInputer\n";	
	return -1;
}

////////////////////////////////////////////////////////////////////////////////////////
//Yuan: the cid in the following is actually the record id

void RestartInputer::getChtId(int &chtid, const int &cid){       
	
	chtidV->set_cur(cid);
	NcBool nb1 = chtidV->get(&chtid,1);
	if(!nb1){	 
	 throw Exception("problem in reading chtid in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}

void RestartInputer::getERRCODE(int & errcode, const int &cid){       
	
	errcodeV->set_cur(cid);
	NcBool nb1 = errcodeV->get(&errcode,1);
	if(!nb1){	 
	 throw Exception("problem in reading errcode in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}

void RestartInputer::getYSF(int & ysf, const int &cid){
	
	ysfV->set_cur(cid);
	NcBool nb1 = ysfV->get(&ysf,1);
	if(!nb1){	 
	 throw Exception("problem in reading ysf in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}

void RestartInputer::getBURNEDN(double & burnedn, const int &cid){
	
	burnednV->set_cur(cid);
	NcBool nb1 = burnednV->get(&burnedn,1);
	if(!nb1){
	 
	 throw Exception("problem in reading burnedn in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}


void RestartInputer::getVEGC(double & vegc, const int &cid){
	
	vegcV->set_cur(cid);
	NcBool nb1 = vegcV->get(&vegc,1);
	if(!nb1){
	 throw Exception("problem in reading vegc in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}

void RestartInputer::getSTRN(double & strn, const int &cid){
	
	strnV->set_cur(cid);
	NcBool nb1 = strnV->get(&strn,1);
	if(!nb1){
	 throw Exception("problem in reading strn in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}


void RestartInputer::getUNNORMLEAF(double & unnormleaf, const int &cid){
	
	unnormleafV->set_cur(cid);
	NcBool nb1 = unnormleafV->get(&unnormleaf,1);
	if(!nb1){
	 
	 throw Exception("problem in reading unnormleaf in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}
/*
void RestartInputer::getPET(double & pet, const int &cid){
	
	petV->set_cur(cid);
	NcBool nb1 = petV->get(&pet,1);
	if(!nb1){
	 
	 throw Exception("problem in reading pet in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}

void RestartInputer::getEET(double & eet, const int &cid){
	
	eetV->set_cur(cid);
	NcBool nb1 = eetV->get(&eet,1);
	if(!nb1){
	 
	 throw Exception("problem in reading eet in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}*/

void RestartInputer::getLAI(double & lai, const int &cid){
	
	laiV->set_cur(cid);
	NcBool nb1 = laiV->get(&lai,1);
	if(!nb1){
	 
	 throw Exception("problem in reading lai in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}

void RestartInputer::getPRVPETMX(double & prvpetmx, const int &cid){
	
	prvpetmxV->set_cur(cid);
	NcBool nb1 = prvpetmxV->get(&prvpetmx,1);
	if(!nb1){
	 
	 throw Exception("problem in reading prvpetmx in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}

void RestartInputer::getPRVEETMX(double & prveetmx, const int &cid){
	
	prveetmxV->set_cur(cid);
	NcBool nb1 = prveetmxV->get(&prveetmx,1);
	if(!nb1){
	 
	 throw Exception("problem in reading prveetmx in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}

void RestartInputer::getFOLIAGEMX(double & foliagemx, const int &cid){
	
	foliagemxV->set_cur(cid);
	NcBool nb1 = foliagemxV->get(&foliagemx,1);
	if(!nb1){
	 
	 throw Exception("problem in reading foliagemx in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}
void RestartInputer::getPRVTOPT(double & prvtopt, const int &cid){
	
	prvtoptV->set_cur(cid);
	NcBool nb1 = prvtoptV->get(&prvtopt,1);
	if(!nb1){
	 
	 throw Exception("problem in reading prvtopt in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}

void RestartInputer::getC2N(double & c2n, const int &cid){
	
	c2nV->set_cur(cid);
	NcBool nb1 = c2nV->get(&c2n,1);
	if(!nb1){
	 
	 throw Exception("problem in reading c2n in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}


void RestartInputer::getKDFIB(double & kdfib, const int &cid){
	
	kdfibV->set_cur(cid);
	NcBool nb1 = kdfibV->get(&kdfib,1);
	if(!nb1){
	 
	 throw Exception("problem in reading kdfib in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}


void RestartInputer::getKDHUM(double & kdhum, const int &cid){
	
	kdhumV->set_cur(cid);
	NcBool nb1 = kdhumV->get(&kdhum,1);
	if(!nb1){
	 
	 throw Exception("problem in reading kdhum in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}

void RestartInputer::getKDMIN(double & kdmin, const int &cid){
	
	kdminV->set_cur(cid);
	NcBool nb1 = kdminV->get(&kdmin,1);
	if(!nb1){
	 
	 throw Exception("problem in reading kdmin in RestartInputer",  I_NCVAR_GET_ERROR);
	}
}


void RestartInputer::getKDSLOW(double & kdslow, const int &cid){
	
	kdslowV->set_cur(cid);
	NcBool nb1 = kdslowV->get(&kdslow,1);
	if(!nb1){
	 
	 throw Exception("problem in reading kdslow in RestartInputer",  I_NCVAR_GET_ERROR);
	}
}

void RestartInputer::getKDFIB_m(double & kdfib_m, const int &cid){

	kdfibV_m->set_cur(cid);
	NcBool nb1 = kdfibV_m->get(&kdfib_m,1);
	if(!nb1){

	 throw Exception("problem in reading kdfib_m in  RestartInputer",  I_NCVAR_GET_ERROR);
	}
}


void RestartInputer::getKDHUM_m(double & kdhum_m, const int &cid){

	kdhumV_m->set_cur(cid);
	NcBool nb1 = kdhumV_m->get(&kdhum_m,1);
	if(!nb1){

	 throw Exception("problem in reading kdhum_m in  RestartInputer",  I_NCVAR_GET_ERROR);
	}
}

void RestartInputer::getKDMIN_m(double & kdmin_m, const int &cid){

	kdminV_m->set_cur(cid);
	NcBool nb1 = kdminV_m->get(&kdmin_m,1);
	if(!nb1){

	 throw Exception("problem in reading kdmin_m in RestartInputer",  I_NCVAR_GET_ERROR);
	}
}


void RestartInputer::getKDSLOW_m(double & kdslow_m, const int &cid){

	kdslowV_m->set_cur(cid);
	NcBool nb1 = kdslowV_m->get(&kdslow_m,1);
	if(!nb1){

	 throw Exception("problem in reading kdslow_m in RestartInputer",  I_NCVAR_GET_ERROR);
	}
}

void RestartInputer::getRP(double & RP, const int &cid){

	RPcV->set_cur(cid);
	NcBool nb1 = RPcV->get(&RP,1);
	if(!nb1){

	 throw Exception("problem in reading RPcV in RestartInputer",  I_NCVAR_GET_ERROR);
	}
}

void RestartInputer::getTVEG(double & TVEG, const int &cid){

	TVEGcV->set_cur(cid);
	NcBool nb1 = TVEGcV->get(&TVEG,1);
	if(!nb1){

	 throw Exception("problem in reading TVEGcV in RestartInputer",  I_NCVAR_GET_ERROR);
	}
}

void RestartInputer::getPRVUNNORMLEAFMX(double & prvunnormleafmx, const int &cid){
	
	prvunnormleafmxV->set_cur(cid);
	NcBool nb1 = prvunnormleafmxV->get(&prvunnormleafmx,1);
	if(!nb1){
	 
	 throw Exception("problem in reading prvunnormleafmx in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}
void RestartInputer::getSTON(double & ston, const int &cid){
	
	stonV->set_cur(cid);
	NcBool nb1 = stonV->get(&ston,1);
	if(!nb1){
	 
	 throw Exception("problem in reading ston in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}

void RestartInputer::getWDEBRIS(double & wdebris, const int &cid){
	
	wdebrisV->set_cur(cid);
	NcBool nb1 = wdebrisV->get(&wdebris,1);
	if(!nb1){
	 
	 throw Exception("problem in reading wdebris in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}

void RestartInputer::getSOLN(double & soln, const int &cid){
	
	solnV->set_cur(cid);
	NcBool nb1 = solnV->get(&soln,1);
	if(!nb1){
	 
	 throw Exception("problem in reading soln in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}

void RestartInputer::getAVLN(double & avln, const int &cid){
	
	avlnV->set_cur(cid);
	NcBool nb1 = avlnV->get(&avln,1);
	if(!nb1){
	 
	 throw Exception("problem in reading avln in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}
void RestartInputer::getDEADC(double & deadc, const int &cid){
	
	deadcV->set_cur(cid);
	NcBool nb1 = deadcV->get(&deadc,1);
	if(!nb1){
	 
	 throw Exception("problem in reading deadc in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}

void RestartInputer::getDEADN(double & deadn, const int &cid){
	
	deadnV->set_cur(cid);
	NcBool nb1 = deadnV->get(&deadn,1);
	if(!nb1){
	 
	 throw Exception("problem in reading deadn in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}

void RestartInputer::getDZsnow(double  DZsnow[], const int &cid){

	DZsnowV->set_cur(cid);
	
	NcBool nb1 = DZsnowV->get(&DZsnow[0],1, MAX_SNW_LAY);
	if(!nb1){
	 
	 throw Exception("problem in reading DZsnow in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}


void RestartInputer::getTSsnow(double  TSsnow[], const int &cid){
	TSsnowV->set_cur(cid);
	
	NcBool nb1 = TSsnowV->get(&TSsnow[0],1, MAX_SNW_LAY);
	if(!nb1){
	 
	 throw Exception("problem in reading TSsnow in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}


void RestartInputer::getAGEsnow(double  AGEsnow[], const int &cid){
	AGEsnowV->set_cur(cid);
	NcBool nb1 = AGEsnowV->get(&AGEsnow[0],1, MAX_SNW_LAY);
	if(!nb1){
	 throw Exception("problem in reading AGEsnow in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}

void RestartInputer::getICEsnow(double  ICEsnow[], const int &cid){
	ICEsnowV->set_cur(cid);
	NcBool nb1 = ICEsnowV->get(&ICEsnow[0],1, MAX_SNW_LAY);
	if(!nb1){
	 
	 throw Exception("problem in reading ICEsnow in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}

void RestartInputer::getRHOsnow(double  RHOsnow[], const int &cid){
	RHOsnowV->set_cur(cid);
	NcBool nb1 = RHOsnowV->get(&RHOsnow[0],1, MAX_SNW_LAY);
	if(!nb1){
	 
	 throw Exception("problem in reading RHOsnow in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}

void RestartInputer::getDZrock(double  DZrock[], const int &cid){
	
	DZrockV->set_cur(cid);
	NcBool nb1 = DZrockV->get(&DZrock[0],1, MAX_ROC_LAY);
	if(!nb1){
	 
	 throw Exception("problem in reading DZrock in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}

void RestartInputer::getTSrock(double  TSrock[], const int &cid){
	
	TSrockV->set_cur(cid);
	NcBool nb1 = TSrockV->get(&TSrock[0],1, MAX_ROC_LAY);
	if(!nb1){
	 
	 throw Exception("problem in reading TSrock in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}

void RestartInputer::getDZsoil(double  DZsoil[], const int &cid){
	
	DZsoilV->set_cur(cid);
	NcBool nb1 = DZsoilV->get(&DZsoil[0],1, MAX_SOI_LAY);
	if(!nb1){
	 
	 throw Exception("problem in reading DZsoil in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}

void RestartInputer::getTSsoil(double  TSsoil[], const int &cid){
	
	TSsoilV->set_cur(cid);
	NcBool nb1 = TSsoilV->get(&TSsoil[0],1, MAX_SOI_LAY);
	if(!nb1){
	 
	 throw Exception("problem in reading TSsoil in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}

void RestartInputer::getLIQsoil(double  LIQsoil[], const int &cid){
	
	LIQsoilV->set_cur(cid);
	NcBool nb1 = LIQsoilV->get(&LIQsoil[0],1, MAX_SOI_LAY);
	if(!nb1){
	 
	 throw Exception("problem in reading LIQsoil in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}

void RestartInputer::getICEsoil(double  ICEsoil[], const int &cid){
	
	ICEsoilV->set_cur(cid);
	NcBool nb1 = ICEsoilV->get(&ICEsoil[0],1, MAX_SOI_LAY);
	if(!nb1){
	 
	 throw Exception("problem in reading ICEsoil in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}
void RestartInputer::getNONC(double  NONC[], const int &cid){
	
	NONCsoilV->set_cur(cid);
	NcBool nb1 = NONCsoilV->get(&NONC[0],1, MAX_SOI_LAY);
	if(!nb1){
	 
	 throw Exception("problem in reading NONC in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}

void RestartInputer::getREAC(double  REAC[], const int &cid){
	
	REACsoilV->set_cur(cid);
	NcBool nb1 = REACsoilV->get(&REAC[0],1, MAX_SOI_LAY);
	if(!nb1){
	 
	 throw Exception("problem in reading REAC in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}

void RestartInputer::getFROZENsoil(int  FROZENsoil[], const int &cid){
	
	FROZENsoilV->set_cur(cid);
	NcBool nb1 = FROZENsoilV->get(&FROZENsoil[0],1, MAX_SOI_LAY);
	if(!nb1){
	 
	 throw Exception("problem in reading FROZENsoil in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}

void RestartInputer::getTYPEsoil(int  TYPEsoil[], const int &cid){
	
	TYPEsoilV->set_cur(cid);
	NcBool nb1 = TYPEsoilV->get(&TYPEsoil[0],1, MAX_SOI_LAY);
	if(!nb1){
	 
	 throw Exception("problem in reading TYPEsoil in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}

void RestartInputer::getTYPEmin(int  TYPEmin[], const int &cid){
	
	TYPEminV->set_cur(cid);
	NcBool nb1 = TYPEminV->get(&TYPEmin[0],1, MAX_MIN_LAY);
	if(!nb1){
	 
	 throw Exception("problem in reading TYPEmin in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}

void RestartInputer::getFrontFT(int  frontFT[], const int &cid){
	
	frontFTV->set_cur(cid);
	NcBool nb1 = frontFTV->get(&frontFT[0],1, MAX_NUM_FNT);
	if(!nb1){
	 
	 throw Exception("problem in reading frontFT in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}


void RestartInputer::getFrontZ(double  frontZ[], const int &cid){
	
	frontZV->set_cur(cid);
	NcBool nb1 = frontZV->get(&frontZ[0],1, MAX_NUM_FNT);
	if(!nb1){
	 
	 throw Exception("problem in reading frontZ in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}

void RestartInputer::getTOPTA(double  frontFT[], const int &cid){
	
	toptAV->set_cur(cid);
	NcBool nb1 = toptAV->get(&frontFT[0],1,10);
	if(!nb1){
	 
	 throw Exception("problem in reading topta in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}
void RestartInputer::getUNNORMLEAFMXA(double  frontFT[], const int &cid){
	
	unnormleafmxAV->set_cur(cid);
	NcBool nb1 = unnormleafmxAV->get(&frontFT[0],1,10);
	if(!nb1){
	 
	 throw Exception("problem in reading unnormleafmxa in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}
void RestartInputer::getPETMXA(double  frontFT[], const int &cid){
	
	petmxAV->set_cur(cid);
	NcBool nb1 = petmxAV->get(&frontFT[0],1,10);
	if(!nb1){
	 
	 throw Exception("problem in reading petmxa in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}
void RestartInputer::getEETMXA(double frontFT[], const int &cid){
	
	eetmxAV->set_cur(cid);
	NcBool nb1 = eetmxAV->get(&frontFT[0],1,10);
	if(!nb1){
	 
	 throw Exception("problem in reading eetmxa in  RestartInputer",  I_NCVAR_GET_ERROR);	
	}
}

