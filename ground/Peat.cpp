#include "Peat.h"

Peat::Peat() {

}

Peat::~Peat() {

}

bool Peat::sameShlwThickRange(const double & thickness) {

	/// if the thickness and shlwthick not in the same range, there is a need to reconstruct peat layers
	bool same = false;
	if (shlwnum == 2) {
		if (shlwdza[0] > shlwdza[1]) {
			same = false;
			return same;
		}

	} else if (shlwnum == 3) {
		if (shlwdza[0] > shlwdza[1] || shlwdza[0] > shlwdza[2] || shlwdza[1]
				> shlwdza[2]) {
			same = false;
			return same;
		}
	}

	if (thickness < 0.02 && shlwthick < 0.02) {
		return true;
	} else if (thickness < 0.04 && thickness >= 0.01 && shlwthick < 0.04
			&& shlwthick >= 0.02) {
		return true;
	} else if (thickness < 0.06 && thickness >= 0.04 && shlwthick < 0.06
			&& shlwthick >= 0.04) {
		return true;
	} else if (thickness < 0.10 && thickness >= 0.06 && shlwthick < 0.10
			&& shlwthick >= 0.06) {
		return true;
	} else if (thickness < 0.15 && thickness >= 0.10 && shlwthick < 0.15
			&& shlwthick >= 0.10) {
		return true;
	} else if (thickness < 0.20 && thickness >= 0.15 && shlwthick < 0.20
			&& shlwthick >= 0.15) {
		return true;

	} else if (thickness < 0.28 && thickness >= 0.20 && deepthick < 0.28
			&& deepthick >= 0.20) {
		return true;
	} else if (thickness < 0.40 && thickness >= 0.28 && deepthick < 0.40
			&& deepthick >= 0.28) {
		return true;
	} else if (thickness >= 0.4 && deepthick >= 0.4) {
		return true;
	}

	return same;
}

bool Peat::sameDeepThickRange(const double & thickness) {
	/// if the thickness and deepthick not in the same range, there is a need to reconstruct peat layers
	bool same = false;

	if (shlwchanged) {
		same = false;
		return same;
	}

	int newdeepnum = 0;

	if (thickness <= dlstshlw)
		newdeepnum = 1;
	else if (thickness > dlstshlw && thickness <= 2 * dlstshlw)
		newdeepnum = 2;
	else if (thickness > 2 * dlstshlw && thickness <= 3 * dlstshlw)
		newdeepnum = 3;
	else if (thickness > 3 * dlstshlw && thickness <= 4 * dlstshlw)
		newdeepnum = 4;
	else if (thickness > 4 * dlstshlw && thickness <= 5 * dlstshlw)
		newdeepnum = 5;
	else if (thickness > 5 * dlstshlw && thickness <= 6 * dlstshlw)
		newdeepnum = 6;
	else if (thickness > 6 * dlstshlw && thickness <= 7 * dlstshlw)
		newdeepnum = 7;
	else if (thickness > 7 * dlstshlw && thickness <= 8 * dlstshlw)
		newdeepnum = 8;
	else if (thickness > 8 * dlstshlw && thickness <= 9 * dlstshlw)
		newdeepnum = 9;
    else if (thickness > 9 * dlstshlw && thickness <= 10 * dlstshlw) //Y.Mi
        newdeepnum = 10;
    else if (thickness > 10 * dlstshlw && thickness <= 11 * dlstshlw)
        newdeepnum = 11;
    else if (thickness > 11 * dlstshlw && thickness <= 12 * dlstshlw)
        newdeepnum = 12;
    else if (thickness > 12 * dlstshlw && thickness <= 13 * dlstshlw)
        newdeepnum = 13;
    else if (thickness > 13 * dlstshlw && thickness <= 14 * dlstshlw)
        newdeepnum = 14;
	else
		newdeepnum = 15;

	/*
	 if (thickness < 3 * dlstshlw) {

	 newdeepnum = 1;
	 } else if (thickness >= 3 * dlstshlw && thickness < 6 * dlstshlw) {

	 newdeepnum = 2;
	 } else {

	 newdeepnum = 3;

	 }
	 */
	if (newdeepnum == deepnum) {
		same = true;
	}

	return same;
}

