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

/*	if (thickness < 0.02 && shlwthick < 0.02) {
		return true;
	} else if (thickness < 0.04 && thickness >= 0.01 && shlwthick < 0.04 && shlwthick >= 0.02) {
		return true;
	} else if (thickness < 0.06 && thickness >= 0.04 && shlwthick < 0.06 && shlwthick >= 0.04) {
		return true;
	} else if (thickness < 0.10 && thickness >= 0.06 && shlwthick < 0.10 && shlwthick >= 0.06) {
		return true;
	} else if (thickness < 0.15 && thickness >= 0.10 && shlwthick < 0.15 && shlwthick >= 0.10) {
		return true;
	} else if (thickness < 0.20 && thickness >= 0.15 && shlwthick < 0.20 && shlwthick >= 0.15) {
		return true;

	} else if (thickness < 0.28 && thickness >= 0.20 && shlwthick < 0.28 && shlwthick >= 0.20) {
		return true;
	} else if (thickness < 0.40 && thickness >= 0.28 && shlwthick < 0.40 && shlwthick >= 0.28) {
		return true;
	} else if (thickness >= 0.4 && shlwthick >= 0.4) {
		return true;
	}
 */
    if (thickness < 0.03 && shlwthick < 0.03) {
        return true;
    } else if (thickness < 0.06 && thickness >= 0.03 && shlwthick < 0.06 && shlwthick >= 0.03) {
        return true;
    } else if (thickness < 0.09 && thickness >= 0.06 && shlwthick < 0.09 && shlwthick >= 0.06) {
        return true;
    } else if (thickness < 0.12 && thickness >= 0.09 && shlwthick < 0.12 && shlwthick >= 0.09) {
        return true;
    } else if (thickness < 0.15 && thickness >= 0.12 && shlwthick < 0.15 && shlwthick >= 0.12) {
        return true;
    } else if (thickness < 0.18 && thickness >= 0.15 && shlwthick < 0.18 && shlwthick >= 0.15) {
        return true;
        
    } else if (thickness < 0.21 && thickness >= 0.18 && shlwthick < 0.21 && shlwthick >= 0.18) {
        return true;
    } else if (thickness < 0.24 && thickness >= 0.21 && shlwthick < 0.24 && shlwthick >= 0.21) {
        return true;
    } else if (thickness < 0.27 && thickness >= 0.24 && shlwthick < 0.27 && shlwthick >= 0.24) {
        return true;
    } else if (thickness < 0.30 && thickness >= 0.27 && shlwthick < 0.30 && shlwthick >= 0.27) {
        return true;
    } else if (thickness < 0.33 && thickness >= 0.30 && shlwthick < 0.33 && shlwthick >= 0.30) {
        return true;
    } else if (thickness < 0.36 && thickness >= 0.33 && shlwthick < 0.36 && shlwthick >= 0.33) {
        return true;
    } else if (thickness < 0.39 && thickness >= 0.36 && shlwthick < 0.39 && shlwthick >= 0.36) {
        return true;
    } else if (thickness < 0.42 && thickness >= 0.39 && shlwthick < 0.42 && shlwthick >= 0.39) {
        return true;
    } else if (thickness < 0.45 && thickness >= 0.42 && shlwthick < 0.45 && shlwthick >= 0.42) {
        return true;
    } else if (thickness < 0.48 && thickness >= 0.45 && shlwthick < 0.48 && shlwthick >= 0.45) {
        return true;
    } else if (thickness < 0.51 && thickness >= 0.48 && shlwthick < 0.51 && shlwthick >= 0.48) {
        return true;
    } else if (thickness < 0.54 && thickness >= 0.51 && shlwthick < 0.54 && shlwthick >= 0.51) {
        return true;
    } else if (thickness < 0.57 && thickness >= 0.54 && shlwthick < 0.57 && shlwthick >= 0.54) {
        return true;
   
    } else if (thickness >= 0.57 && shlwthick >= 0.57) {
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
    else if (thickness > 14 * dlstshlw && thickness <= 15 * dlstshlw)
        newdeepnum = 15;
    
    else if (thickness > 15 * dlstshlw && thickness <= 16 * dlstshlw)
        newdeepnum = 16;
    else if (thickness > 16 * dlstshlw && thickness <= 17 * dlstshlw)
        newdeepnum = 17;
    else if (thickness > 17 * dlstshlw && thickness <= 18 * dlstshlw)
        newdeepnum = 18;
    else if (thickness > 18 * dlstshlw && thickness <= 19 * dlstshlw)
        newdeepnum = 19;
    else if (thickness > 19 * dlstshlw && thickness <= 20 * dlstshlw)
        newdeepnum = 20;
    else if (thickness > 20 * dlstshlw && thickness <= 21 * dlstshlw)
        newdeepnum = 21;
    else if (thickness > 21 * dlstshlw && thickness <= 22 * dlstshlw)
        newdeepnum = 22;
    else if (thickness > 22 * dlstshlw && thickness <= 23 * dlstshlw)
        newdeepnum = 23;
    else if (thickness > 23 * dlstshlw && thickness <= 24 * dlstshlw)
        newdeepnum = 24;
    else if (thickness > 24 * dlstshlw && thickness <= 25 * dlstshlw)
        newdeepnum = 25;
    else if (thickness > 26 * dlstshlw && thickness <= 27 * dlstshlw)
        newdeepnum = 27;
    else if (thickness > 27 * dlstshlw && thickness <= 28 * dlstshlw)
        newdeepnum = 28;
    else if (thickness > 28 * dlstshlw && thickness <= 29 * dlstshlw)
        newdeepnum = 29;
    else if (thickness > 29 * dlstshlw && thickness <= 30 * dlstshlw)
        newdeepnum = 30;
	else
		newdeepnum = 31;

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
    }else if (thickness <= 0.33) {
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
        shlwdza[10] = thickness-0.3;
        shlwnum = 11;
        
    }else if (thickness <= 0.36) {
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
    shlwdza[10] = 0.03;
    shlwdza[11] = thickness-0.33;
    shlwnum = 12;
        
    }else if (thickness <= 0.39) {
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
        shlwdza[10] = 0.03;
        shlwdza[11] = 0.03;
        shlwdza[12] = thickness-0.36;
        shlwnum = 13;
        
        
    }
    

 else if (thickness <= 0.42) {
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
     shlwdza[10] = 0.03;
     shlwdza[11] = 0.03;
        shlwdza[12] = 0.03;
        shlwdza[13] = thickness-0.39;
        shlwnum = 14;
    }  else if (thickness <= 0.45) {
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
        shlwdza[10] = 0.03;
        shlwdza[11] = 0.03;
        shlwdza[12] = 0.03;
        shlwdza[13] = 0.03;
        shlwdza[14] = thickness-0.42;
        
        shlwnum = 15;
    } else if (thickness <= 0.48) {
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
        shlwdza[10] = 0.03;
        shlwdza[11] = 0.03;
        shlwdza[12] = 0.03;
        shlwdza[13] = 0.03;
        shlwdza[14] =  0.03;
        shlwdza[15] = thickness-0.45;
        shlwnum = 16;
    } else if (thickness <= 0.51) {
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
        shlwdza[10] = 0.03;
        shlwdza[11] = 0.03;
        shlwdza[12] = 0.03;
        shlwdza[13] = 0.03;
        shlwdza[14] =  0.03;
        shlwdza[15] = 0.03;
        shlwdza[16] = thickness-0.48;
        shlwnum = 17;
    } else if (thickness <= 0.54) {
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
        shlwdza[10] = 0.03;
        shlwdza[11] = 0.03;
        shlwdza[12] = 0.03;
        shlwdza[13] = 0.03;
        shlwdza[14] =  0.03;
        shlwdza[15] = 0.03;
        shlwdza[16] = 0.03;
        shlwdza[17] = thickness-0.51;
        shlwnum = 18;
    } else if (thickness <= 0.57) {
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
        shlwdza[10] = 0.03;
        shlwdza[11] = 0.03;
        shlwdza[12] = 0.03;
        shlwdza[13] = 0.03;
        shlwdza[14] =  0.03;
        shlwdza[15] = 0.03;
        shlwdza[16] = 0.03;
        shlwdza[17] = 0.03;
        shlwdza[18] = thickness-0.54;
        shlwnum = 19;
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
        shlwdza[10] = 0.03;
        shlwdza[11] = 0.03;
        shlwdza[12] = 0.03;
        shlwdza[13] = 0.03;
        shlwdza[14] =  0.03;
        shlwdza[15] = 0.03;
        shlwdza[16] = 0.03;
        shlwdza[17] = 0.03;
        shlwdza[18] = 0.03;
        shlwdza[19] = thickness-0.57;
        shlwnum = 20;
    

	}
	shlwthick = thickness;
	dlstshlw = shlwdza[shlwnum - 1];
}


