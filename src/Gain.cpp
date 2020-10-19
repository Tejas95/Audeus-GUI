//
//  Gain.cpp
//  Audeus
//
//  Created by Tejas Manjunath on 10/28/19.
//  Copyright © 2019 Tejas Manjunath. All rights reserved.
//

#include "Gain.h"
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <iostream>
#include "Audeus.h"

using namespace std;

CGain::CGain()
{
	loudnessDifference = new float[NUM_CHANNELS];
}


void CGain::cal_gain(float *loud_in, float *loud_ref, float *gain)
{
    CAudeus AUD;
    for (int i = AUD.startChannel; i < AUD.endChannel; i++)
	{
		gain[i] = loud_ref[i] - loud_in[i];
		gain[i] = pow(10, gain[i] / 20);
		cout << "Gain Level for channel " << i << " is: " << gain[i] << endl;
	}
}