void Peat::initShlwThicknesses(const double & thickness) {

	oldshlwthick = shlwthick;
	if (shlwnum > 0)
		olddlstshlw = shlwdza[shlwnum - 1]; //Yuan:???
	shlwthick = thickness;

//	if (thickness < 0.02)
//		shlwthick = 0.02;
//	shlwnum = 0;
//	if (thickness < 0.00) { //Yuan: always allow at least ONE shlwnum
//		shlwdza[0] = -1;
//		shlwdza[1] = -1;
//		shlwdza[2] = -1;
//		shlwnum = 0;
//	} else if (thickness < 0.04) {
//		shlwdza[0] = thickness;
//		shlwdza[1] = -1;
//		shlwdza[2] = -1;
//		shlwnum = 1;
//	} else if (thickness < 0.06) {
//		shlwdza[0] = 0.02;
//		shlwdza[1] = thickness - 0.02;
//		shlwdza[2] = -1;
//		shlwnum = 2;
//	} else if (thickness < 0.10) {
//		shlwdza[0] = 0.03;
//		shlwdza[1] = thickness - 0.03;
//		shlwdza[2] = -1;
//		shlwnum = 2;
//	} else if (thickness < 0.15) {
//		shlwdza[0] = 0.02;
//		shlwdza[1] = 0.04;
//		shlwdza[2] = thickness - 0.06;
//		shlwnum = 3;
//	} else if (thickness < 0.20) {
//		shlwdza[0] = 0.03;
//		shlwdza[1] = 0.06;
//		shlwdza[2] = thickness - 0.09;
//		shlwnum = 3;
//	} else if (thickness < 0.28) {
//		shlwdza[0] = 0.04;
//		shlwdza[1] = 0.08;
//		shlwdza[2] = thickness - 0.12;
//		shlwnum = 3;
//	} else if (thickness < 0.40) {
//		shlwdza[0] = 0.05;
//		shlwdza[1] = 0.11;
//		shlwdza[2] = thickness - 0.16;
//		shlwnum = 3;
//	} else if (thickness >= 0.4) {
//
//		shlwdza[0] = 0.1;
//		shlwdza[1] = 0.2;
//		shlwdza[2] = thickness - 0.3;
//		shlwnum = 3;

    if (thickness < 0.03)
        shlwthick = 0.03;
   
    shlwnum = 1;
    
    if (thickness == 0.03) { //Yuan: always allow at least ONE shlwnum
        shlwdza[0] = 0.03;
        shlwdza[1] = -1;
        shlwdza[2] = -1;
        shlwnum = 1;
    } else if (thickness <= 0.06) {
        shlwdza[0] = 0.03;
        shlwdza[1] = thickness-0.03;
        shlwdza[2] = -1;
        shlwnum = 2;
    } else if (thickness <= 0.09) {
        shlwdza[0] = 0.03;
        shlwdza[1] = 0.03;
        shlwdza[2] = thickness-0.06;
        shlwnum = 3;
    } else if (thickness <= 0.12) {
        shlwdza[0] = 0.03;
        shlwdza[1] = 0.03;
        shlwdza[2] = 0.03;
        shlwdza[3] = thickness-0.09;
        shlwnum = 4;
    } else if (thickness <= 0.15) {
        shlwdza[0] = 0.03;
        shlwdza[1] = 0.03;
        shlwdza[2] = 0.03;
        shlwdza[3] = 0.03;
        shlwdza[4] = thickness-0.12;
        shlwnum = 5;
    } else if (thickness <= 0.18) {
        shlwdza[0] = 0.03;
        shlwdza[1] = 0.03;
        shlwdza[2] = 0.03;
        shlwdza[3] = 0.03;
        shlwdza[4] = 0.03;
        shlwdza[5] = thickness-0.15;
        shlwnum = 6;
    } else if (thickness <= 0.21) {
        shlwdza[0] = 0.03;
        shlwdza[1] = 0.03;
        shlwdza[2] = 0.03;
        shlwdza[3] = 0.03;
        shlwdza[4] = 0.03;
        shlwdza[5] = 0.03;
        shlwdza[6] = thickness-0.18;
        shlwnum = 7;
    } else if (thickness <= 0.24) {
        shlwdza[0] = 0.03;
        shlwdza[1] = 0.03;
        shlwdza[2] = 0.03;
        shlwdza[3] = 0.03;
        shlwdza[4] = 0.03;
        shlwdza[5] = 0.03;
        shlwdza[6] = 0.03;
        shlwdza[7] = thickness-0.21;
        shlwnum = 8;
    } else if (thickness <= 0.27) {
        shlwdza[0] = 0.03;
        shlwdza[1] = 0.03;
        shlwdza[2] = 0.03;
        shlwdza[3] = 0.03;
        shlwdza[4] = 0.03;
        shlwdza[5] = 0.03;
        shlwdza[6] = 0.03;
        shlwdza[7] = 0.03;
        shlwdza[8] = thickness-0.24;
        shlwnum = 9;
    } else if (thickness <= 0.30) {
        shlwdza[0] = 0.03;
        shlwdza[1] = 0.03;
        shlwdza[2] = 0.03;
        shlwdza[3] = 0.03;
        shlwdza[4] = 0.03;
        shlwdza[5] = 0.03;
        shlwdza[6] = 0.03;
        shlwdza[7] = 0.03;
        shlwdza[8] = 0.03;
        shlwdza[9] = thickness-0.27;
        shlwnum = 10;
    } else {
        shlwdza[0] = 0.03;
        shlwdza[1] = 0.03;
        shlwdza[2] = 0.03;
        shlwdza[3] = 0.03;
        shlwdza[4] = 0.03;
        shlwdza[5] = 0.03;
        shlwdza[6] = 0.03;
        shlwdza[7] = 0.03;
        shlwdza[8] = 0.03;
        shlwdza[9] = 0.03;
        shlwdza[10] = thickness-0.30;
        shlwnum = 11;
    }
    
//    else if (thickness <= 0.24) {
//        shlwdza[0] = 0.02;
//        shlwdza[1] = 0.02;
//        shlwdza[2] = 0.02;
//        shlwdza[3] = 0.02;
//        shlwdza[4] = 0.02;
//        shlwdza[5] = 0.02;
//        shlwdza[6] = 0.02;
//        shlwdza[7] = 0.02;
//        shlwdza[8] = 0.02;
//        shlwdza[9] = 0.02;
//        shlwdza[10] = 0.02;
//        shlwdza[11] = thickness-0.22;
//        shlwnum = 12;
//    } else if (thickness <= 0.26) {
//        shlwdza[0] = 0.02;
//        shlwdza[1] = 0.02;
//        shlwdza[2] = 0.02;
//        shlwdza[3] = 0.02;
//        shlwdza[4] = 0.02;
//        shlwdza[5] = 0.02;
//        shlwdza[6] = 0.02;
//        shlwdza[7] = 0.02;
//        shlwdza[8] = 0.02;
//        shlwdza[9] = 0.02;
//        shlwdza[10] = 0.02;
//        shlwdza[11] = 0.02;
//        shlwdza[12] = thickness-0.24;
//        shlwnum = 13;
//    } else if (thickness <= 0.28) {
//        shlwdza[0] = 0.02;
//        shlwdza[1] = 0.02;
//        shlwdza[2] = 0.02;
//        shlwdza[3] = 0.02;
//        shlwdza[4] = 0.02;
//        shlwdza[5] = 0.02;
//        shlwdza[6] = 0.02;
//        shlwdza[7] = 0.02;
//        shlwdza[8] = 0.02;
//        shlwdza[9] = 0.02;
//        shlwdza[10] = 0.02;
//        shlwdza[11] = 0.02;
//        shlwdza[12] = 0.02;
//        shlwdza[13] = thickness-0.26;
//        shlwnum = 14;
//    }  else if (thickness <= 0.30) {
//        shlwdza[0] = 0.02;
//        shlwdza[1] = 0.02;
//        shlwdza[2] = 0.02;
//        shlwdza[3] = 0.02;
//        shlwdza[4] = 0.02;
//        shlwdza[5] = 0.02;
//        shlwdza[6] = 0.02;
//        shlwdza[7] = 0.02;
//        shlwdza[8] = 0.02;
//        shlwdza[9] = 0.02;
//        shlwdza[10] = 0.02;
//        shlwdza[11] = 0.02;
//        shlwdza[12] = 0.02;
//        shlwdza[13] = 0.02;
//        shlwdza[14] = thickness-0.28;
//        shlwnum = 15;
//    } else if (thickness <= 0.32) {
//        shlwdza[0] = 0.02;
//        shlwdza[1] = 0.02;
//        shlwdza[2] = 0.02;
//        shlwdza[3] = 0.02;
//        shlwdza[4] = 0.02;
//        shlwdza[5] = 0.02;
//        shlwdza[6] = 0.02;
//        shlwdza[7] = 0.02;
//        shlwdza[8] = 0.02;
//        shlwdza[9] = 0.02;
//        shlwdza[10] = 0.02;
//        shlwdza[11] = 0.02;
//        shlwdza[12] = 0.02;
//        shlwdza[13] = 0.02;
//        shlwdza[14] = 0.02;
//        shlwdza[15] = thickness-0.30;
//        shlwnum = 16;
//    } else if (thickness <= 0.34) {
//        shlwdza[0] = 0.02;
//        shlwdza[1] = 0.02;
//        shlwdza[2] = 0.02;
//        shlwdza[3] = 0.02;
//        shlwdza[4] = 0.02;
//        shlwdza[5] = 0.02;
//        shlwdza[6] = 0.02;
//        shlwdza[7] = 0.02;
//        shlwdza[8] = 0.02;
//        shlwdza[9] = 0.02;
//        shlwdza[10] = 0.02;
//        shlwdza[11] = 0.02;
//        shlwdza[12] = 0.02;
//        shlwdza[13] = 0.02;
//        shlwdza[14] = 0.02;
//        shlwdza[15] = 0.02;
//        shlwdza[16] = thickness-0.32;
//        shlwnum = 17;
//    } else if (thickness <= 0.36) {
//        shlwdza[0] = 0.02;
//        shlwdza[1] = 0.02;
//        shlwdza[2] = 0.02;
//        shlwdza[3] = 0.02;
//        shlwdza[4] = 0.02;
//        shlwdza[5] = 0.02;
//        shlwdza[6] = 0.02;
//        shlwdza[7] = 0.02;
//        shlwdza[8] = 0.02;
//        shlwdza[9] = 0.02;
//        shlwdza[10] = 0.02;
//        shlwdza[11] = 0.02;
//        shlwdza[12] = 0.02;
//        shlwdza[13] = 0.02;
//        shlwdza[14] = 0.02;
//        shlwdza[15] = 0.02;
//        shlwdza[16] = 0.02;
//        shlwdza[17] = thickness-0.34;
//        shlwnum = 18;
//    } else if (thickness <= 0.38) {
//        shlwdza[0] = 0.02;
//        shlwdza[1] = 0.02;
//        shlwdza[2] = 0.02;
//        shlwdza[3] = 0.02;
//        shlwdza[4] = 0.02;
//        shlwdza[5] = 0.02;
//        shlwdza[6] = 0.02;
//        shlwdza[7] = 0.02;
//        shlwdza[8] = 0.02;
//        shlwdza[9] = 0.02;
//        shlwdza[10] = 0.02;
//        shlwdza[11] = 0.02;
//        shlwdza[12] = 0.02;
//        shlwdza[13] = 0.02;
//        shlwdza[14] = 0.02;
//        shlwdza[15] = 0.02;
//        shlwdza[16] = 0.02;
//        shlwdza[17] = 0.02;
//        shlwdza[18] = thickness-0.36;
//        shlwnum = 19;
//    } else if (thickness <= 0.40) {
//        shlwdza[0] = 0.02;
//        shlwdza[1] = 0.02;
//        shlwdza[2] = 0.02;
//        shlwdza[3] = 0.02;
//        shlwdza[4] = 0.02;
//        shlwdza[5] = 0.02;
//        shlwdza[6] = 0.02;
//        shlwdza[7] = 0.02;
//        shlwdza[8] = 0.02;
//        shlwdza[9] = 0.02;
//        shlwdza[10] = 0.02;
//        shlwdza[11] = 0.02;
//        shlwdza[12] = 0.02;
//        shlwdza[13] = 0.02;
//        shlwdza[14] = 0.02;
//        shlwdza[15] = 0.02;
//        shlwdza[16] = 0.02;
//        shlwdza[17] = 0.02;
//        shlwdza[18] = 0.02;
//        shlwdza[19] = thickness-0.38;
//        shlwnum = 20;
//    
//    } else if (thickness > 0.4) {
//        
//        shlwdza[0] = 0.02;
//        shlwdza[1] = 0.02;
//        shlwdza[2] = 0.02;
//        shlwdza[3] = 0.02;
//        shlwdza[4] = 0.02;
//        shlwdza[5] = 0.02;
//        shlwdza[6] = 0.02;
//        shlwdza[7] = 0.02;
//        shlwdza[8] = 0.02;
//        shlwdza[9] = 0.02;
//        shlwdza[10] = 0.02;
//        shlwdza[11] = 0.02;
//        shlwdza[12] = 0.02;
//        shlwdza[13] = 0.02;
//        shlwdza[14] = 0.02;
//        shlwdza[15] = 0.02;
//        shlwdza[16] = 0.02;
//        shlwdza[17] = 0.02;
//        shlwdza[18] = 0.02;
//        shlwdza[19] = thickness-0.38;
//        shlwnum = 20;
//        
//	}
	shlwthick = thickness;
	dlstshlw = shlwdza[shlwnum - 1];
}

