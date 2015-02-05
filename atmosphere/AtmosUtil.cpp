#include "AtmosUtil.h"

AtmosUtil::AtmosUtil() {

}
;

AtmosUtil::~AtmosUtil() {

}
;

void AtmosUtil::updateDailyPrec(const int yindex, const int mindex,
		float precd[], const int & dinmcurr, const float & mta,
		const float & mprec, const int flag) {
	// input are monthly precipitation, monthly temperature
	// output are daily precpitation
	// this function is based on the code provided Qianlai on Feb. 19, 2007
	float RT, RS, R;
	RT = 1.778;
	RS = 0.635;
	R = 0.5;

	float TEMP, PREC, DURT, DURS;
	PREC = mprec / 10.0 / 2.54; //comvert mm to cm, then to in.
	DURT = RT / R;
	DURS = RS / R;

	float B, T, S, RB, DURB;
	for (int id = 0; id < 32; id++) {
		RAININTE[id] = 0.;
		RAINDUR[id] = 0.;
	}

	TEMP = mta;
	//  Case 1, TEMP<0.
	if (TEMP <= 0.0) {
		if (PREC <= 1.0) {
			B = 1.0;
			T = 0.0;
			S = 1.0;
		} else {
			B = 1.0;
			T = 1.0;
			S = 1.0;
		}

		RB = (PREC * 2.54 - RS * S - RT * T) / B;
		DURB = RB / R;
	}

	//   Case 2, PREC<1.0 inch.
	else if (PREC <= 1.0) {
		B = 1.0;
		T = 0.0;
		S = 1.0;
		RB = (PREC * 2.54 - RS * S - RT * T) / B;
		DURB = RB / R;
	}

	//   Case 3, 1.0<PREC<2.5 inches.
	else if ((2.5 >= PREC) && (PREC > 1.0)) {
		B = 1.0;
		T = 1.0;
		S = 1.0;
		RB = (PREC * 2.54 - RS * S - RT * T) / B;
		DURB = RB / R;
	}

	//   Case 4, 2.5<PREC<4.0 inches.
	else if ((4.0 >= PREC) && (PREC > 2.5)) {
		B = 1.0;
		S = 4.0;
		if (PREC < 3.7)
			T = 1.0;
		else
			T = 2.0;
		RB = (PREC * 2.54 - RS * S - RT * T) / B;
		DURB = RB / R;
	}

	//   Case 5, 4.0<PREC<5.0 inches.
	else if ((5.0 >= PREC) && (PREC > 4.0)) {
		B = 1.0;
		S = 4.0;
		if (PREC < 4.43)
			T = 1.0;
		else
			T = 2.0;
		RB = (PREC * 2.54 - RS * S - RT * T) / B;
		DURB = RB / R;
	}

	//   Case 6, 5.0<PREC<7.0 inches.
	else if ((7.0 >= PREC) && (PREC > 5.0)) {
		B = 2.0;
		S = 4.0;
		if (PREC < 5.65)
			T = 1.0;
		else
			T = 2.0;
		RB = (PREC * 2.54 - RS * S - RT * T) / B;
		DURB = RB / R;
	}

	//   Case 7, 7.0<PREC<9.0 inches.
	else if ((9.0 >= PREC) && (PREC > 7.0)) {
		B = 2.0;
		S = 6.0;
		if (PREC < 8.21)
			T = 3.0;
		else
			T = 4.0;
		RB = (PREC * 2.54 - RS * S - RT * T) / B;
		DURB = RB / R;
	}

	//   Case 8, 9.0<PREC<11.0 inches.
	else if ((11.0 >= PREC) && (PREC > 9.0)) {
		B = 3.0;
		S = 6.0;
		if (PREC < 10.0)
			T = 4.0;
		else
			T = 5.0;
		RB = (PREC * 2.54 - RS * S - RT * T) / B;
		DURB = RB / R;
	}

	//   Case 9, PREC>11.0 inches.
	else if (PREC > 11.0) {
		B = 4.0;
		S = 7.0;
		if (PREC < 13.0)
			T = 4.0;
		else
			T = 5.0;
		RB = (PREC * 2.54 - RS * S - RT * T) / B;
		DURB = RB / R;
	}

	if (DURB < 0.0)
		DURB = 0.01; // !added //changed from zero to 0.01 by shuhua
	PREC = PREC * 2.54 * 10.0; // convert back to cm, and then to mm

	float BB, TT;
	int KTT, KDD, KTD, KKTD;
	int NN, DT;

	DT = dinmcurr;

	KTT = (int) (B + T);
	KTD = DT / KTT;
	KDD = DT - KTT * KTD;
	BB = B;
	TT = T;
	NN = 0;
	for (int JJ = 1; JJ <= KTT; JJ++) {
		if (BB > 0.0) {
			BB = BB - 1.0;
			for (int L = 1; L <= KTD; L++) {
				NN = NN + 1;
				RAININTE[NN] = 0.0;
				RAINDUR[NN] = 0.0;
				if (L == KTD) {
					RAININTE[NN] = 5.0; // unit with mm /hr
					RAINDUR[NN] = DURB;
				}
			}
		}

		if (TT > 0.0) {
			TT = TT - 1.0;
			if (JJ == 1)
				KKTD = KTD + KDD;
			else
				KKTD = KTD;
			for (int L = 1; L <= KKTD; L++) {
				NN = NN + 1;
				RAININTE[NN] = 0.0;
				RAINDUR[NN] = 0.0;
				if (L == KKTD) {
					RAININTE[NN] = 5.0; //unit mm/hr
					RAINDUR[NN] = DURT;
				}
			}
		}

	} // end of for J

	// in winter season, DURT was always zero, so put the precipitation on the day with RAININTE>0;

	int numprec = 0;
	double tothour = 0.;
	for (int id = 0; id < dinmcurr; id++) {
		if (RAINDUR[id + 1] > 0) {
			numprec++;
			tothour += RAINDUR[id + 1];
		}
	}

	float sumprec = 0.;
	if (numprec > 0) {
		double rainrate = mprec / tothour;

		for (int id = 0; id < dinmcurr; id++) {

#ifdef M_PRECIP
			if (flag == 1 && yindex == 104) {
				if (mindex == 4)
					precd[id] = prec20055[id];
				else if (mindex == 5)
					precd[id] = prec20056[id];
				else if (mindex == 6)
					precd[id] = prec20057[id];
				else if (mindex == 7)
					precd[id] = prec20058[id];
				else
					precd[id] = RAINDUR[id + 1] * rainrate;
			} else if (flag == 1 && yindex == 105) {
				if (mindex == 4)
					precd[id] = prec20065[id];
				else if (mindex == 5)
					precd[id] = prec20066[id];
				else if (mindex == 6)
					precd[id] = prec20067[id];
				else if (mindex == 7)
					precd[id] = prec20068[id];
				else
					precd[id] = RAINDUR[id + 1] * rainrate;
			} else if (flag == 1 && yindex == 106) {
				if (mindex == 5)
					precd[id] = prec20076[id];
				else if (mindex == 6)
					precd[id] = prec20077[id];
				else if (mindex == 7)
					precd[id] = prec20078[id];
				else if (mindex == 8)
					precd[id] = prec20079[id];
				else
					precd[id] = RAINDUR[id + 1] * rainrate;
			} else if (flag == 1 && yindex == 107) {
				if (mindex == 4)
					precd[id] = prec20085[id];
				else if (mindex == 5)
					precd[id] = prec20086[id];
				else if (mindex == 6)
					precd[id] = prec20087[id];
				else if (mindex == 7)
					precd[id] = prec20088[id];
				else
					precd[id] = RAINDUR[id + 1] * rainrate;
			}  else if (flag == 1 && yindex == 108) {
				if (mindex == 4)
					precd[id] = prec20095[id];
				else if (mindex == 5)
					precd[id] = prec20096[id];
				else if (mindex == 6)
					precd[id] = prec20097[id];
				else if (mindex == 7)
					precd[id] = prec20098[id];
				else
					precd[id] = RAINDUR[id + 1] * rainrate;
			}  else if (flag == 1 && yindex == 109) {
				if (mindex == 4)
					precd[id] = prec20105[id];
				else if (mindex == 5)
					precd[id] = prec20106[id];
				else if (mindex == 6)
					precd[id] = prec20107[id];
				else if (mindex == 7)
					precd[id] = prec20108[id];
				else
					precd[id] = RAINDUR[id + 1] * rainrate;
			}  else if (flag == 1 && yindex == 110) {
				if (mindex == 4)
					precd[id] = prec20115[id];
				else if (mindex == 5)
					precd[id] = prec20116[id];
				else if (mindex == 6)
					precd[id] = prec20117[id];
				else if (mindex == 7)
					precd[id] = prec20118[id];
				else
					precd[id] = RAINDUR[id + 1] * rainrate;
			}else {
				precd[id] = RAINDUR[id + 1] * rainrate;
			}
#endif
#ifndef M_PRECIP
			precd[id] = RAINDUR[id + 1] * rainrate;
#endif
			sumprec += precd[id];
		}

	}

}

void AtmosUtil::updateDailyDriver(float tad[], const float prevta,
		const float curta, const float nextta, const int & dinmprev,
		const int & dinmcurr, const int & dinmnext) {

	int hdamx = dinmprev + 2 * dinmcurr + dinmnext;
	float temp[hdamx], timind[hdamx];//, stemp[hdamx];
	float dtday = 0.5;
	int months = 3;
	float tamon[months], timmon[months];//, sfmon[months];

	tamon[0] = prevta;
	tamon[1] = curta;
	tamon[2] = nextta;

	timmon[0] = dtday;
	timmon[1] = dtday * (dinmprev + dinmcurr);
	timmon[2] = dtday * hdamx;
	for (int ihd = 0; ihd < hdamx; ihd++) {
		timind[ihd] = (ihd + 1) * dtday;
	}

	itp.interpolate(timmon, tamon, months, timind, temp, hdamx);
	for (int ihd = 0; ihd < dinmcurr; ihd++) {
		tad[ihd] = (temp[2 * ihd + dinmprev] + temp[2 * ihd + 1 + dinmprev])
				/ 2.;
	}

}
;
