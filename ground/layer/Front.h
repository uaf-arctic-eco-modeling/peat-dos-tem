/*! \file provides freezing or thawing fronts */
#ifndef FRONT_H_
#define FRONT_H_

class Front{
  public:
    Front();
    int frzing; /*! whether is a freezing/thawing front */
    double dz; /*! relative position to a layer */
    //double z; /*! relative position to soil surface */

    void setFrzing(const double & tsur, const double & tf);
	void reset();
	void assign(const Front & of);
	void set(const double &dz, const int& frz);
};
#endif /*FRONT_H_*/