void Peat::initDeepThicknesses(const double & thickness) {
	olddeepthick = deepthick;

	deepthick = thickness;
	if (thickness < 0.0)
		deepthick = 0.0;

	deepnum = 0;

	if (dlstshlw > 0) {
		if (deepthick <= dlstshlw) {
			deepdza[0] = deepthick;
			deepdza[1] = -1;
			deepdza[2] = -1;
			deepdza[3] = -1;
			deepdza[4] = -1;
			deepdza[5] = -1;
			deepdza[6] = -1;
			deepdza[7] = -1;
			deepdza[8] = -1;
			deepdza[9] = -1;
            deepdza[10] = -1;
            deepdza[11] = -1;
            deepdza[12] = -1;
            deepdza[13] = -1;
            deepdza[14] = -1;

			deepnum = 1;
		} else if (deepthick > dlstshlw && deepthick <= 2 * dlstshlw) {
			deepdza[0] = 1. / 3. * deepthick;
			deepdza[1] = 2. / 3. * deepthick;
			deepdza[2] = -1;
			deepdza[3] = -1;
			deepdza[4] = -1;
			deepdza[5] = -1;
			deepdza[6] = -1;
			deepdza[7] = -1;
			deepdza[8] = -1;
			deepdza[9] = -1;
            deepdza[10] = -1;
            deepdza[11] = -1;
            deepdza[12] = -1;
            deepdza[13] = -1;
            deepdza[14] = -1;

			deepnum = 2;
		} else if (deepthick > 2 * dlstshlw && deepthick <= 3 * dlstshlw) {
			deepdza[0] = 1. / 6. * deepthick;
			deepdza[1] = 2. / 6. * deepthick;
			deepdza[2] = 3. / 6. * deepthick;
			deepdza[3] = -1;
			deepdza[4] = -1;
			deepdza[5] = -1;
			deepdza[6] = -1;
			deepdza[7] = -1;
			deepdza[8] = -1;
			deepdza[9] = -1;
            deepdza[10] = -1;
            deepdza[11] = -1;
            deepdza[12] = -1;
            deepdza[13] = -1;
            deepdza[14] = -1;

			deepnum = 3;
		} else if (deepthick > 3 * dlstshlw && deepthick <= 4 * dlstshlw) {
			deepdza[0] = 1. / 10. * deepthick;
			deepdza[1] = 2. / 10. * deepthick;
			deepdza[2] = 3. / 10. * deepthick;
			deepdza[3] = 4. / 10. * deepthick;
			deepdza[4] = -1;
			deepdza[5] = -1;
			deepdza[6] = -1;
			deepdza[7] = -1;
			deepdza[8] = -1;
			deepdza[9] = -1;
            deepdza[10] = -1;
            deepdza[11] = -1;
            deepdza[12] = -1;
            deepdza[13] = -1;
            deepdza[14] = -1;

			deepnum = 4;
		} else if (deepthick > 4 * dlstshlw && deepthick <= 5 * dlstshlw) {
			deepdza[0] = 1. / 15. * deepthick;
			deepdza[1] = 2. / 15. * deepthick;
			deepdza[2] = 3. / 15. * deepthick;
			deepdza[3] = 4. / 15. * deepthick;
			deepdza[4] = 5. / 15. * deepthick;
			deepdza[5] = -1;
			deepdza[6] = -1;
			deepdza[7] = -1;
			deepdza[8] = -1;
			deepdza[9] = -1;
            deepdza[10] = -1;
            deepdza[11] = -1;
            deepdza[12] = -1;
            deepdza[13] = -1;
            deepdza[14] = -1;

			deepnum = 5;
		} else if (deepthick > 5 * dlstshlw && deepthick <= 6 * dlstshlw) {
			deepdza[0] = 1. / 21. * deepthick;
			deepdza[1] = 2. / 21. * deepthick;
			deepdza[2] = 3. / 21. * deepthick;
			deepdza[3] = 4. / 21. * deepthick;
			deepdza[4] = 5. / 21. * deepthick;
			deepdza[5] = 6. / 21. * deepthick;
			deepdza[6] = -1;
			deepdza[7] = -1;
			deepdza[8] = -1;
			deepdza[9] = -1;
            deepdza[10] = -1;
            deepdza[11] = -1;
            deepdza[12] = -1;
            deepdza[13] = -1;
            deepdza[14] = -1;

			deepnum = 6;
		} else if (deepthick > 6 * dlstshlw && deepthick <= 7 * dlstshlw) {
			deepdza[0] = 1. / 28. * deepthick;
			deepdza[1] = 2. / 28. * deepthick;
			deepdza[2] = 3. / 28. * deepthick;
			deepdza[3] = 4. / 28. * deepthick;
			deepdza[4] = 5. / 28. * deepthick;
			deepdza[5] = 6. / 28. * deepthick;
			deepdza[6] = 7. / 28. * deepthick;
			deepdza[7] = -1;
			deepdza[8] = -1;
			deepdza[9] = -1;
            deepdza[10] = -1;
            deepdza[11] = -1;
            deepdza[12] = -1;
            deepdza[13] = -1;
            deepdza[14] = -1;

			deepnum = 7;
		} else if (deepthick > 7 * dlstshlw && deepthick <= 8 * dlstshlw) {
			deepdza[0] = 1. / 36. * deepthick;
			deepdza[1] = 2. / 36. * deepthick;
			deepdza[2] = 3. / 36. * deepthick;
			deepdza[3] = 4. / 36. * deepthick;
			deepdza[4] = 5. / 36. * deepthick;
			deepdza[5] = 6. / 36. * deepthick;
			deepdza[6] = 7. / 36. * deepthick;
			deepdza[7] = 8. / 36. * deepthick;
			deepdza[8] = -1;
			deepdza[9] = -1;
            deepdza[10] = -1;
            deepdza[11] = -1;
            deepdza[12] = -1;
            deepdza[13] = -1;
            deepdza[14] = -1;

			deepnum = 8;
		} else if (deepthick > 8 * dlstshlw && deepthick <= 9 * dlstshlw) {
			deepdza[0] = 1. / 45. * deepthick;
			deepdza[1] = 2. / 45. * deepthick;
			deepdza[2] = 3. / 45. * deepthick;
			deepdza[3] = 4. / 45. * deepthick;
			deepdza[4] = 5. / 45. * deepthick;
			deepdza[5] = 6. / 45. * deepthick;
			deepdza[6] = 7. / 45. * deepthick;
			deepdza[7] = 8. / 45. * deepthick;
			deepdza[8] = 9. / 45. * deepthick;
			deepdza[9] = -1;
            deepdza[10] = -1;
            deepdza[11] = -1;
            deepdza[12] = -1;
            deepdza[13] = -1;
            deepdza[14] = -1;

			deepnum = 9;
        }else if (deepthick > 9 * dlstshlw && deepthick <= 10 * dlstshlw){
			deepdza[0] = 1. / 55. * deepthick;
			deepdza[1] = 2. / 55. * deepthick;
			deepdza[2] = 3. / 55. * deepthick;
			deepdza[3] = 4. / 55. * deepthick;
			deepdza[4] = 5. / 55. * deepthick;
			deepdza[5] = 6. / 55. * deepthick;
			deepdza[6] = 7. / 55. * deepthick;
			deepdza[7] = 8. / 55. * deepthick;
			deepdza[8] = 9. / 55. * deepthick;
			deepdza[9] = 10. / 55. * deepthick;
            deepdza[10] = -1;
            deepdza[11] = -1;
            deepdza[12] = -1;
            deepdza[13] = -1;
            deepdza[14] = -1;

			deepnum = 10;
        }else if (deepthick > 10 * dlstshlw && deepthick <= 11 * dlstshlw){
            deepdza[0] = 1. / 66. * deepthick;
            deepdza[1] = 2. / 66. * deepthick;
            deepdza[2] = 3. / 66. * deepthick;
            deepdza[3] = 4. / 66. * deepthick;
            deepdza[4] = 5. / 66. * deepthick;
            deepdza[5] = 6. / 66. * deepthick;
            deepdza[6] = 7. / 66. * deepthick;
            deepdza[7] = 8. / 66. * deepthick;
            deepdza[8] = 9. / 66. * deepthick;
            deepdza[9] = 10. / 66. * deepthick;
            deepdza[10] = 11. / 66. * deepthick;
            deepdza[11] = -1;
            deepdza[12] = -1;
            deepdza[13] = -1;
            deepdza[14] = -1;
            deepnum = 11;
            
        }else if (deepthick > 11 * dlstshlw && deepthick <= 12 * dlstshlw){
            deepdza[0] = 1. / 78. * deepthick;
            deepdza[1] = 2. / 78. * deepthick;
            deepdza[2] = 3. / 78. * deepthick;
            deepdza[3] = 4. / 78. * deepthick;
            deepdza[4] = 5. / 78. * deepthick;
            deepdza[5] = 6. / 78. * deepthick;
            deepdza[6] = 7. / 78. * deepthick;
            deepdza[7] = 8. / 78. * deepthick;
            deepdza[8] = 9. / 78. * deepthick;
            deepdza[9] = 10. / 78. * deepthick;
            deepdza[10] = 11. / 78. * deepthick;
            deepdza[11] = 12. / 78. * deepthick;
            deepdza[12] = -1;
            deepdza[13] = -1;
            deepdza[14] = -1;
            
            deepnum = 12;
            
        }else if (deepthick > 12 * dlstshlw && deepthick <= 13 * dlstshlw){
            deepdza[0] = 1. / 91. * deepthick;
            deepdza[1] = 2. / 91. * deepthick;
            deepdza[2] = 3. / 91. * deepthick;
            deepdza[3] = 4. / 91. * deepthick;
            deepdza[4] = 5. / 91. * deepthick;
            deepdza[5] = 6. / 91. * deepthick;
            deepdza[6] = 7. / 91. * deepthick;
            deepdza[7] = 8. / 91. * deepthick;
            deepdza[8] = 9. / 91. * deepthick;
            deepdza[9] = 10. / 91. * deepthick;
            deepdza[10] = 11. / 91. * deepthick;
            deepdza[11] = 12. / 91. * deepthick;
            deepdza[12] = 13. / 91. * deepthick;
            deepdza[13] = -1;
            deepdza[14] = -1;
            
            deepnum = 13;
            
        }else if (deepthick > 13 * dlstshlw && deepthick <= 14 * dlstshlw){
            deepdza[0] = 1. / 105. * deepthick;
            deepdza[1] = 2. / 105. * deepthick;
            deepdza[2] = 3. / 105. * deepthick;
            deepdza[3] = 4. / 105. * deepthick;
            deepdza[4] = 5. / 105. * deepthick;
            deepdza[5] = 6. / 105. * deepthick;
            deepdza[6] = 7. / 105. * deepthick;
            deepdza[7] = 8. / 105. * deepthick;
            deepdza[8] = 9. / 105. * deepthick;
            deepdza[9] = 10. / 105. * deepthick;
            deepdza[10] = 11. / 105. * deepthick;
            deepdza[11] = 12. / 105. * deepthick;
            deepdza[12] = 13. / 105. * deepthick;
            deepdza[13] = 14. / 105. * deepthick;
            deepdza[14] = -1;
            
            deepnum = 14;
            
        }else if (deepthick > 14 * dlstshlw && deepthick <= 15 * dlstshlw){
            deepdza[0] = 1. / 120. * deepthick;
            deepdza[1] = 2. / 120. * deepthick;
            deepdza[2] = 3. / 120. * deepthick;
            deepdza[3] = 4. / 120. * deepthick;
            deepdza[4] = 5. / 120. * deepthick;
            deepdza[5] = 6. / 120. * deepthick;
            deepdza[6] = 7. / 120. * deepthick;
            deepdza[7] = 8. / 120. * deepthick;
            deepdza[8] = 9. / 120. * deepthick;
            deepdza[9] = 10. / 120. * deepthick;
            deepdza[10] = 11. / 120. * deepthick;
            deepdza[11] = 12. / 120. * deepthick;
            deepdza[12] = 13. / 120. * deepthick;
            deepdza[13] = 14. / 120. * deepthick;
            deepdza[14] = 15. / 120. * deepthick;
            
            deepnum = 15;
		
	} else {
        deepdza[0] = 1. / 120. * deepthick;
        deepdza[1] = 2. / 120. * deepthick;
        deepdza[2] = 3. / 120. * deepthick;
        deepdza[3] = 4. / 120. * deepthick;
        deepdza[4] = 5. / 120. * deepthick;
        deepdza[5] = 6. / 120. * deepthick;
        deepdza[6] = 7. / 120. * deepthick;
        deepdza[7] = 8. / 120. * deepthick;
        deepdza[8] = 9. / 120. * deepthick;
        deepdza[9] = 10. / 120. * deepthick;
        deepdza[10] = 11. / 120. * deepthick;
        deepdza[11] = 12. / 120. * deepthick;
        deepdza[12] = 13. / 120. * deepthick;
        deepdza[13] = 14. / 120. * deepthick;
        deepdza[14] = 15. / 120. * deepthick;
        
        
        deepnum = 15;
    }
		/*
		deepdza[0] = deepthick;
		deepdza[1] = -1;
		deepdza[2] = -1;
		deepdza[3] = -1;
		deepdza[4] = -1;
		deepdza[5] = -1;
		deepdza[6] = -1;
		deepdza[7] = -1;
		deepdza[8] = -1;
		deepdza[9] = -1;

		deepnum = 1;
		*/
	}
	/*
	 if (dlstshlw > 0) {
	 if (deepthick < 3 * dlstshlw) {
	 deepdza[0] = deepthick;
	 deepdza[1] = -1;
	 deepdza[2] = -1;
	 deepnum = 1;
	 } else if (deepthick >= 3 * dlstshlw && deepthick < 6 * dlstshlw) {
	 deepdza[0] = 1. / 3. * deepthick;
	 deepdza[1] = 2. / 3. * deepthick;
	 deepdza[2] = -1;
	 deepnum = 2;
	 } else {
	 deepdza[0] = 1. / 6. * deepthick;
	 deepdza[1] = 2. / 6. * deepthick;
	 deepdza[2] = 3. / 6. * deepthick;
	 deepnum = 3;
	 }
	 } else {
	 deepdza[0] = deepthick;
	 deepdza[1] = -1;
	 deepdza[2] = -1;
	 deepnum = 1;
	 }*/

}

void Peat::updateShlwThicknesses(int type[], double dz[], const int & maxnum) {
	shlwnum = 0;
	shlwthick = 0;
	for (int i = 0; i < maxnum; i++) {
		if (type[i] == 1) {
			shlwdza[shlwnum] = dz[i];
			shlwnum++;
			shlwthick += dz[i];
		} else {
			if (type[i] > 1) {
				break;
			}
		}
	}
}

void Peat::updateDeepThicknesses(int type[], double dz[], const int & maxnum) {
	deepnum = 0;
	deepthick = 0;

	for (int i = 0; i < maxnum; i++) {
		if (type[i] == 2) {
			deepdza[deepnum] = dz[i];
			deepnum++;
			deepthick += dz[i];
		} else {
			if (type[i] > 2) {
				break;
			}
		}
	}
	if (deepnum == 1) {
		if (deepthick < 0.02) {
			deepthick = 0.02;
			deepdza[0] = 0.02;
		}
	} else if (deepnum == 0) {
		deepnum = 1;
		deepthick = 0.02;
		deepdza[0] = 0.02;

	}

}
