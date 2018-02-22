#ifndef SOIL_ENV_H_
#define SOIL_ENV_H_

#include "Stefan.h"  
#include "Richard.h"
#include "Bucket.h"  //Y.Mi

#include "../data/EnvData.h"
#include "../data/FirData.h"
#include "../data/RestartData.h"

#include "layer/Layer.h"
#include "layer/SoilLayer.h"
#include "layer/PeatLayer.h"

#include "../inc/parameters.h"
#include "../lookup/CohortLookup.h"
#include "../inc/layerconst.h"

#include "Moss.h"
#include "Peat.h"
#include "Mineral.h"
#include "../inc/ErrorCode.h"
#include "../util/Exception.h"

#ifdef FEN
#ifdef CONTROL

#define WTDATA
//#undef WTDATA

const double wtb2011[111] = {0.63994,1.08,1.7423,2.611,3.197,3.9666,3.2654,3.9645,4.5216,4.575,2.8527,2.2332,1.8681,1.9686,1.8078,2.35,3.0866,3.0979,3.6408,3.8812,4.4102,5.059,5.1079,3.6781,3.6982,2.107,1.5963,1.3158,1.768,1.7617,1.5522,1.2411,1.5474,2.1357,2.8176,2.8125,1.9271,2.8204,3.4085,3.8247,4.2053,4.6838,5.2524,3.6712,3.8157,3.8281,4.5981,5.1131,5.6708,6.1042,6.4197,6.9071,7.152,7.0637,5.1923,5.5279,5.972,5.2263,5.0908,5.6303,6.1706,6.4345,6.9594,7.7947,8.2409,8.1238,8.1535,7.997,8.3242,8.5476,8.3362,6.7782,6.2703,6.637,7.1771,7.5508,7.4727,7.6354,7.4684,3.8291,2.728,2.569,2.9141,3.183,3.6511,4.0605,4.4451,4.802,5.1892,5.2012,4.7749,4.5661,4.7684,4.9437,5.2443,5.6465,6.0275,6.3264,6.2264,4.8867,3.9392,3.7968,3.9041,3.9918,4.1494,4.0865,4.1195,4.1832,4.4255,4.6173,4.5815};

const double wtb2012[109] = {-3.87,-3.6792,-3.1042,-2.7792,-2.3687,-1.8208,-1.3583,-0.96042,-0.49583,0.025,0.39792,0.81458,0.95417,1.6583,0.3625,-0.61042,-0.18125,0.32083,0.86458,1.4479,1.8938,1.85,2.2563,2.8542,3.3875,3.8,3.5667,4.225,4.4396,4.9188,5.25,5.8063,6.0479,6.2667,5.3729,5.5875,5.7687,4.5958,3.4562,3.2667,3.0146,3.3042,3.2792,3.6958,4.0667,4.5146,4.7083,4.9521,4.5833,3.6896,3.1792,3.1625,3.1437,3.0854,3.2417,3.4312,3.2188,3.075,2.9688,2.9396,2.9937,3.0438,3.0479,2.7083,2.3042,2.3792,2.0708,2.0708,2.4937,2.3292,2.0417,1.8188,1.725,1.675,1.0917,-0.63125,-3.3917,-3.75,-4.0958,-4.1604,-4.9562,-5.9417,-5.9792,-5.8438,-5.8875,-5.9042,-6.2313,-6.3708,-6.4354,-6.2875,-6.2146,-5.9375,-5.9,-5.8583,-5.6771,-5.5771,-5.4021,-5.3208,-5.4188,-5.3979,-5.4229,-5.9917,-6.2958,-6.4958,-6.9896,-7.1604,-7.1104,-7.0542,-7.2217};


const double wtb2013[86] = {2.863,3.1125,3.4854,3.8729,4.2896,4.7708,5.2625,5.7083,6.3375,6.8771,7.4521,7.8083,8.1021,8.6,9.1958,9.8354,10.481,10.958,11.458,11.921,12.2,12.621,13.156,13.929,14.183,14.613,14.8,15.079,15.125,15.502,14.8,15.185,15.646,16.14,16.49,17.231,17.331,17.731,17.467,15.217,15.298,15.952,16.479,16.967,17.202,17.635,18.41,18.906,19.281,19.879,20.3,20.654,21.038,21.344,21.467,21.994,22.227,22.921,23.19,23.688,23.981,24.367,24.775,25.404,25.938,26.144,26.09,25.223,25.433,25.892,26.273,24.448,23.742,23.91,20.483,19.192,19.204,19.592,20.019,20.146,20.004,19.848,19.973,19.952,18.798,18.317};


#endif
#endif


class Soil_Env {
public:
	Soil_Env();
	~Soil_Env();

	/*! the thickness of soil column , which is from the the top
	 * of moss layer, if exists, to the bottom of last mineral layer.(unit: m)*/
	double dztot;
	/*! number of soil layers */
	int num;
	double initem[MAX_SOI_LAY];
	double inivwc[MAX_SOI_LAY];

	/*! reset diagnostic variables to initial values */
	void resetDiagnostic();

	Moss moss;
	Peat peat;
	Mineral mineral;
    
    Bucket bucket; //Y.Mi

	Richard richard;
	Stefan stefan;

	void setEnvData(EnvData* edp);
	void setFirData(FirData* fdp);
	void setCohortLookup(CohortLookup * chtlup);

	void updateDailySurfFlux(Layer* frontl, const double & tsurf,
			const double & dayl);

	double getWaterTable(Layer* fstsoil, const int year, const int doy);

	void initializeParameter(const int &drgtypep, const int &vegtypep);
	void initializeState(Layer* fstsoill);
	void initializeState5restart(Layer* fstsoill, RestartData* resin);

	double infilFrozen2(Layer* fstsoill, Layer *fstminl, const double & rnth,
			const double & melt);

	double infilFrozen(Layer* fstminl, const double & infilf);

	double getDrainage(const double & wtable);
	double getRunoff(Layer* fstsoill, const double & rnth, const double & melt,
			const double & frasat);
	double update5Drainage(Layer* drainl, const double & fracsat,
			const double & wtd);

	double getSoilTransFactor(Layer* fstsoill);

	double update5BaseFlow(Layer* drainl);

	double getBaseFlow(double const & wetness);

	double getRunoffVIC(Layer* fstsoill, const double & rnth,
			const double & melt);

	///////////////////
	void layer2structdaily(Layer* fstsoill);
	void layer2structmonthly(Layer* fstsoill);
	void retrieveDailyOutputs(Layer* fstsoill, Layer* fstminl, Layer* lstminl,
			Layer* backl);
	void retrieveDailyFronts(Layer* fstsoill);
	void retrieveThawPercent(Layer* fstsoill);

	//////////////////////

	void resetFineRootFrac(Layer* fstsoill);
	void resetTypeDZ(Layer* fstsoill);
	soipar_env envpar;

	double getFracSat(const double & wtd);

private:

	double getEvaporation(const double & tsurf, const double & dayl,
			const double &rad);

	double getPenMonET(const double & ta, const double& vpd,
			const double &irad, const double &rv, const double & rh);
	double updateLayerTemp5Lat(Layer* currl, const double & infil);

	double getFineRootFrac(const double & layertop, const double & layerbot,
			const double & mossthick);

	EnvData * ed;
	FirData * fd;

	CohortLookup* chtlu;

	void initTempMois(Layer* frontl);
	void initRootMass(Layer* fstsoill);
};

#endif /*SOIL_ENV_H_*/
