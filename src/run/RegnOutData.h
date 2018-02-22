#ifndef REGNOUTDATA_H_
#define REGNOUTDATA_H_
/* 
 * define output variables for regional TEM run
 * memory consumption too much, so modified as output year by year
 *  rather than cohort by cohort - Yuan
 */

class RegnOutData{
	
	public:
   
		RegnOutData();
		~RegnOutData();
	 	int chtid;
	 
	  	int status;
	 	float yrrm;
	 	float yrrh;
	 	float yrrg;
	 	float yrburnsoic;
	 	float yrburnvegc;
	 
     	float yrnpp;
	 	float yrgpp;
	 	float yrysf;
	 
	  	float yrvegc;
	  	float yrminc;
	  	float yrshlwc;
	  	float yrdeepc;
	  
	  	float yrorgn;
    	float yravln;
    	float yrvegn;
    
    	float yrlai ;
    	float yrnetnmin;
    	float yrnuptake;
    	float yrltrfaln;
    	float yrltrfalc;
    
    	float yreet ;
    	float yrpet ;
    	float yrwtd;
    	float yrch4flux;
    	float yrhco2flux;
    	float yraco2flux;
    	float yrdfratio;
    	float yrco2ch4;
    	float yroxid;
    	float yrald;
		float yrperm;
		float yrgrowstart;
		float yrgrowend;
	 
		float yrvwcshlw;
		float yrvwcdeep;
		float yrvwcmine;
		float yrvwcmin10;

		float yrtshlw;
		float yrtdeep;
		float yrtmine;
    	float yrtmin10;
		float yrtrock34;
		float yrunfrzcolumn;

    	float yrmossdz;
		float yrshlwdz;
		float yrdeepdz;
	
		float yrninput;
		float yrnlost;
		float yrqdrain;
		float yrqrunoff;

		float yrburnthick;
	 
};

#endif /*REGNOUTDATA_H_*/
