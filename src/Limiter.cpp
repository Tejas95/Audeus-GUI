//
//  Limiter.cpp
//  Audeus
//
//  Created by Tejas Manjunath on 10/21/19.
//  Copyright © 2019 Tejas Manjunath. All rights reserved.
//

#include "Limiter.h"
#include <iostream>
#include "Audeus.h"
#include "mainwindow.h"

using namespace std;

extern CAudeus AUD;

CLimiter::CLimiter()
{
    loudness_current = new float[NUM_CHANNELS];
    gainToBe = new float[NUM_CHANNELS];

    memset(loudness_current, 0, sizeof(float) * NUM_CHANNELS);
    memset(gainToBe, 0, sizeof(float) * NUM_CHANNELS);
}


void CLimiter::compute_limiter(float** input, float* loudness_ref, float* threshold, float* gain, float* gainToBe)
{

    cloudness1.compute_loudness(input, loudness_current);

    //Gain Calculation for limiter
    for (int i = 0; i < NUM_CHANNELS; i++)
    {
        qDebug() << loudness_current[0];
        if (loudness_current[i] > threshold[i])
        {
            gainToBe[i] = loudness_ref[i] - loudness_current[i];
            gainToBe[i] = pow(10, gainToBe[i] / 20);
        }
        else
            gainToBe[i] = gain[i];
    }
}
