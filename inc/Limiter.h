#ifndef LIMITER_H
#define LIMITER_H

//
//  Limiter.hpp
//  Audeus
//
//  Created by Tejas Manjunath on 10/21/19.
//  Copyright © 2019 Tejas Manjunath. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "Definitions.h"

using namespace std;

class CLimiter
{
public:

    CLimiter();

    void compute_limiter(float* loudness_ref, float* current_loudness, float* threshold, float* gain, float* gainToBe);

    float* gainToBe;


};

#endif // LIMITER_H
