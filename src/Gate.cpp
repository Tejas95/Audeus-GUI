//
//  Gate.cpp
//  Audeus
//
//  Created by Tejas Manjunath on 10/21/19.
//  Copyright © 2019 Tejas Manjunath. All rights reserved.
//

#include "Limiter.h"
#include <iostream>
#include "Gate.h"
#include "Audeus.h"

using namespace std;

CGate::CGate()
{
    loudness_current = new float[NUM_CHANNELS];
}


void CGate::compute_gate(const float** in, float** out, float* input_loudness, float* threshold, float* gain)
{
    //Gain Calculation for limiter
    for (int i = 0; i < NUM_CHANNELS; i++)
    {
        for (int j = 0; j < FRAMES_PER_BUFFER; j++)
        {
            if (input_loudness[i] < threshold[i])
                out[i][j] = 0;
            else
                out[i][j] = in[i][j] * gain[i];
        }
    }
}
