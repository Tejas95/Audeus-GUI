//
//  Limiter.cpp
//  Audeus
//
//  Created by Tejas Manjunath on 10/21/19.
//  Copyright © 2019 Tejas Manjunath. All rights reserved.
//

#include "Limiter.h"
#include <iostream>
#include "Loudness.h"
#include "Audeus.h"

using namespace std;

CLimiter::CLimiter()
{
    gainToBe = new float[NUM_CHANNELS];
}


void CLimiter::compute_limiter(float* loudness_ref, float* current_loudness, float* threshold, float* gain, float* gainToBe)
{
    //Gain Calculation for limiter
    for (int i = 0; i < NUM_CHANNELS; i++)
    {
        if (current_loudness[i] > threshold[i])
        {
            gainToBe[i] = loudness_ref[i] - current_loudness[i];
            gainToBe[i] = pow(10, gainToBe[i] / 20);
        }
        else
            gainToBe[i] = gain[i];
    }


}
