/*! \file
 * Superclass for SoilLayer and SnowLayer
 */
#ifndef LAYER_H_
#define LAYER_H_

#include<string>
#include <iostream>
//#include "../inoutput/Logger.h"
#include <sstream>
#include <cmath>
#include <vector>
using namespace std;

#include "../../inc/PhysicalConstants.h"

class Layer {
	public:
    
    Layer();
    
	int indl; /*! layer index, start from 1 */
    int solind; /*! soil layer index, start from 1*/
    int frozen; /*! thermal state of soil, 0: undetermined, 1: frozen, -1: unfrozen*/
    int color;  /* color of layer*/
    
    double dz; /*! thickness of layer (unit : \f$ m \f$)*/
    double z; /*! distance to the ground surface
	  * <ol>
	  * <li>+ means below surface, for soil layer
	  * <li>- means above surface, for snow layer
	  * </ol>
	  */
    double rho; /*! density of this layer (unit : \f$ kg m^{-3} \f$)*/
    double age; /*! age of a layer (year)*/
    double minliq; // minimum liq water content//kg/m2
    double maxliq; // maximum liq water content
    double maxice; // maximum ice content
    double tcmin; // minimum thermal conductivity, to consider the effect of air and water convection
    double tem; /// variables
	/*! temperature, Note: here the temperature of one layer
	 * means the temperature at the bottom of one layer.
	 * This definition is for Goodrich method */
	double ch4;
    double liq; /*!liquid water kg/m2*/
	double ice; /*!ice content kg/m2*/
	double wat; /*! total water conent*/
	double poro; /*! porosity*/
	double bulkden; /*! bulk density: the kg solid/ volume of whole layer*/
    double dbdw; /*!bulk density /density of water*/
    //double mass; //the mass of a layer
    
    Layer* nextl; /*! point to next layer */
	Layer* prevl; /*! point to previous layer */
	
    virtual ~Layer();
    virtual bool isSnow()=0;
    virtual bool isSoil()=0;
    virtual bool isRock()=0;
    // virtual void updateDensity()=0;
    
    enum typekey {I_LAY, I_SOIL, I_SNOW, I_MOSS, I_PEAT, I_MINE, I_ROCK};
    typekey tkey; /*! the name of class for the distinction between moss, peat and mineral soil layer*/
    
    void check();
    void advanceOneDay();
    void addOneMoreFront(const double & deltaz,const int & frzing);
    void addOneMoreFront5Bot(const double & deltaz,const int & frzing);
    void removeAllFronts(const int & frzing);
    void moveFrontDown(const double & partd, const int & fntind);
    void moveFrontUp(const double & partd, const int & fntind);
    void printFrontsInfo();
    void updateNumberOfFronts(int & numfrz, int & numthw);
	//void logLayerInfo(Logger * logger);
    
    int checkFrontsValidity();
    
    double getHeatCapacity();
    double getThermalConductivity();
    double getVolWater(); /*!get volumetric soil water content*/
	double getVolLiq();
	double getVolIce();
	double getEffVolWater();
   	
	virtual double getFrzThermCond()=0; // get frozen layer thermal conductivity
	virtual double getUnfThermCond()=0; // get unfrozen layer thermal conductivity
	virtual double getFrzVolHeatCapa()=0; // get frozen layer specific heat capcity
	virtual double getUnfVolHeatCapa()=0; // get unfrozen layer specific heat capacity
    virtual double getAlbedoVis()=0; // get albedo of visible radition
    virtual double getAlbedoNir()=0; // get albedo of Nir radition
};
#endif /*LAYER_H_*/
