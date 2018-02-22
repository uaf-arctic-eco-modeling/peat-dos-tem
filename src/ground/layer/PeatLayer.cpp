/*! \file
 * 
 */
#include "PeatLayer.h"

PeatLayer::PeatLayer(const double & pdz, const int & upper){
	
	tkey=I_PEAT;
	dz = pdz;
	isFibric =false;
	isHumic  =false;
	fromFire =false;

// these properties will not change upon fire disturbance
// it is assumed that when fire occurs, the left moss will
// be converted to deep organic type
    tcsolid = 0.25;
    // kg/m3, from ATBalland22005a
	
	//psisat = -120; // mm
	
	fldcap = 0.516; // reference ? unit vwater/vtot ? // not used
	wltpnt = 0.321; // reference   // not used
   	vhcsolid=2.5e6; //J/m3K

// the porosity might be changed with depth
// the porosity can also be changed with the occurrence of fire   
    if(upper==1){
        poro = 0.97;//0.95; Y.Mi
		isFibric =true;
		color = 8;// ATBeringer52001a;
    	albsatvis = 0.075;
   		albsatnir = 0.15;
   		albdryvis = 0.15;
   		albdrynir = 0.3;
        
        prtlden = 1.51e3;//Y.Mi 1.3e3 ;
        
   		hksat = 0.28;  
   	 	bsw=2.7;
   	    bulkden = 50;// Y.Mi 51000; // g/m3
   		cfrac = 44.2; // %
   		psisat =-10.0;
    }else{
        poro = 0.9;//0.8; Y.Mi
		isHumic =true;	
		color = 3;// ATBeringer52001a;
    	albsatvis = 0.075;
   		albsatnir = 0.15;
   		albdryvis = 0.15;
   		albdrynir = 0.3;
 
        prtlden = 1.6e3;//Y.Mi 1.3e3 ;
       	bulkden = 155;// Y.Mi 176000; // g/m3
   	  	cfrac = 35.2; // %
        
   		bsw=8;
   		hksat =0.002;
   		psisat =-12;
    }

	//whenever poro is changed, deriveProperty need to be called again
	//tcmin =0.01;    	
    deriveProperty();
};

void PeatLayer::humify(){
	    poro = 0.9;//0.8; Y.Mi
		isHumic =true;	
		isFibric=false;
		color =3;// ATBeringer52001a;
    	albsatvis = 0.075;
   		albsatnir = 0.15;
   		albdryvis = 0.15;
   		albdrynir = 0.3;
    
    prtlden = 1.6e3;//Y.Mi 1.3e3 ;
    bulkden = 155;// Y.Mi 176000; // g/m3
    
   	
   		//bsw = 6.1;//4.0; //
   	 	hksat = 0.02;//0.1;//0.28; //mm/s
   		//tcmin =0.1;//0.10;
   		//psisat =-10.1; 
	 	deriveProperty();
};



bool PeatLayer::isMoss(){
  return false;	
}

bool PeatLayer::isMineral(){
  return false;	
}
bool PeatLayer::isPeat(){
  return true;	
}