void Peat::initDeepThicknesses(const double & thickness) {
    olddeepthick = deepthick;
    
    deepthick = thickness;
    if (thickness < 1.0e-6)
        deepthick = 0.0;
    
    deepnum = 0;
    
    if (dlstshlw > 0) {
        if (deepthick <= 0.03) { //dlstshlw = 0.02
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
            deepdza[15] = -1;
            deepdza[16] = -1;
            deepdza[17] = -1;
            deepdza[18] = -1;
            deepdza[19] = -1;
            deepdza[20] = -1;
            deepdza[21] = -1;
            deepdza[22] = -1;
            deepdza[23] = -1;
            deepdza[24] = -1;
            deepdza[25] = -1;
            deepdza[26] = -1;
            deepdza[27] = -1;
            deepdza[28] = -1;
            deepdza[29] = -1;
            
            deepnum = 1;
        } else if (deepthick <= 0.06) {
            deepdza[0] = 0.03;
            deepdza[1] = deepthick - 0.03;
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
            deepdza[15] = -1;
            deepdza[16] = -1;
            deepdza[17] = -1;
            deepdza[18] = -1;
            deepdza[19] = -1;
            deepdza[20] = -1;
            deepdza[21] = -1;
            deepdza[22] = -1;
            deepdza[23] = -1;
            deepdza[24] = -1;
            deepdza[25] = -1;
            deepdza[26] = -1;
            deepdza[27] = -1;
            deepdza[28] = -1;
            deepdza[29] = -1;
            
            deepnum = 2;
        } else if ( deepthick <= 0.09) {
            deepdza[0] = 0.03;
            deepdza[1] = 0.03;
            deepdza[2] = deepthick - 0.06;
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
            deepdza[15] = -1;
            deepdza[16] = -1;
            deepdza[17] = -1;
            deepdza[18] = -1;
            deepdza[19] = -1;
            deepdza[20] = -1;
            deepdza[21] = -1;
            deepdza[22] = -1;
            deepdza[23] = -1;
            deepdza[24] = -1;
            deepdza[25] = -1;
            deepdza[26] = -1;
            deepdza[27] = -1;
            deepdza[28] = -1;
            deepdza[29] = -1;
            
            deepnum = 3;
        } else if (deepthick <= 0.12) {
            deepdza[0] = 0.03;
            deepdza[1] = 0.03;
            deepdza[2] = 0.03;
            deepdza[3] = deepthick - 0.09;
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
            deepdza[15] = -1;
            deepdza[16] = -1;
            deepdza[17] = -1;
            deepdza[18] = -1;
            deepdza[19] = -1;
            deepdza[20] = -1;
            deepdza[21] = -1;
            deepdza[22] = -1;
            deepdza[23] = -1;
            deepdza[24] = -1;
            deepdza[25] = -1;
            deepdza[26] = -1;
            deepdza[27] = -1;
            deepdza[28] = -1;
            deepdza[29] = -1;
            
            deepnum = 4;
        } else if (deepthick <= 0.15) {
            deepdza[0] = 0.03;
            deepdza[1] = 0.03;
            deepdza[2] = 0.03;
            deepdza[3] = 0.03;
            deepdza[4] = deepthick - 0.12;
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
            deepdza[15] = -1;
            deepdza[16] = -1;
            deepdza[17] = -1;
            deepdza[18] = -1;
            deepdza[19] = -1;
            deepdza[20] = -1;
            deepdza[21] = -1;
            deepdza[22] = -1;
            deepdza[23] = -1;
            deepdza[24] = -1;
            deepdza[25] = -1;
            deepdza[26] = -1;
            deepdza[27] = -1;
            deepdza[28] = -1;
            deepdza[29] = -1;
            
            deepnum = 5;
        } else if (deepthick <= 0.18) {
            deepdza[0] = 0.03;
            deepdza[1] = 0.03;
            deepdza[2] = 0.03;
            deepdza[3] = 0.03;
            deepdza[4] = 0.03;
            deepdza[5] = deepthick - 0.15;
            deepdza[6] = -1;
            deepdza[7] = -1;
            deepdza[8] = -1;
            deepdza[9] = -1;
            deepdza[10] = -1;
            deepdza[11] = -1;
            deepdza[12] = -1;
            deepdza[13] = -1;
            deepdza[14] = -1;
            deepdza[15] = -1;
            deepdza[16] = -1;
            deepdza[17] = -1;
            deepdza[18] = -1;
            deepdza[19] = -1;
            deepdza[20] = -1;
            deepdza[21] = -1;
            deepdza[22] = -1;
            deepdza[23] = -1;
            deepdza[24] = -1;
            deepdza[25] = -1;
            deepdza[26] = -1;
            deepdza[27] = -1;
            deepdza[28] = -1;
            deepdza[29] = -1;
            
            deepnum = 6;
        } else if (deepthick <= 0.21) {
            deepdza[0] = 0.03;
            deepdza[1] = 0.03;
            deepdza[2] = 0.03;
            deepdza[3] = 0.03;
            deepdza[4] = 0.03;
            deepdza[5] = 0.03;
            deepdza[6] = deepthick - 0.18;
            deepdza[7] = -1;
            deepdza[8] = -1;
            deepdza[9] = -1;
            deepdza[10] = -1;
            deepdza[11] = -1;
            deepdza[12] = -1;
            deepdza[13] = -1;
            deepdza[14] = -1;
            deepdza[15] = -1;
            deepdza[16] = -1;
            deepdza[17] = -1;
            deepdza[18] = -1;
            deepdza[19] = -1;
            deepdza[20] = -1;
            deepdza[21] = -1;
            deepdza[22] = -1;
            deepdza[23] = -1;
            deepdza[24] = -1;
            deepdza[25] = -1;
            deepdza[26] = -1;
            deepdza[27] = -1;
            deepdza[28] = -1;
            deepdza[29] = -1;
            
            deepnum = 7;
        } else if (deepthick <= 0.24) {
            deepdza[0] = 0.03;
            deepdza[1] = 0.03;
            deepdza[2] = 0.03;
            deepdza[3] = 0.03;
            deepdza[4] = 0.03;
            deepdza[5] = 0.03;
            deepdza[6] = 0.03;
            deepdza[7] = deepthick - 0.21;
            deepdza[8] = -1;
            deepdza[9] = -1;
            deepdza[10] = -1;
            deepdza[11] = -1;
            deepdza[12] = -1;
            deepdza[13] = -1;
            deepdza[14] = -1;
            deepdza[15] = -1;
            deepdza[16] = -1;
            deepdza[17] = -1;
            deepdza[18] = -1;
            deepdza[19] = -1;
            deepdza[20] = -1;
            deepdza[21] = -1;
            deepdza[22] = -1;
            deepdza[23] = -1;
            deepdza[24] = -1;
            deepdza[25] = -1;
            deepdza[26] = -1;
            deepdza[27] = -1;
            deepdza[28] = -1;
            deepdza[29] = -1;
            
            deepnum = 8;
        } else if (deepthick <= 0.27) {
            deepdza[0] = 0.03;
            deepdza[1] = 0.03;
            deepdza[2] = 0.03;
            deepdza[3] = 0.03;
            deepdza[4] = 0.03;
            deepdza[5] = 0.03;
            deepdza[6] = 0.03;
            deepdza[7] = 0.03;
            deepdza[8] = deepthick - 0.24;
            deepdza[9] = -1;
            deepdza[10] = -1;
            deepdza[11] = -1;
            deepdza[12] = -1;
            deepdza[13] = -1;
            deepdza[14] = -1;
            deepdza[15] = -1;
            deepdza[16] = -1;
            deepdza[17] = -1;
            deepdza[18] = -1;
            deepdza[19] = -1;
            deepdza[20] = -1;
            deepdza[21] = -1;
            deepdza[22] = -1;
            deepdza[23] = -1;
            deepdza[24] = -1;
            deepdza[25] = -1;
            deepdza[26] = -1;
            deepdza[27] = -1;
            deepdza[28] = -1;
            deepdza[29] = -1;
            
            deepnum = 9;
        }else if (deepthick <= 0.30){
            deepdza[0] = 0.03;
            deepdza[1] = 0.03;
            deepdza[2] = 0.03;
            deepdza[3] = 0.03;
            deepdza[4] = 0.03;
            deepdza[5] = 0.03;
            deepdza[6] = 0.03;
            deepdza[7] = 0.03;
            deepdza[8] = 0.03;
            deepdza[9] = deepthick - 0.27;
            deepdza[10] = -1;
            deepdza[11] = -1;
            deepdza[12] = -1;
            deepdza[13] = -1;
            deepdza[14] = -1;
            deepdza[15] = -1;
            deepdza[16] = -1;
            deepdza[17] = -1;
            deepdza[18] = -1;
            deepdza[19] = -1;
            deepdza[20] = -1;
            deepdza[21] = -1;
            deepdza[22] = -1;
            deepdza[23] = -1;
            deepdza[24] = -1;
            deepdza[25] = -1;
            deepdza[26] = -1;
            deepdza[27] = -1;
            deepdza[28] = -1;
            deepdza[29] = -1;
            
            deepnum = 10;
        }else if (deepthick <= 0.33){
            deepdza[0] = 0.03;
            deepdza[1] = 0.03;
            deepdza[2] = 0.03;
            deepdza[3] = 0.03;
            deepdza[4] = 0.03;
            deepdza[5] = 0.03;
            deepdza[6] = 0.03;
            deepdza[7] = 0.03;
            deepdza[8] = 0.03;
            deepdza[9] = 0.03;
            deepdza[10] = deepthick - 0.30;
            deepdza[11] = -1;
            deepdza[12] = -1;
            deepdza[13] = -1;
            deepdza[14] = -1;
            deepdza[15] = -1;
            deepdza[16] = -1;
            deepdza[17] = -1;
            deepdza[18] = -1;
            deepdza[19] = -1;
            deepdza[20] = -1;
            deepdza[21] = -1;
            deepdza[22] = -1;
            deepdza[23] = -1;
            deepdza[24] = -1;
            deepdza[25] = -1;
            deepdza[26] = -1;
            deepdza[27] = -1;
            deepdza[28] = -1;
            deepdza[29] = -1;
            
            deepnum = 11;
            
        }else if (deepthick <= 0.36){
            deepdza[0] = 0.03;
            deepdza[1] = 0.03;
            deepdza[2] = 0.03;
            deepdza[3] = 0.03;
            deepdza[4] = 0.03;
            deepdza[5] = 0.03;
            deepdza[6] = 0.03;
            deepdza[7] = 0.03;
            deepdza[8] = 0.03;
            deepdza[9] = 0.03;
            deepdza[10] = 0.03;
            deepdza[11] = deepthick - 0.33;
            deepdza[12] = -1;
            deepdza[13] = -1;
            deepdza[14] = -1;
            deepdza[15] = -1;
            deepdza[16] = -1;
            deepdza[17] = -1;
            deepdza[18] = -1;
            deepdza[19] = -1;
            deepdza[20] = -1;
            deepdza[21] = -1;
            deepdza[22] = -1;
            deepdza[23] = -1;
            deepdza[24] = -1;
            deepdza[25] = -1;
            deepdza[26] = -1;
            deepdza[27] = -1;
            deepdza[28] = -1;
            deepdza[29] = -1;
            
            deepnum = 12;
            
        }else if (deepthick <= 0.39){
            deepdza[0] = 0.03;
            deepdza[1] = 0.03;
            deepdza[2] = 0.03;
            deepdza[3] = 0.03;
            deepdza[4] = 0.03;
            deepdza[5] = 0.03;
            deepdza[6] = 0.03;
            deepdza[7] = 0.03;
            deepdza[8] = 0.03;
            deepdza[9] = 0.03;
            deepdza[10] = 0.03;
            deepdza[11] = 0.03;
            deepdza[12] = deepthick - 0.36;
            deepdza[13] = -1;
            deepdza[14] = -1;
            deepdza[14] = -1;
            deepdza[15] = -1;
            deepdza[16] = -1;
            deepdza[17] = -1;
            deepdza[18] = -1;
            deepdza[19] = -1;
            deepdza[20] = -1;
            deepdza[21] = -1;
            deepdza[22] = -1;
            deepdza[23] = -1;
            deepdza[24] = -1;
            deepdza[25] = -1;
            deepdza[26] = -1;
            deepdza[27] = -1;
            deepdza[28] = -1;
            deepdza[29] = -1;
            
            
            deepnum = 13;
            
        }else if (deepthick <= 0.42){
            deepdza[0] = 0.03;
            deepdza[1] = 0.03;
            deepdza[2] = 0.03;
            deepdza[3] = 0.03;
            deepdza[4] = 0.03;
            deepdza[5] = 0.03;
            deepdza[6] = 0.03;
            deepdza[7] = 0.03;
            deepdza[8] = 0.03;
            deepdza[9] = 0.03;
            deepdza[10] = 0.03;
            deepdza[11] = 0.03;
            deepdza[12] = 0.03;
            deepdza[13] = deepthick - 0.39;
            deepdza[14] = -1;
            deepdza[14] = -1;
            deepdza[15] = -1;
            deepdza[16] = -1;
            deepdza[17] = -1;
            deepdza[18] = -1;
            deepdza[19] = -1;
            deepdza[20] = -1;
            deepdza[21] = -1;
            deepdza[22] = -1;
            deepdza[23] = -1;
            deepdza[24] = -1;
            deepdza[25] = -1;
            deepdza[26] = -1;
            deepdza[27] = -1;
            deepdza[28] = -1;
            deepdza[29] = -1;
            
            deepnum = 14;
            
        }else if (deepthick <= 0.45){
            deepdza[0] = 0.03;
            deepdza[1] = 0.03;
            deepdza[2] = 0.03;
            deepdza[3] = 0.03;
            deepdza[4] = 0.03;
            deepdza[5] = 0.03;
            deepdza[6] = 0.03;
            deepdza[7] = 0.03;
            deepdza[8] = 0.03;
            deepdza[9] = 0.03;
            deepdza[10] = 0.03;
            deepdza[11] = 0.03;
            deepdza[12] = 0.03;
            deepdza[13] = 0.03;
            deepdza[14] = deepthick - 0.42;
            deepdza[15] = -1;
            deepdza[16] = -1;
            deepdza[17] = -1;
            deepdza[18] = -1;
            deepdza[19] = -1;
            deepdza[20] = -1;
            deepdza[21] = -1;
            deepdza[22] = -1;
            deepdza[23] = -1;
            deepdza[24] = -1;
            deepdza[25] = -1;
            deepdza[26] = -1;
            deepdza[27] = -1;
            deepdza[28] = -1;
            deepdza[29] = -1;
            
            deepnum = 15;
            
        }else if (deepthick <= 0.48){
            deepdza[0] = 0.03;
            deepdza[1] = 0.03;
            deepdza[2] = 0.03;
            deepdza[3] = 0.03;
            deepdza[4] = 0.03;
            deepdza[5] = 0.03;
            deepdza[6] = 0.03;
            deepdza[7] = 0.03;
            deepdza[8] = 0.03;
            deepdza[9] = 0.03;
            deepdza[10] = 0.03;
            deepdza[11] = 0.03;
            deepdza[12] = 0.03;
            deepdza[13] = 0.03;
            deepdza[14] = 0.03;
            deepdza[15] = deepthick - 0.45;
            
            deepdza[16] = -1;
            deepdza[17] = -1;
            deepdza[18] = -1;
            deepdza[19] = -1;
            deepdza[20] = -1;
            deepdza[21] = -1;
            deepdza[22] = -1;
            deepdza[23] = -1;
            deepdza[24] = -1;
            deepdza[25] = -1;
            deepdza[26] = -1;
            deepdza[27] = -1;
            deepdza[28] = -1;
            deepdza[29] = -1;
            
            deepnum = 16;
            
        }else if (deepthick <= 0.51){
            deepdza[0] = 0.03;
            deepdza[1] = 0.03;
            deepdza[2] = 0.03;
            deepdza[3] = 0.03;
            deepdza[4] = 0.03;
            deepdza[5] = 0.03;
            deepdza[6] = 0.03;
            deepdza[7] = 0.03;
            deepdza[8] = 0.03;
            deepdza[9] = 0.03;
            deepdza[10] = 0.03;
            deepdza[11] = 0.03;
            deepdza[12] = 0.03;
            deepdza[13] = 0.03;
            deepdza[14] = 0.03;
            deepdza[15] = 0.03;
            deepdza[16] = deepthick - 0.48;
            
            deepdza[17] = -1;
            deepdza[18] = -1;
            deepdza[19] = -1;
            deepdza[20] = -1;
            deepdza[21] = -1;
            deepdza[22] = -1;
            deepdza[23] = -1;
            deepdza[24] = -1;
            deepdza[25] = -1;
            deepdza[26] = -1;
            deepdza[27] = -1;
            deepdza[28] = -1;
            deepdza[29] = -1;
            
            deepnum = 17;
            
        }else if (deepthick <= 0.54){
            deepdza[0] = 0.03;
            deepdza[1] = 0.03;
            deepdza[2] = 0.03;
            deepdza[3] = 0.03;
            deepdza[4] = 0.03;
            deepdza[5] = 0.03;
            deepdza[6] = 0.03;
            deepdza[7] = 0.03;
            deepdza[8] = 0.03;
            deepdza[9] = 0.03;
            deepdza[10] = 0.03;
            deepdza[11] = 0.03;
            deepdza[12] = 0.03;
            deepdza[13] = 0.03;
            deepdza[14] = 0.03;
            deepdza[15] = 0.03;
            deepdza[16] = 0.03;
            deepdza[17] = deepthick - 0.51;
            
            deepdza[18] = -1;
            deepdza[19] = -1;
            deepdza[20] = -1;
            deepdza[21] = -1;
            deepdza[22] = -1;
            deepdza[23] = -1;
            deepdza[24] = -1;
            deepdza[25] = -1;
            deepdza[26] = -1;
            deepdza[27] = -1;
            deepdza[28] = -1;
            deepdza[29] = -1;
            
            deepnum = 18;
            
        }else if (deepthick <= 0.57){
            deepdza[0] = 0.03;
            deepdza[1] = 0.03;
            deepdza[2] = 0.03;
            deepdza[3] = 0.03;
            deepdza[4] = 0.03;
            deepdza[5] = 0.03;
            deepdza[6] = 0.03;
            deepdza[7] = 0.03;
            deepdza[8] = 0.03;
            deepdza[9] = 0.03;
            deepdza[10] = 0.03;
            deepdza[11] = 0.03;
            deepdza[12] = 0.03;
            deepdza[13] = 0.03;
            deepdza[14] = 0.03;
            deepdza[15] = 0.03;
            deepdza[16] = 0.03;
            deepdza[17] = 0.03;
            deepdza[18] = deepthick - 0.54;
            deepdza[19] = -1;
            deepdza[20] = -1;
            deepdza[21] = -1;
            deepdza[22] = -1;
            deepdza[23] = -1;
            deepdza[24] = -1;
            deepdza[25] = -1;
            deepdza[26] = -1;
            deepdza[27] = -1;
            deepdza[28] = -1;
            deepdza[29] = -1;
            
            
            deepnum = 19;
            
        }else if (deepthick <= 0.60){
            deepdza[0] = 0.03;
            deepdza[1] = 0.03;
            deepdza[2] = 0.03;
            deepdza[3] = 0.03;
            deepdza[4] = 0.03;
            deepdza[5] = 0.03;
            deepdza[6] = 0.03;
            deepdza[7] = 0.03;
            deepdza[8] = 0.03;
            deepdza[9] = 0.03;
            deepdza[10] = 0.03;
            deepdza[11] = 0.03;
            deepdza[12] = 0.03;
            deepdza[13] = 0.03;
            deepdza[14] = 0.03;
            deepdza[15] = 0.03;
            deepdza[16] = 0.03;
            deepdza[17] = 0.03;
            deepdza[18] = 0.03;
            deepdza[19] = deepthick - 0.57;
            deepdza[20] = -1;
            deepdza[21] = -1;
            deepdza[22] = -1;
            deepdza[23] = -1;
            deepdza[24] = -1;
            deepdza[25] = -1;
            deepdza[26] = -1;
            deepdza[27] = -1;
            deepdza[28] = -1;
            deepdza[29] = -1;
            
            deepnum = 20;
            
        }else if (deepthick <= 0.63){
            deepdza[0] = 0.03;
            deepdza[1] = 0.03;
            deepdza[2] = 0.03;
            deepdza[3] = 0.03;
            deepdza[4] = 0.03;
            deepdza[5] = 0.03;
            deepdza[6] = 0.03;
            deepdza[7] = 0.03;
            deepdza[8] = 0.03;
            deepdza[9] = 0.03;
            deepdza[10] = 0.03;
            deepdza[11] = 0.03;
            deepdza[12] = 0.03;
            deepdza[13] = 0.03;
            deepdza[14] = 0.03;
            deepdza[15] = 0.03;
            deepdza[16] = 0.03;
            deepdza[17] = 0.03;
            deepdza[18] = 0.03;
            deepdza[19] = 0.03;
            deepdza[20] = deepthick - 0.60;
            deepdza[21] = -1;
            deepdza[22] = -1;
            deepdza[23] = -1;
            deepdza[24] = -1;
            deepdza[25] = -1;
            deepdza[26] = -1;
            deepdza[27] = -1;
            deepdza[28] = -1;
            deepdza[29] = -1;
            
            deepnum = 21;
            
        }else if (deepthick <= 0.66){
            deepdza[0] = 0.03;
            deepdza[1] = 0.03;
            deepdza[2] = 0.03;
            deepdza[3] = 0.03;
            deepdza[4] = 0.03;
            deepdza[5] = 0.03;
            deepdza[6] = 0.03;
            deepdza[7] = 0.03;
            deepdza[8] = 0.03;
            deepdza[9] = 0.03;
            deepdza[10] = 0.03;
            deepdza[11] = 0.03;
            deepdza[12] = 0.03;
            deepdza[13] = 0.03;
            deepdza[14] = 0.03;
            deepdza[15] = 0.03;
            deepdza[16] = 0.03;
            deepdza[17] = 0.03;
            deepdza[18] = 0.03;
            deepdza[19] = 0.03;
            deepdza[20] = 0.03;
            deepdza[21] = deepthick - 0.63;
            deepdza[22] = -1;
            deepdza[23] = -1;
            deepdza[24] = -1;
            deepdza[25] = -1;
            deepdza[26] = -1;
            deepdza[27] = -1;
            deepdza[28] = -1;
            deepdza[29] = -1;
            
            deepnum = 22;
            
        }else if (deepthick <= 0.69){
            deepdza[0] = 0.03;
            deepdza[1] = 0.03;
            deepdza[2] = 0.03;
            deepdza[3] = 0.03;
            deepdza[4] = 0.03;
            deepdza[5] = 0.03;
            deepdza[6] = 0.03;
            deepdza[7] = 0.03;
            deepdza[8] = 0.03;
            deepdza[9] = 0.03;
            deepdza[10] = 0.03;
            deepdza[11] = 0.03;
            deepdza[12] = 0.03;
            deepdza[13] = 0.03;
            deepdza[14] = 0.03;
            deepdza[15] = 0.03;
            deepdza[16] = 0.03;
            deepdza[17] = 0.03;
            deepdza[18] = 0.03;
            deepdza[19] = 0.03;
            deepdza[20] = 0.03;
            deepdza[21] = 0.03;
            deepdza[22] = deepthick - 0.66;
            deepdza[23] = -1;
            deepdza[24] = -1;
            deepdza[25] = -1;
            deepdza[26] = -1;
            deepdza[27] = -1;
            deepdza[28] = -1;
            deepdza[29] = -1;
            
            deepnum = 23;
            
        }else if (deepthick <= 0.72){
            deepdza[0] = 0.03;
            deepdza[1] = 0.03;
            deepdza[2] = 0.03;
            deepdza[3] = 0.03;
            deepdza[4] = 0.03;
            deepdza[5] = 0.03;
            deepdza[6] = 0.03;
            deepdza[7] = 0.03;
            deepdza[8] = 0.03;
            deepdza[9] = 0.03;
            deepdza[10] = 0.03;
            deepdza[11] = 0.03;
            deepdza[12] = 0.03;
            deepdza[13] = 0.03;
            deepdza[14] = 0.03;
            deepdza[15] = 0.03;
            deepdza[16] = 0.03;
            deepdza[17] = 0.03;
            deepdza[18] = 0.03;
            deepdza[19] = 0.03;
            deepdza[20] = 0.03;
            deepdza[21] = 0.03;
            deepdza[22] = 0.03;
            deepdza[23] = deepthick - 0.69;
            deepdza[24] = -1;
            deepdza[25] = -1;
            deepdza[26] = -1;
            deepdza[27] = -1;
            deepdza[28] = -1;
            deepdza[29] = -1;
            
            deepnum = 24;
            
        }else if (deepthick <= 0.75){
            deepdza[0] = 0.03;
            deepdza[1] = 0.03;
            deepdza[2] = 0.03;
            deepdza[3] = 0.03;
            deepdza[4] = 0.03;
            deepdza[5] = 0.03;
            deepdza[6] = 0.03;
            deepdza[7] = 0.03;
            deepdza[8] = 0.03;
            deepdza[9] = 0.03;
            deepdza[10] = 0.03;
            deepdza[11] = 0.03;
            deepdza[12] = 0.03;
            deepdza[13] = 0.03;
            deepdza[14] = 0.03;
            deepdza[15] = 0.03;
            deepdza[16] = 0.03;
            deepdza[17] = 0.03;
            deepdza[18] = 0.03;
            deepdza[19] = 0.03;
            deepdza[20] = 0.03;
            deepdza[21] = 0.03;
            deepdza[22] = 0.03;
            deepdza[23] = 0.03;
            deepdza[24] = deepthick - 0.72;
            deepdza[25] = -1;
            deepdza[26] = -1;
            deepdza[27] = -1;
            deepdza[28] = -1;
            deepdza[29] = -1;
            
            deepnum = 25;
            
        }else if (deepthick <= 0.78){
            deepdza[0] = 0.03;
            deepdza[1] = 0.03;
            deepdza[2] = 0.03;
            deepdza[3] = 0.03;
            deepdza[4] = 0.03;
            deepdza[5] = 0.03;
            deepdza[6] = 0.03;
            deepdza[7] = 0.03;
            deepdza[8] = 0.03;
            deepdza[9] = 0.03;
            deepdza[10] = 0.03;
            deepdza[11] = 0.03;
            deepdza[12] = 0.03;
            deepdza[13] = 0.03;
            deepdza[14] = 0.03;
            deepdza[15] = 0.03;
            deepdza[16] = 0.03;
            deepdza[17] = 0.03;
            deepdza[18] = 0.03;
            deepdza[19] = 0.03;
            deepdza[20] = 0.03;
            deepdza[21] = 0.03;
            deepdza[22] = 0.03;
            deepdza[23] = 0.03;
            deepdza[24] = 0.03;
            deepdza[25] = deepthick - 0.75;
            deepdza[26] = -1;
            deepdza[27] = -1;
            deepdza[28] = -1;
            deepdza[29] = -1;
            
            deepnum = 26;
            
        }else if (deepthick <= 0.81){
            deepdza[0] = 0.03;
            deepdza[1] = 0.03;
            deepdza[2] = 0.03;
            deepdza[3] = 0.03;
            deepdza[4] = 0.03;
            deepdza[5] = 0.03;
            deepdza[6] = 0.03;
            deepdza[7] = 0.03;
            deepdza[8] = 0.03;
            deepdza[9] = 0.03;
            deepdza[10] = 0.03;
            deepdza[11] = 0.03;
            deepdza[12] = 0.03;
            deepdza[13] = 0.03;
            deepdza[14] = 0.03;
            deepdza[15] = 0.03;
            deepdza[16] = 0.03;
            deepdza[17] = 0.03;
            deepdza[18] = 0.03;
            deepdza[19] = 0.03;
            deepdza[20] = 0.03;
            deepdza[21] = 0.03;
            deepdza[22] = 0.03;
            deepdza[23] = 0.03;
            deepdza[24] = 0.03;
            deepdza[25] = 0.03;
            deepdza[26] = deepthick - 0.78;
            deepdza[27] = -1;
            deepdza[28] = -1;
            deepdza[29] = -1;
            
            deepnum = 27;
            
        }else if (deepthick <= 0.84){
            deepdza[0] = 0.03;
            deepdza[1] = 0.03;
            deepdza[2] = 0.03;
            deepdza[3] = 0.03;
            deepdza[4] = 0.03;
            deepdza[5] = 0.03;
            deepdza[6] = 0.03;
            deepdza[7] = 0.03;
            deepdza[8] = 0.03;
            deepdza[9] = 0.03;
            deepdza[10] = 0.03;
            deepdza[11] = 0.03;
            deepdza[12] = 0.03;
            deepdza[13] = 0.03;
            deepdza[14] = 0.03;
            deepdza[15] = 0.03;
            deepdza[16] = 0.03;
            deepdza[17] = 0.03;
            deepdza[18] = 0.03;
            deepdza[19] = 0.03;
            deepdza[20] = 0.03;
            deepdza[21] = 0.03;
            deepdza[22] = 0.03;
            deepdza[23] = 0.03;
            deepdza[24] = 0.03;
            deepdza[25] = 0.03;
            deepdza[26] = 0.03;
            deepdza[27] = deepthick - 0.81;
            deepdza[28] = -1;
            deepdza[29] = -1;
            
            deepnum = 28;
            
        }else if (deepthick <= 0.87){
            deepdza[0] = 0.03;
            deepdza[1] = 0.03;
            deepdza[2] = 0.03;
            deepdza[3] = 0.03;
            deepdza[4] = 0.03;
            deepdza[5] = 0.03;
            deepdza[6] = 0.03;
            deepdza[7] = 0.03;
            deepdza[8] = 0.03;
            deepdza[9] = 0.03;
            deepdza[10] = 0.03;
            deepdza[11] = 0.03;
            deepdza[12] = 0.03;
            deepdza[13] = 0.03;
            deepdza[14] = 0.03;
            deepdza[15] = 0.03;
            deepdza[16] = 0.03;
            deepdza[17] = 0.03;
            deepdza[18] = 0.03;
            deepdza[19] = 0.03;
            deepdza[20] = 0.03;
            deepdza[21] = 0.03;
            deepdza[22] = 0.03;
            deepdza[23] = 0.03;
            deepdza[24] = 0.03;
            deepdza[25] = 0.03;
            deepdza[26] = 0.03;
            deepdza[27] = 0.03;
            deepdza[28] = deepthick - 0.84;
            deepdza[29] = -1;
            
            deepnum = 29;
            
            
        }else if (deepthick <= 0.90){
            deepdza[0] = 0.03;
            deepdza[1] = 0.03;
            deepdza[2] = 0.03;
            deepdza[3] = 0.03;
            deepdza[4] = 0.03;
            deepdza[5] = 0.03;
            deepdza[6] = 0.03;
            deepdza[7] = 0.03;
            deepdza[8] = 0.03;
            deepdza[9] = 0.03;
            deepdza[10] = 0.03;
            deepdza[11] = 0.03;
            deepdza[12] = 0.03;
            deepdza[13] = 0.03;
            deepdza[14] = 0.03;
            deepdza[15] = 0.03;
            deepdza[16] = 0.03;
            deepdza[17] = 0.03;
            deepdza[18] = 0.03;
            deepdza[19] = 0.03;
            deepdza[20] = 0.03;
            deepdza[21] = 0.03;
            deepdza[22] = 0.03;
            deepdza[23] = 0.03;
            deepdza[24] = 0.03;
            deepdza[25] = 0.03;
            deepdza[26] = 0.03;
            deepdza[27] = 0.03;
            deepdza[28] = 0.03;
            deepdza[29] = deepthick - 0.87;
            
            deepnum = 30;
            
            
            
        } else {
            deepdza[0] = 0.03;
            deepdza[1] = 0.03;
            deepdza[2] = 0.03;
            deepdza[3] = 0.03;
            deepdza[4] = 0.03;
            deepdza[5] = 0.03;
            deepdza[6] = 0.03;
            deepdza[7] = 0.03;
            deepdza[8] = 0.03;
            deepdza[9] = 0.03;
            deepdza[10] = 0.03;
            deepdza[11] = 0.03;
            deepdza[12] = 0.03;
            deepdza[13] = 0.03;
            deepdza[14] = 0.03;
            deepdza[15] = 0.03;
            deepdza[16] = 0.03;
            deepdza[17] = 0.03;
            deepdza[18] = 0.03;
            deepdza[19] = 0.03;
            deepdza[20] = 0.03;
            deepdza[21] = 0.03;
            deepdza[22] = 0.03;
            deepdza[23] = 0.03;
            deepdza[24] = 0.03;
            deepdza[25] = 0.03;
            deepdza[26] = 0.03;
            deepdza[27] = 0.03;
            deepdza[28] = 0.03;
            deepdza[29] = deepthick - 0.87;
            
            deepnum = 30;
            
            
        }
       
    }
    
    
}

