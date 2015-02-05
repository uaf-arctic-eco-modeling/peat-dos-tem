/*! \file
 * 
 */
#ifndef SOILLAYER_H_
#define SOILLAYER_H_
#include "Layer.h"


#include "../../inc/PhysicalConstants.h"

#include <math.h>
#include <cmath>
#include <deque>
#include <vector>
#include <memory>
using namespace std;

#include "../../lookup/SoilLookup.h"
#include "Front.h"
#include "../../util/Exception.h"

class SoilLayer:public Layer{
	public:
	
		/*! the texture class is from ATBeringer52001a*/
	enum STKEY {I_SAND, I_LOAMY_SAND, I_SANDY_LOAM, 
		         I_LOAM, I_SILTY_LOAM, I_SANDY_CLAY_LOAM, I_CLAY_LOAM, 
		         I_SILTY_CLAY_LOAM, I_SANDY_CLAY, I_SILTY_CLAY, I_CLAY};
	
	STKEY stkey; // texture key
    
	virtual ~SoilLayer();
    SoilLayer();
	
    bool tstate ;	/*! thermal state:
		 * -1 : frozen
		 * 0: undetermined, with freezing/thawing front(s)
		 * 1: unfrozen */
    
	double psisat; /*! saturated matric potential*/
    double hksat; /*! saturated matric potential*/
    double bsw; /*! Clap and Hornberger consant*/
    double tcdry; /*! dry matter thermal conductivity W/mK*/
    double tcsolid; /*! solid thermal conductivity W/mK*/
    double vhcsolid; /*! solid volumetric heat capacity*/
    double cfrac; //fraction of carbon
    double nfrac; //fraction of nitrogen
    double tcsatfrz; /*! saturated frozen soil thermal conductivity*/
    double tcsatunf; /*! saturated unfrozen soil thermal conductivity*/
    double albdryvis; //albedo
    double albdrynir;
    double albsatvis;
    double albsatnir;
    double fldcap; //field capacity
    double wltpnt; //wilting point;
    double prtlden; /*! particle density*/
    double rootfrac; /*! fraction of root mass in this layer, relative to total root*/
    double reac; /*! soil carbon pool unit : \f$\frac{kgC}{m^2} \f$ */
    double nonc; //non reactive c
    
    deque<Front*> fronts; //double queue

    void clean();//used to release memory of front
	void updateProperty4LayerChange();
	void updateWater5Front();
    void combineFronts();
    void adjustTem5State();
    void addOneFront5Top(const double & deltaz,const int & frzing);
    void addOneFront5Top4restart(const double & deltaz,const int & frzing);
    void addOneFront5Bot(const double & deltaz,const int & frzing);
    void moveOneFrontDown(const double & partd, const int & fntind);
    void moveOneFrontUp(const double & partd, const int & fntind);
    void removeAllFronts(const int & frzing);
    void removeTopFront();
    void removeBotFront();
    void deriveProperty();
    void checkFronts();
    void adjustFronts();
    
    bool fromFire; // converted from fire
	virtual bool isSnow();
    virtual bool isSoil(); 		
    virtual bool isRock();
    virtual bool isMoss()=0;
    virtual bool isMineral()=0;
    virtual bool isPeat()=0;
 
    double getFrzPoint();
    double getUnfrzColumn();
    double getMatricPotential();
    double getHydraulicCond1();
    double getUnfWatFactor(const double & t);
    double getFrozenFraction();
    double getDryThermCond(const double & tcsolid, const double & bulkden, const double & partden);
    
    virtual double getFrzThermCond(); // get frozen layer thermal conductivity
	virtual double getUnfThermCond(); // get unfrozen layer thermal conductivity
	virtual double getFrzVolHeatCapa(); // get frozen layer specific heat capcity
	virtual double getUnfVolHeatCapa(); // get unfrozen layer specific heat capacity
    virtual double getAlbedoVis(); // get albedo of visible radition
    virtual double getAlbedoNir(); // get albedo of Nir radition
 	
    SoilLookup* soillu;
    
};
#endif /*SOILLAYER_H_*/