//
//void Peat::initDeepThicknesses(const double & thickness) {
//	olddeepthick = deepthick;
//
//	deepthick = thickness;
//	if (thickness < 0.0)
//		deepthick = 0.0;
//
//	deepnum = 0;
//
//	if (dlstshlw > 0) {
//		if (deepthick <= dlstshlw) { //dlstshlw = 0.02
//			deepdza[0] = deepthick;
//			deepdza[1] = -1;
//			deepdza[2] = -1;
//			deepdza[3] = -1;
//			deepdza[4] = -1;
//			deepdza[5] = -1;
//			deepdza[6] = -1;
//			deepdza[7] = -1;
//			deepdza[8] = -1;
//			deepdza[9] = -1;
//            deepdza[10] = -1;
//            deepdza[11] = -1;
//            deepdza[12] = -1;
//            deepdza[13] = -1;
//            deepdza[14] = -1;
//            deepdza[15] = -1;
//            deepdza[16] = -1;
//            deepdza[17] = -1;
//            deepdza[18] = -1;
//            deepdza[19] = -1;
//            deepdza[20] = -1;
//            deepdza[21] = -1;
//            deepdza[22] = -1;
//            deepdza[23] = -1;
//            deepdza[24] = -1;
//            deepdza[25] = -1;
//            deepdza[26] = -1;
//            deepdza[27] = -1;
//            deepdza[28] = -1;
//            deepdza[29] = -1;
//
//			deepnum = 1;
//		} else if (deepthick > dlstshlw && deepthick <= 2 * dlstshlw) {
//			deepdza[0] = 1. / 3. * deepthick;
//			deepdza[1] = 2. / 3. * deepthick;
//			deepdza[2] = -1;
//			deepdza[3] = -1;
//			deepdza[4] = -1;
//			deepdza[5] = -1;
//			deepdza[6] = -1;
//			deepdza[7] = -1;
//			deepdza[8] = -1;
//			deepdza[9] = -1;
//            deepdza[10] = -1;
//            deepdza[11] = -1;
//            deepdza[12] = -1;
//            deepdza[13] = -1;
//            deepdza[14] = -1;
//            deepdza[15] = -1;
//            deepdza[16] = -1;
//            deepdza[17] = -1;
//            deepdza[18] = -1;
//            deepdza[19] = -1;
//            deepdza[20] = -1;
//            deepdza[21] = -1;
//            deepdza[22] = -1;
//            deepdza[23] = -1;
//            deepdza[24] = -1;
//            deepdza[25] = -1;
//            deepdza[26] = -1;
//            deepdza[27] = -1;
//            deepdza[28] = -1;
//            deepdza[29] = -1;
//
//			deepnum = 2;
//		} else if (deepthick > 2 * dlstshlw && deepthick <= 3 * dlstshlw) {
//			deepdza[0] = 1. / 6. * deepthick;
//			deepdza[1] = 2. / 6. * deepthick;
//			deepdza[2] = 3. / 6. * deepthick;
//			deepdza[3] = -1;
//			deepdza[4] = -1;
//			deepdza[5] = -1;
//			deepdza[6] = -1;
//			deepdza[7] = -1;
//			deepdza[8] = -1;
//			deepdza[9] = -1;
//            deepdza[10] = -1;
//            deepdza[11] = -1;
//            deepdza[12] = -1;
//            deepdza[13] = -1;
//            deepdza[14] = -1;
//            deepdza[15] = -1;
//            deepdza[16] = -1;
//            deepdza[17] = -1;
//            deepdza[18] = -1;
//            deepdza[19] = -1;
//            deepdza[20] = -1;
//            deepdza[21] = -1;
//            deepdza[22] = -1;
//            deepdza[23] = -1;
//            deepdza[24] = -1;
//            deepdza[25] = -1;
//            deepdza[26] = -1;
//            deepdza[27] = -1;
//            deepdza[28] = -1;
//            deepdza[29] = -1;
//
//			deepnum = 3;
//		} else if (deepthick > 3 * dlstshlw && deepthick <= 4 * dlstshlw) {
//			deepdza[0] = 1. / 10. * deepthick;
//			deepdza[1] = 2. / 10. * deepthick;
//			deepdza[2] = 3. / 10. * deepthick;
//			deepdza[3] = 4. / 10. * deepthick;
//			deepdza[4] = -1;
//			deepdza[5] = -1;
//			deepdza[6] = -1;
//			deepdza[7] = -1;
//			deepdza[8] = -1;
//			deepdza[9] = -1;
//            deepdza[10] = -1;
//            deepdza[11] = -1;
//            deepdza[12] = -1;
//            deepdza[13] = -1;
//            deepdza[14] = -1;
//            deepdza[15] = -1;
//            deepdza[16] = -1;
//            deepdza[17] = -1;
//            deepdza[18] = -1;
//            deepdza[19] = -1;
//            deepdza[20] = -1;
//            deepdza[21] = -1;
//            deepdza[22] = -1;
//            deepdza[23] = -1;
//            deepdza[24] = -1;
//            deepdza[25] = -1;
//            deepdza[26] = -1;
//            deepdza[27] = -1;
//            deepdza[28] = -1;
//            deepdza[29] = -1;
//
//			deepnum = 4;
//		} else if (deepthick > 4 * dlstshlw && deepthick <= 5 * dlstshlw) {
//			deepdza[0] = 1. / 15. * deepthick;
//			deepdza[1] = 2. / 15. * deepthick;
//			deepdza[2] = 3. / 15. * deepthick;
//			deepdza[3] = 4. / 15. * deepthick;
//			deepdza[4] = 5. / 15. * deepthick;
//			deepdza[5] = -1;
//			deepdza[6] = -1;
//			deepdza[7] = -1;
//			deepdza[8] = -1;
//			deepdza[9] = -1;
//            deepdza[10] = -1;
//            deepdza[11] = -1;
//            deepdza[12] = -1;
//            deepdza[13] = -1;
//            deepdza[14] = -1;
//            deepdza[15] = -1;
//            deepdza[16] = -1;
//            deepdza[17] = -1;
//            deepdza[18] = -1;
//            deepdza[19] = -1;
//            deepdza[20] = -1;
//            deepdza[21] = -1;
//            deepdza[22] = -1;
//            deepdza[23] = -1;
//            deepdza[24] = -1;
//            deepdza[25] = -1;
//            deepdza[26] = -1;
//            deepdza[27] = -1;
//            deepdza[28] = -1;
//            deepdza[29] = -1;
//
//			deepnum = 5;
//		} else if (deepthick > 5 * dlstshlw && deepthick <= 6 * dlstshlw) {
//			deepdza[0] = 1. / 21. * deepthick;
//			deepdza[1] = 2. / 21. * deepthick;
//			deepdza[2] = 3. / 21. * deepthick;
//			deepdza[3] = 4. / 21. * deepthick;
//			deepdza[4] = 5. / 21. * deepthick;
//			deepdza[5] = 6. / 21. * deepthick;
//			deepdza[6] = -1;
//			deepdza[7] = -1;
//			deepdza[8] = -1;
//			deepdza[9] = -1;
//            deepdza[10] = -1;
//            deepdza[11] = -1;
//            deepdza[12] = -1;
//            deepdza[13] = -1;
//            deepdza[14] = -1;
//            deepdza[15] = -1;
//            deepdza[16] = -1;
//            deepdza[17] = -1;
//            deepdza[18] = -1;
//            deepdza[19] = -1;
//            deepdza[20] = -1;
//            deepdza[21] = -1;
//            deepdza[22] = -1;
//            deepdza[23] = -1;
//            deepdza[24] = -1;
//            deepdza[25] = -1;
//            deepdza[26] = -1;
//            deepdza[27] = -1;
//            deepdza[28] = -1;
//            deepdza[29] = -1;
//
//			deepnum = 6;
//		} else if (deepthick > 6 * dlstshlw && deepthick <= 7 * dlstshlw) {
//			deepdza[0] = 1. / 28. * deepthick;
//			deepdza[1] = 2. / 28. * deepthick;
//			deepdza[2] = 3. / 28. * deepthick;
//			deepdza[3] = 4. / 28. * deepthick;
//			deepdza[4] = 5. / 28. * deepthick;
//			deepdza[5] = 6. / 28. * deepthick;
//			deepdza[6] = 7. / 28. * deepthick;
//			deepdza[7] = -1;
//			deepdza[8] = -1;
//			deepdza[9] = -1;
//            deepdza[10] = -1;
//            deepdza[11] = -1;
//            deepdza[12] = -1;
//            deepdza[13] = -1;
//            deepdza[14] = -1;
//            deepdza[15] = -1;
//            deepdza[16] = -1;
//            deepdza[17] = -1;
//            deepdza[18] = -1;
//            deepdza[19] = -1;
//            deepdza[20] = -1;
//            deepdza[21] = -1;
//            deepdza[22] = -1;
//            deepdza[23] = -1;
//            deepdza[24] = -1;
//            deepdza[25] = -1;
//            deepdza[26] = -1;
//            deepdza[27] = -1;
//            deepdza[28] = -1;
//            deepdza[29] = -1;
//
//			deepnum = 7;
//		} else if (deepthick > 7 * dlstshlw && deepthick <= 8 * dlstshlw) {
//			deepdza[0] = 1. / 36. * deepthick;
//			deepdza[1] = 2. / 36. * deepthick;
//			deepdza[2] = 3. / 36. * deepthick;
//			deepdza[3] = 4. / 36. * deepthick;
//			deepdza[4] = 5. / 36. * deepthick;
//			deepdza[5] = 6. / 36. * deepthick;
//			deepdza[6] = 7. / 36. * deepthick;
//			deepdza[7] = 8. / 36. * deepthick;
//			deepdza[8] = -1;
//			deepdza[9] = -1;
//            deepdza[10] = -1;
//            deepdza[11] = -1;
//            deepdza[12] = -1;
//            deepdza[13] = -1;
//            deepdza[14] = -1;
//            deepdza[15] = -1;
//            deepdza[16] = -1;
//            deepdza[17] = -1;
//            deepdza[18] = -1;
//            deepdza[19] = -1;
//            deepdza[20] = -1;
//            deepdza[21] = -1;
//            deepdza[22] = -1;
//            deepdza[23] = -1;
//            deepdza[24] = -1;
//            deepdza[25] = -1;
//            deepdza[26] = -1;
//            deepdza[27] = -1;
//            deepdza[28] = -1;
//            deepdza[29] = -1;
//
//			deepnum = 8;
//		} else if (deepthick > 8 * dlstshlw && deepthick <= 9 * dlstshlw) {
//			deepdza[0] = 1. / 45. * deepthick;
//			deepdza[1] = 2. / 45. * deepthick;
//			deepdza[2] = 3. / 45. * deepthick;
//			deepdza[3] = 4. / 45. * deepthick;
//			deepdza[4] = 5. / 45. * deepthick;
//			deepdza[5] = 6. / 45. * deepthick;
//			deepdza[6] = 7. / 45. * deepthick;
//			deepdza[7] = 8. / 45. * deepthick;
//			deepdza[8] = 9. / 45. * deepthick;
//			deepdza[9] = -1;
//            deepdza[10] = -1;
//            deepdza[11] = -1;
//            deepdza[12] = -1;
//            deepdza[13] = -1;
//            deepdza[14] = -1;
//            deepdza[15] = -1;
//            deepdza[16] = -1;
//            deepdza[17] = -1;
//            deepdza[18] = -1;
//            deepdza[19] = -1;
//            deepdza[20] = -1;
//            deepdza[21] = -1;
//            deepdza[22] = -1;
//            deepdza[23] = -1;
//            deepdza[24] = -1;
//            deepdza[25] = -1;
//            deepdza[26] = -1;
//            deepdza[27] = -1;
//            deepdza[28] = -1;
//            deepdza[29] = -1;
//
//			deepnum = 9;
//        }else if (deepthick > 9 * dlstshlw && deepthick <= 10 * dlstshlw){
//			deepdza[0] = 1. / 55. * deepthick;
//			deepdza[1] = 2. / 55. * deepthick;
//			deepdza[2] = 3. / 55. * deepthick;
//			deepdza[3] = 4. / 55. * deepthick;
//			deepdza[4] = 5. / 55. * deepthick;
//			deepdza[5] = 6. / 55. * deepthick;
//			deepdza[6] = 7. / 55. * deepthick;
//			deepdza[7] = 8. / 55. * deepthick;
//			deepdza[8] = 9. / 55. * deepthick;
//			deepdza[9] = 10. / 55. * deepthick;
//            deepdza[10] = -1;
//            deepdza[11] = -1;
//            deepdza[12] = -1;
//            deepdza[13] = -1;
//            deepdza[14] = -1;
//            deepdza[15] = -1;
//            deepdza[16] = -1;
//            deepdza[17] = -1;
//            deepdza[18] = -1;
//            deepdza[19] = -1;
//            deepdza[20] = -1;
//            deepdza[21] = -1;
//            deepdza[22] = -1;
//            deepdza[23] = -1;
//            deepdza[24] = -1;
//            deepdza[25] = -1;
//            deepdza[26] = -1;
//            deepdza[27] = -1;
//            deepdza[28] = -1;
//            deepdza[29] = -1;
//
//			deepnum = 10;
//        }else if (deepthick > 10 * dlstshlw && deepthick <= 11 * dlstshlw){
//            deepdza[0] = 1. / 66. * deepthick;
//            deepdza[1] = 2. / 66. * deepthick;
//            deepdza[2] = 3. / 66. * deepthick;
//            deepdza[3] = 4. / 66. * deepthick;
//            deepdza[4] = 5. / 66. * deepthick;
//            deepdza[5] = 6. / 66. * deepthick;
//            deepdza[6] = 7. / 66. * deepthick;
//            deepdza[7] = 8. / 66. * deepthick;
//            deepdza[8] = 9. / 66. * deepthick;
//            deepdza[9] = 10. / 66. * deepthick;
//            deepdza[10] = 11. / 66. * deepthick;
//            deepdza[11] = -1;
//            deepdza[12] = -1;
//            deepdza[13] = -1;
//            deepdza[14] = -1;
//            deepdza[15] = -1;
//            deepdza[16] = -1;
//            deepdza[17] = -1;
//            deepdza[18] = -1;
//            deepdza[19] = -1;
//            deepdza[20] = -1;
//            deepdza[21] = -1;
//            deepdza[22] = -1;
//            deepdza[23] = -1;
//            deepdza[24] = -1;
//            deepdza[25] = -1;
//            deepdza[26] = -1;
//            deepdza[27] = -1;
//            deepdza[28] = -1;
//            deepdza[29] = -1;
//            
//            deepnum = 11;
//            
//        }else if (deepthick > 11 * dlstshlw && deepthick <= 12 * dlstshlw){
//            deepdza[0] = 1. / 78. * deepthick;
//            deepdza[1] = 2. / 78. * deepthick;
//            deepdza[2] = 3. / 78. * deepthick;
//            deepdza[3] = 4. / 78. * deepthick;
//            deepdza[4] = 5. / 78. * deepthick;
//            deepdza[5] = 6. / 78. * deepthick;
//            deepdza[6] = 7. / 78. * deepthick;
//            deepdza[7] = 8. / 78. * deepthick;
//            deepdza[8] = 9. / 78. * deepthick;
//            deepdza[9] = 10. / 78. * deepthick;
//            deepdza[10] = 11. / 78. * deepthick;
//            deepdza[11] = 12. / 78. * deepthick;
//            deepdza[12] = -1;
//            deepdza[13] = -1;
//            deepdza[14] = -1;
//            deepdza[15] = -1;
//            deepdza[16] = -1;
//            deepdza[17] = -1;
//            deepdza[18] = -1;
//            deepdza[19] = -1;
//            deepdza[20] = -1;
//            deepdza[21] = -1;
//            deepdza[22] = -1;
//            deepdza[23] = -1;
//            deepdza[24] = -1;
//            deepdza[25] = -1;
//            deepdza[26] = -1;
//            deepdza[27] = -1;
//            deepdza[28] = -1;
//            deepdza[29] = -1;
//            
//            deepnum = 12;
//            
//        }else if (deepthick > 12 * dlstshlw && deepthick <= 13 * dlstshlw){
//            deepdza[0] = 1. / 91. * deepthick;
//            deepdza[1] = 2. / 91. * deepthick;
//            deepdza[2] = 3. / 91. * deepthick;
//            deepdza[3] = 4. / 91. * deepthick;
//            deepdza[4] = 5. / 91. * deepthick;
//            deepdza[5] = 6. / 91. * deepthick;
//            deepdza[6] = 7. / 91. * deepthick;
//            deepdza[7] = 8. / 91. * deepthick;
//            deepdza[8] = 9. / 91. * deepthick;
//            deepdza[9] = 10. / 91. * deepthick;
//            deepdza[10] = 11. / 91. * deepthick;
//            deepdza[11] = 12. / 91. * deepthick;
//            deepdza[12] = 13. / 91. * deepthick;
//            deepdza[13] = -1;
//            deepdza[14] = -1;
//            deepdza[14] = -1;
//            deepdza[15] = -1;
//            deepdza[16] = -1;
//            deepdza[17] = -1;
//            deepdza[18] = -1;
//            deepdza[19] = -1;
//            deepdza[20] = -1;
//            deepdza[21] = -1;
//            deepdza[22] = -1;
//            deepdza[23] = -1;
//            deepdza[24] = -1;
//            deepdza[25] = -1;
//            deepdza[26] = -1;
//            deepdza[27] = -1;
//            deepdza[28] = -1;
//            deepdza[29] = -1;
//            
//            
//            deepnum = 13;
//            
//        }else if (deepthick > 13 * dlstshlw && deepthick <= 14 * dlstshlw){
//            deepdza[0] = 1. / 105. * deepthick;
//            deepdza[1] = 2. / 105. * deepthick;
//            deepdza[2] = 3. / 105. * deepthick;
//            deepdza[3] = 4. / 105. * deepthick;
//            deepdza[4] = 5. / 105. * deepthick;
//            deepdza[5] = 6. / 105. * deepthick;
//            deepdza[6] = 7. / 105. * deepthick;
//            deepdza[7] = 8. / 105. * deepthick;
//            deepdza[8] = 9. / 105. * deepthick;
//            deepdza[9] = 10. / 105. * deepthick;
//            deepdza[10] = 11. / 105. * deepthick;
//            deepdza[11] = 12. / 105. * deepthick;
//            deepdza[12] = 13. / 105. * deepthick;
//            deepdza[13] = 14. / 105. * deepthick;
//            deepdza[14] = -1;
//            deepdza[14] = -1;
//            deepdza[15] = -1;
//            deepdza[16] = -1;
//            deepdza[17] = -1;
//            deepdza[18] = -1;
//            deepdza[19] = -1;
//            deepdza[20] = -1;
//            deepdza[21] = -1;
//            deepdza[22] = -1;
//            deepdza[23] = -1;
//            deepdza[24] = -1;
//            deepdza[25] = -1;
//            deepdza[26] = -1;
//            deepdza[27] = -1;
//            deepdza[28] = -1;
//            deepdza[29] = -1;
//            
//            deepnum = 14;
//            
//        }else if (deepthick > 14 * dlstshlw && deepthick <= 15 * dlstshlw){
//            deepdza[0] = 1. / 120. * deepthick;
//            deepdza[1] = 2. / 120. * deepthick;
//            deepdza[2] = 3. / 120. * deepthick;
//            deepdza[3] = 4. / 120. * deepthick;
//            deepdza[4] = 5. / 120. * deepthick;
//            deepdza[5] = 6. / 120. * deepthick;
//            deepdza[6] = 7. / 120. * deepthick;
//            deepdza[7] = 8. / 120. * deepthick;
//            deepdza[8] = 9. / 120. * deepthick;
//            deepdza[9] = 10. / 120. * deepthick;
//            deepdza[10] = 11. / 120. * deepthick;
//            deepdza[11] = 12. / 120. * deepthick;
//            deepdza[12] = 13. / 120. * deepthick;
//            deepdza[13] = 14. / 120. * deepthick;
//            deepdza[14] = 15. / 120. * deepthick;
//            deepdza[15] = -1;
//            deepdza[16] = -1;
//            deepdza[17] = -1;
//            deepdza[18] = -1;
//            deepdza[19] = -1;
//            deepdza[20] = -1;
//            deepdza[21] = -1;
//            deepdza[22] = -1;
//            deepdza[23] = -1;
//            deepdza[24] = -1;
//            deepdza[25] = -1;
//            deepdza[26] = -1;
//            deepdza[27] = -1;
//            deepdza[28] = -1;
//            deepdza[29] = -1;
//            
//            deepnum = 15;
//            
//        }else if (deepthick > 15 * dlstshlw && deepthick <= 16 * dlstshlw){
//            deepdza[0] = 1. / 136. * deepthick;
//            deepdza[1] = 2. / 136. * deepthick;
//            deepdza[2] = 3. / 136. * deepthick;
//            deepdza[3] = 4. / 136. * deepthick;
//            deepdza[4] = 5. / 136. * deepthick;
//            deepdza[5] = 6. / 136. * deepthick;
//            deepdza[6] = 7. / 136. * deepthick;
//            deepdza[7] = 8. / 136. * deepthick;
//            deepdza[8] = 9. / 136. * deepthick;
//            deepdza[9] = 10. / 136. * deepthick;
//            deepdza[10] = 11. / 136. * deepthick;
//            deepdza[11] = 12. / 136. * deepthick;
//            deepdza[12] = 13. / 136. * deepthick;
//            deepdza[13] = 14. / 136. * deepthick;
//            deepdza[14] = 15. / 136. * deepthick;
//            deepdza[15] = 16. / 136. * deepthick;
//            
//            deepdza[16] = -1;
//            deepdza[17] = -1;
//            deepdza[18] = -1;
//            deepdza[19] = -1;
//            deepdza[20] = -1;
//            deepdza[21] = -1;
//            deepdza[22] = -1;
//            deepdza[23] = -1;
//            deepdza[24] = -1;
//            deepdza[25] = -1;
//            deepdza[26] = -1;
//            deepdza[27] = -1;
//            deepdza[28] = -1;
//            deepdza[29] = -1;
//            
//            deepnum = 16;
//            
//        }else if (deepthick > 16 * dlstshlw && deepthick <= 17 * dlstshlw){
//            deepdza[0] = 1. / 153. * deepthick;
//            deepdza[1] = 2. / 153. * deepthick;
//            deepdza[2] = 3. / 153. * deepthick;
//            deepdza[3] = 4. / 153. * deepthick;
//            deepdza[4] = 5. / 153. * deepthick;
//            deepdza[5] = 6. / 153. * deepthick;
//            deepdza[6] = 7. / 153. * deepthick;
//            deepdza[7] = 8. / 153. * deepthick;
//            deepdza[8] = 9. / 153. * deepthick;
//            deepdza[9] = 10. / 153. * deepthick;
//            deepdza[10] = 11. / 153. * deepthick;
//            deepdza[11] = 12. / 153. * deepthick;
//            deepdza[12] = 13. / 153. * deepthick;
//            deepdza[13] = 14. / 153. * deepthick;
//            deepdza[14] = 15. / 153. * deepthick;
//            deepdza[15] = 16. / 153. * deepthick;
//            deepdza[16] = 17. / 153. * deepthick;
//            
//            deepdza[17] = -1;
//            deepdza[18] = -1;
//            deepdza[19] = -1;
//            deepdza[20] = -1;
//            deepdza[21] = -1;
//            deepdza[22] = -1;
//            deepdza[23] = -1;
//            deepdza[24] = -1;
//            deepdza[25] = -1;
//            deepdza[26] = -1;
//            deepdza[27] = -1;
//            deepdza[28] = -1;
//            deepdza[29] = -1;
//            
//            deepnum = 17;
//            
//        }else if (deepthick > 17 * dlstshlw && deepthick <= 18 * dlstshlw){
//            deepdza[0] = 1. / 171. * deepthick;
//            deepdza[1] = 2. / 171. * deepthick;
//            deepdza[2] = 3. / 171. * deepthick;
//            deepdza[3] = 4. / 171. * deepthick;
//            deepdza[4] = 5. / 171. * deepthick;
//            deepdza[5] = 6. / 171. * deepthick;
//            deepdza[6] = 7. / 171. * deepthick;
//            deepdza[7] = 8. / 171. * deepthick;
//            deepdza[8] = 9. / 171. * deepthick;
//            deepdza[9] = 10. / 171. * deepthick;
//            deepdza[10] = 11. / 171. * deepthick;
//            deepdza[11] = 12. / 171. * deepthick;
//            deepdza[12] = 13. / 171. * deepthick;
//            deepdza[13] = 14. / 171. * deepthick;
//            deepdza[14] = 15. / 171. * deepthick;
//            deepdza[15] = 16. / 171. * deepthick;
//            deepdza[16] = 17. / 171. * deepthick;
//            deepdza[17] = 18. / 171. * deepthick;
//            
//            deepdza[18] = -1;
//            deepdza[19] = -1;
//            deepdza[20] = -1;
//            deepdza[21] = -1;
//            deepdza[22] = -1;
//            deepdza[23] = -1;
//            deepdza[24] = -1;
//            deepdza[25] = -1;
//            deepdza[26] = -1;
//            deepdza[27] = -1;
//            deepdza[28] = -1;
//            deepdza[29] = -1;
//            
//            deepnum = 18;
//            
//        }else if (deepthick > 18 * dlstshlw && deepthick <= 19 * dlstshlw){
//            deepdza[0] = 1. / 190. * deepthick;
//            deepdza[1] = 2. / 190. * deepthick;
//            deepdza[2] = 3. / 190. * deepthick;
//            deepdza[3] = 4. / 190. * deepthick;
//            deepdza[4] = 5. / 190. * deepthick;
//            deepdza[5] = 6. / 190. * deepthick;
//            deepdza[6] = 7. / 190. * deepthick;
//            deepdza[7] = 8. / 190. * deepthick;
//            deepdza[8] = 9. / 190. * deepthick;
//            deepdza[9] = 10. / 190. * deepthick;
//            deepdza[10] = 11. / 190. * deepthick;
//            deepdza[11] = 12. / 190. * deepthick;
//            deepdza[12] = 13. / 190. * deepthick;
//            deepdza[13] = 14. / 190. * deepthick;
//            deepdza[14] = 15. / 190. * deepthick;
//            deepdza[15] = 16. / 190. * deepthick;
//            deepdza[16] = 17. / 190. * deepthick;
//            deepdza[17] = 18. / 190. * deepthick;
//            deepdza[18] = 19. / 190. * deepthick;
//            deepdza[19] = -1;
//            deepdza[20] = -1;
//            deepdza[21] = -1;
//            deepdza[22] = -1;
//            deepdza[23] = -1;
//            deepdza[24] = -1;
//            deepdza[25] = -1;
//            deepdza[26] = -1;
//            deepdza[27] = -1;
//            deepdza[28] = -1;
//            deepdza[29] = -1;
//            
//            
//            deepnum = 19;
//            
//        }else if (deepthick > 19 * dlstshlw && deepthick <= 20 * dlstshlw){
//            deepdza[0] = 1. / 210. * deepthick;
//            deepdza[1] = 2. / 210. * deepthick;
//            deepdza[2] = 3. / 210. * deepthick;
//            deepdza[3] = 4. / 210. * deepthick;
//            deepdza[4] = 5. / 210. * deepthick;
//            deepdza[5] = 6. / 210. * deepthick;
//            deepdza[6] = 7. / 210. * deepthick;
//            deepdza[7] = 8. / 210. * deepthick;
//            deepdza[8] = 9. / 210. * deepthick;
//            deepdza[9] = 10. / 210. * deepthick;
//            deepdza[10] = 11. / 210. * deepthick;
//            deepdza[11] = 12. / 210. * deepthick;
//            deepdza[12] = 13. / 210. * deepthick;
//            deepdza[13] = 14. / 210. * deepthick;
//            deepdza[14] = 15. / 210. * deepthick;
//            deepdza[15] = 16. / 210. * deepthick;
//            deepdza[16] = 17. / 210. * deepthick;
//            deepdza[17] = 18. / 210. * deepthick;
//            deepdza[18] = 19. / 210. * deepthick;
//            deepdza[19] = 20. / 210. * deepthick;
//            deepdza[20] = -1;
//            deepdza[21] = -1;
//            deepdza[22] = -1;
//            deepdza[23] = -1;
//            deepdza[24] = -1;
//            deepdza[25] = -1;
//            deepdza[26] = -1;
//            deepdza[27] = -1;
//            deepdza[28] = -1;
//            deepdza[29] = -1;
//            
//            deepnum = 20;
//            
//        }else if (deepthick > 20 * dlstshlw && deepthick <= 21 * dlstshlw){
//            deepdza[0] = 1. / 231. * deepthick;
//            deepdza[1] = 2. / 231. * deepthick;
//            deepdza[2] = 3. / 231. * deepthick;
//            deepdza[3] = 4. / 231. * deepthick;
//            deepdza[4] = 5. / 231. * deepthick;
//            deepdza[5] = 6. / 231. * deepthick;
//            deepdza[6] = 7. / 231. * deepthick;
//            deepdza[7] = 8. / 231. * deepthick;
//            deepdza[8] = 9. / 231. * deepthick;
//            deepdza[9] = 10. / 231. * deepthick;
//            deepdza[10] = 11. / 231. * deepthick;
//            deepdza[11] = 12. / 231. * deepthick;
//            deepdza[12] = 13. / 231. * deepthick;
//            deepdza[13] = 14. / 231. * deepthick;
//            deepdza[14] = 15. / 231. * deepthick;
//            deepdza[15] = 16. / 231. * deepthick;
//            deepdza[16] = 17. / 231. * deepthick;
//            deepdza[17] = 18. / 231. * deepthick;
//            deepdza[18] = 19. / 231. * deepthick;
//            deepdza[19] = 20. / 231. * deepthick;
//            deepdza[20] = 21. / 231. * deepthick;
//            deepdza[21] = -1;
//            deepdza[22] = -1;
//            deepdza[23] = -1;
//            deepdza[24] = -1;
//            deepdza[25] = -1;
//            deepdza[26] = -1;
//            deepdza[27] = -1;
//            deepdza[28] = -1;
//            deepdza[29] = -1;
//            
//            deepnum = 21;
//            
//        }else if (deepthick > 21 * dlstshlw && deepthick <= 21 * dlstshlw){
//            deepdza[0] = 1. / 253. * deepthick;
//            deepdza[1] = 2. / 253. * deepthick;
//            deepdza[2] = 3. / 253. * deepthick;
//            deepdza[3] = 4. / 253. * deepthick;
//            deepdza[4] = 5. / 253. * deepthick;
//            deepdza[5] = 6. / 253. * deepthick;
//            deepdza[6] = 7. / 253. * deepthick;
//            deepdza[7] = 8. / 253. * deepthick;
//            deepdza[8] = 9. / 253. * deepthick;
//            deepdza[9] = 10. / 253. * deepthick;
//            deepdza[10] = 11. / 253. * deepthick;
//            deepdza[11] = 12. / 253. * deepthick;
//            deepdza[12] = 13. / 253. * deepthick;
//            deepdza[13] = 14. / 253. * deepthick;
//            deepdza[14] = 15. / 253. * deepthick;
//            deepdza[15] = 16. / 253. * deepthick;
//            deepdza[16] = 17. / 253. * deepthick;
//            deepdza[17] = 18. / 253. * deepthick;
//            deepdza[18] = 19. / 253. * deepthick;
//            deepdza[19] = 20. / 253. * deepthick;
//            deepdza[20] = 21. / 253. * deepthick;
//            deepdza[21] = 22. / 253. * deepthick;
//            deepdza[22] = -1;
//            deepdza[23] = -1;
//            deepdza[24] = -1;
//            deepdza[25] = -1;
//            deepdza[26] = -1;
//            deepdza[27] = -1;
//            deepdza[28] = -1;
//            deepdza[29] = -1;
//            
//            deepnum = 22;
//            
//        }else if (deepthick > 22 * dlstshlw && deepthick <= 23 * dlstshlw){
//            deepdza[0] = 1. / 276. * deepthick;
//            deepdza[1] = 2. / 276. * deepthick;
//            deepdza[2] = 3. / 276. * deepthick;
//            deepdza[3] = 4. / 276. * deepthick;
//            deepdza[4] = 5. / 276. * deepthick;
//            deepdza[5] = 6. / 276. * deepthick;
//            deepdza[6] = 7. / 276. * deepthick;
//            deepdza[7] = 8. / 276. * deepthick;
//            deepdza[8] = 9. / 276. * deepthick;
//            deepdza[9] = 10. / 276. * deepthick;
//            deepdza[10] = 11. / 276. * deepthick;
//            deepdza[11] = 12. / 276. * deepthick;
//            deepdza[12] = 13. / 276. * deepthick;
//            deepdza[13] = 14. / 276. * deepthick;
//            deepdza[14] = 15. / 276. * deepthick;
//            deepdza[15] = 16. / 276. * deepthick;
//            deepdza[16] = 17. / 276. * deepthick;
//            deepdza[17] = 18. / 276. * deepthick;
//            deepdza[18] = 19. / 276. * deepthick;
//            deepdza[19] = 20. / 276. * deepthick;
//            deepdza[20] = 21. / 276. * deepthick;
//            deepdza[21] = 22. / 276. * deepthick;
//            deepdza[22] = 23. / 276. * deepthick;
//            deepdza[23] = -1;
//            deepdza[24] = -1;
//            deepdza[25] = -1;
//            deepdza[26] = -1;
//            deepdza[27] = -1;
//            deepdza[28] = -1;
//            deepdza[29] = -1;
//            
//            deepnum = 23;
//            
//        }else if (deepthick > 23 * dlstshlw && deepthick <= 24 * dlstshlw){
//            deepdza[0] = 1. / 300. * deepthick;
//            deepdza[1] = 2. / 300. * deepthick;
//            deepdza[2] = 3. / 300. * deepthick;
//            deepdza[3] = 4. / 300. * deepthick;
//            deepdza[4] = 5. / 300. * deepthick;
//            deepdza[5] = 6. / 300. * deepthick;
//            deepdza[6] = 7. / 300. * deepthick;
//            deepdza[7] = 8. / 300. * deepthick;
//            deepdza[8] = 9. / 300. * deepthick;
//            deepdza[9] = 10. / 300. * deepthick;
//            deepdza[10] = 11. / 300. * deepthick;
//            deepdza[11] = 12. / 300. * deepthick;
//            deepdza[12] = 13. / 300. * deepthick;
//            deepdza[13] = 14. / 300. * deepthick;
//            deepdza[14] = 15. / 300. * deepthick;
//            deepdza[15] = 16. / 300. * deepthick;
//            deepdza[16] = 17. / 300. * deepthick;
//            deepdza[17] = 18. / 300. * deepthick;
//            deepdza[18] = 19. / 300. * deepthick;
//            deepdza[19] = 20. / 300. * deepthick;
//            deepdza[20] = 21. / 300. * deepthick;
//            deepdza[21] = 22. / 300. * deepthick;
//            deepdza[22] = 23. / 300. * deepthick;
//            deepdza[23] = 24. / 300. * deepthick;
//            deepdza[24] = -1;
//            deepdza[25] = -1;
//            deepdza[26] = -1;
//            deepdza[27] = -1;
//            deepdza[28] = -1;
//            deepdza[29] = -1;
//            
//            deepnum = 24;
//            
//        }else if (deepthick > 24 * dlstshlw && deepthick <= 25 * dlstshlw){
//            deepdza[0] = 1. / 325. * deepthick;
//            deepdza[1] = 2. / 325. * deepthick;
//            deepdza[2] = 3. / 325. * deepthick;
//            deepdza[3] = 4. / 325. * deepthick;
//            deepdza[4] = 5. / 325. * deepthick;
//            deepdza[5] = 6. / 325. * deepthick;
//            deepdza[6] = 7. / 325. * deepthick;
//            deepdza[7] = 8. / 325. * deepthick;
//            deepdza[8] = 9. / 325. * deepthick;
//            deepdza[9] = 10. / 325. * deepthick;
//            deepdza[10] = 11. / 325. * deepthick;
//            deepdza[11] = 12. / 325. * deepthick;
//            deepdza[12] = 13. / 325. * deepthick;
//            deepdza[13] = 14. / 325. * deepthick;
//            deepdza[14] = 15. / 325. * deepthick;
//            deepdza[15] = 16. / 325. * deepthick;
//            deepdza[16] = 17. / 325. * deepthick;
//            deepdza[17] = 18. / 325. * deepthick;
//            deepdza[18] = 19. / 325. * deepthick;
//            deepdza[19] = 20. / 325. * deepthick;
//            deepdza[20] = 21. / 325. * deepthick;
//            deepdza[21] = 22. / 325. * deepthick;
//            deepdza[22] = 23. / 325. * deepthick;
//            deepdza[23] = 24. / 325. * deepthick;
//            deepdza[24] = 25. / 325. * deepthick;
//            deepdza[25] = -1;
//            deepdza[26] = -1;
//            deepdza[27] = -1;
//            deepdza[28] = -1;
//            deepdza[29] = -1;
//            
//            deepnum = 25;
//            
//        }else if (deepthick > 25 * dlstshlw && deepthick <= 26 * dlstshlw){
//            deepdza[0] = 1. / 351. * deepthick;
//            deepdza[1] = 2. / 351. * deepthick;
//            deepdza[2] = 3. / 351. * deepthick;
//            deepdza[3] = 4. / 351. * deepthick;
//            deepdza[4] = 5. / 351. * deepthick;
//            deepdza[5] = 6. / 351. * deepthick;
//            deepdza[6] = 7. / 351. * deepthick;
//            deepdza[7] = 8. / 351. * deepthick;
//            deepdza[8] = 9. / 351. * deepthick;
//            deepdza[9] = 10. / 351. * deepthick;
//            deepdza[10] = 11. / 351. * deepthick;
//            deepdza[11] = 12. / 351. * deepthick;
//            deepdza[12] = 13. / 351. * deepthick;
//            deepdza[13] = 14. / 351. * deepthick;
//            deepdza[14] = 15. / 351. * deepthick;
//            deepdza[15] = 16. / 351. * deepthick;
//            deepdza[16] = 17. / 351. * deepthick;
//            deepdza[17] = 18. / 351. * deepthick;
//            deepdza[18] = 19. / 351. * deepthick;
//            deepdza[19] = 20. / 351. * deepthick;
//            deepdza[20] = 21. / 351. * deepthick;
//            deepdza[21] = 22. / 351. * deepthick;
//            deepdza[22] = 23. / 351. * deepthick;
//            deepdza[23] = 24. / 351. * deepthick;
//            deepdza[24] = 25. / 351. * deepthick;
//            deepdza[25] = 26. / 351. * deepthick;
//            deepdza[26] = -1;
//            deepdza[27] = -1;
//            deepdza[28] = -1;
//            deepdza[29] = -1;
//            
//            deepnum = 26;
//            
//        }else if (deepthick > 26 * dlstshlw && deepthick <= 27 * dlstshlw){
//            deepdza[0] = 1. / 378. * deepthick;
//            deepdza[1] = 2. / 378. * deepthick;
//            deepdza[2] = 3. / 378. * deepthick;
//            deepdza[3] = 4. / 378. * deepthick;
//            deepdza[4] = 5. / 378. * deepthick;
//            deepdza[5] = 6. / 378. * deepthick;
//            deepdza[6] = 7. / 378. * deepthick;
//            deepdza[7] = 8. / 378. * deepthick;
//            deepdza[8] = 9. / 378. * deepthick;
//            deepdza[9] = 10. / 378. * deepthick;
//            deepdza[10] = 11. / 378. * deepthick;
//            deepdza[11] = 12. / 378. * deepthick;
//            deepdza[12] = 13. / 378. * deepthick;
//            deepdza[13] = 14. / 378. * deepthick;
//            deepdza[14] = 15. / 378. * deepthick;
//            deepdza[15] = 16. / 378. * deepthick;
//            deepdza[16] = 17. / 378. * deepthick;
//            deepdza[17] = 18. / 378. * deepthick;
//            deepdza[18] = 19. / 378. * deepthick;
//            deepdza[19] = 20. / 378. * deepthick;
//            deepdza[20] = 21. / 378. * deepthick;
//            deepdza[21] = 22. / 378. * deepthick;
//            deepdza[22] = 23. / 378. * deepthick;
//            deepdza[23] = 24. / 378. * deepthick;
//            deepdza[24] = 25. / 378. * deepthick;
//            deepdza[25] = 26. / 378. * deepthick;
//            deepdza[26] = 27. / 378. * deepthick;
//            deepdza[27] = -1;
//            deepdza[28] = -1;
//            deepdza[29] = -1;
//            
//            deepnum = 27;
//            
//        }else if (deepthick > 27 * dlstshlw && deepthick <= 28 * dlstshlw){
//            deepdza[0] = 1. / 406. * deepthick;
//            deepdza[1] = 2. / 406. * deepthick;
//            deepdza[2] = 3. / 406. * deepthick;
//            deepdza[3] = 4. / 406. * deepthick;
//            deepdza[4] = 5. / 406. * deepthick;
//            deepdza[5] = 6. / 406. * deepthick;
//            deepdza[6] = 7. / 406. * deepthick;
//            deepdza[7] = 8. / 406. * deepthick;
//            deepdza[8] = 9. / 406. * deepthick;
//            deepdza[9] = 10. / 406. * deepthick;
//            deepdza[10] = 11. / 406. * deepthick;
//            deepdza[11] = 12. / 406. * deepthick;
//            deepdza[12] = 13. / 406. * deepthick;
//            deepdza[13] = 14. / 406. * deepthick;
//            deepdza[14] = 15. / 406. * deepthick;
//            deepdza[15] = 16. / 406. * deepthick;
//            deepdza[16] = 17. / 406. * deepthick;
//            deepdza[17] = 18. / 406. * deepthick;
//            deepdza[18] = 19. / 406. * deepthick;
//            deepdza[19] = 20. / 406. * deepthick;
//            deepdza[20] = 21. / 406. * deepthick;
//            deepdza[21] = 22. / 406. * deepthick;
//            deepdza[22] = 23. / 406. * deepthick;
//            deepdza[23] = 24. / 406. * deepthick;
//            deepdza[24] = 25. / 406. * deepthick;
//            deepdza[25] = 26. / 406. * deepthick;
//            deepdza[26] = 27. / 406. * deepthick;
//            deepdza[27] = 28. / 406. * deepthick;
//            deepdza[28] = -1;
//            deepdza[29] = -1;
//            
//            deepnum = 28;
//            
//        }else if (deepthick > 28 * dlstshlw && deepthick <= 29 * dlstshlw){
//            deepdza[0] = 1. / 435. * deepthick;
//            deepdza[1] = 2. / 435. * deepthick;
//            deepdza[2] = 3. / 435. * deepthick;
//            deepdza[3] = 4. / 435. * deepthick;
//            deepdza[4] = 5. / 435. * deepthick;
//            deepdza[5] = 6. / 435. * deepthick;
//            deepdza[6] = 7. / 435. * deepthick;
//            deepdza[7] = 8. / 435. * deepthick;
//            deepdza[8] = 9. / 435. * deepthick;
//            deepdza[9] = 10. / 435. * deepthick;
//            deepdza[10] = 11. / 435. * deepthick;
//            deepdza[11] = 12. / 435. * deepthick;
//            deepdza[12] = 13. / 435. * deepthick;
//            deepdza[13] = 14. / 435. * deepthick;
//            deepdza[14] = 15. / 435. * deepthick;
//            deepdza[15] = 16. / 435. * deepthick;
//            deepdza[16] = 17. / 435. * deepthick;
//            deepdza[17] = 18. / 435. * deepthick;
//            deepdza[18] = 19. / 435. * deepthick;
//            deepdza[19] = 20. / 435. * deepthick;
//            deepdza[20] = 21. / 435. * deepthick;
//            deepdza[21] = 22. / 435. * deepthick;
//            deepdza[22] = 23. / 435. * deepthick;
//            deepdza[23] = 24. / 435. * deepthick;
//            deepdza[24] = 25. / 435. * deepthick;
//            deepdza[25] = 26. / 435. * deepthick;
//            deepdza[26] = 27. / 435. * deepthick;
//            deepdza[27] = 28. / 435. * deepthick;
//            deepdza[28] = 29. / 435. * deepthick;
//            deepdza[29] = -1;
//            
//            deepnum = 29;
//            
//            
//        }else if (deepthick > 29 * dlstshlw && deepthick <= 30 * dlstshlw){
//            deepdza[0] = 1. / 465. * deepthick;
//            deepdza[1] = 2. / 465. * deepthick;
//            deepdza[2] = 3. / 465. * deepthick;
//            deepdza[3] = 4. / 465. * deepthick;
//            deepdza[4] = 5. / 465. * deepthick;
//            deepdza[5] = 6. / 465. * deepthick;
//            deepdza[6] = 7. / 465. * deepthick;
//            deepdza[7] = 8. / 465. * deepthick;
//            deepdza[8] = 9. / 465. * deepthick;
//            deepdza[9] = 10. / 465. * deepthick;
//            deepdza[10] = 11. / 465. * deepthick;
//            deepdza[11] = 12. / 465. * deepthick;
//            deepdza[12] = 13. / 465. * deepthick;
//            deepdza[13] = 14. / 465. * deepthick;
//            deepdza[14] = 15. / 465. * deepthick;
//            deepdza[15] = 16. / 465. * deepthick;
//            deepdza[16] = 17. / 465. * deepthick;
//            deepdza[17] = 18. / 465. * deepthick;
//            deepdza[18] = 19. / 465. * deepthick;
//            deepdza[19] = 20. / 465. * deepthick;
//            deepdza[20] = 21. / 465. * deepthick;
//            deepdza[21] = 22. / 465. * deepthick;
//            deepdza[22] = 23. / 465. * deepthick;
//            deepdza[23] = 24. / 465. * deepthick;
//            deepdza[24] = 25. / 465. * deepthick;
//            deepdza[25] = 26. / 465. * deepthick;
//            deepdza[26] = 27. / 465. * deepthick;
//            deepdza[27] = 28. / 465. * deepthick;
//            deepdza[28] = 29. / 465. * deepthick;
//            deepdza[29] = 30. / 465. * deepthick;
//            
//            deepnum = 30;
//            
//            
//		
//	} else {
//        deepdza[0] = 1. / 465. * deepthick;
//        deepdza[1] = 2. / 465. * deepthick;
//        deepdza[2] = 3. / 465. * deepthick;
//        deepdza[3] = 4. / 465. * deepthick;
//        deepdza[4] = 5. / 465. * deepthick;
//        deepdza[5] = 6. / 465. * deepthick;
//        deepdza[6] = 7. / 465. * deepthick;
//        deepdza[7] = 8. / 465. * deepthick;
//        deepdza[8] = 9. / 465. * deepthick;
//        deepdza[9] = 10. / 465. * deepthick;
//        deepdza[10] = 11. / 465. * deepthick;
//        deepdza[11] = 12. / 465. * deepthick;
//        deepdza[12] = 13. / 465. * deepthick;
//        deepdza[13] = 14. / 465. * deepthick;
//        deepdza[14] = 15. / 465. * deepthick;
//        deepdza[15] = 16. / 465. * deepthick;
//        deepdza[16] = 17. / 465. * deepthick;
//        deepdza[17] = 18. / 465. * deepthick;
//        deepdza[18] = 19. / 465. * deepthick;
//        deepdza[19] = 20. / 465. * deepthick;
//        deepdza[20] = 21. / 465. * deepthick;
//        deepdza[21] = 22. / 465. * deepthick;
//        deepdza[22] = 23. / 465. * deepthick;
//        deepdza[23] = 24. / 465. * deepthick;
//        deepdza[24] = 25. / 465. * deepthick;
//        deepdza[25] = 26. / 465. * deepthick;
//        deepdza[26] = 27. / 465. * deepthick;
//        deepdza[27] = 28. / 465. * deepthick;
//        deepdza[28] = 29. / 465. * deepthick;
//        deepdza[29] = 30. / 465. * deepthick;
//        
//        deepnum = 30;
//        
//  
//    }
//		/*
//		deepdza[0] = deepthick;
//		deepdza[1] = -1;
//		deepdza[2] = -1;
//		deepdza[3] = -1;
//		deepdza[4] = -1;
//		deepdza[5] = -1;
//		deepdza[6] = -1;
//		deepdza[7] = -1;
//		deepdza[8] = -1;
//		deepdza[9] = -1;
//
//		deepnum = 1;
//		*/
//	}
//	/*
//	 if (dlstshlw > 0) {
//	 if (deepthick < 3 * dlstshlw) {
//	 deepdza[0] = deepthick;
//	 deepdza[1] = -1;
//	 deepdza[2] = -1;
//	 deepnum = 1;
//	 } else if (deepthick >= 3 * dlstshlw && deepthick < 6 * dlstshlw) {
//	 deepdza[0] = 1. / 3. * deepthick;
//	 deepdza[1] = 2. / 3. * deepthick;
//	 deepdza[2] = -1;
//	 deepnum = 2;
//	 } else {
//	 deepdza[0] = 1. / 6. * deepthick;
//	 deepdza[1] = 2. / 6. * deepthick;
//	 deepdza[2] = 3. / 6. * deepthick;
//	 deepnum = 3;
//	 }
//	 } else {
//	 deepdza[0] = deepthick;
//	 deepdza[1] = -1;
//	 deepdza[2] = -1;
//	 deepnum = 1;
//	 }*/
//
//}

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
