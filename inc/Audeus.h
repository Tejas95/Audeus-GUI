#pragma once

#define NOMINMAX

#include <stdio.h>
#include <math.h>
#include <portaudio.h>
#include <algorithm>
#include "Loudness.h"
#include "Gain.h"
#include "Limiter.h"
#include "Definitions.h"
#include <iostream>
#include <string>
#include <dsound.h>
#include <dsconf.h>
#include "pawrapper.h"
#include "Gate.h"

using namespace std;

class CAudeus
{

public:
    CAudeus();
    void calculateAverage(float **input, float *output, int numberOfNoiseValues);

    static int AudioCallback(const void *inputBuffer, void *outputBuffer,
        unsigned long framesPerBuffer,
        const PaStreamCallbackTimeInfo* timeInfo,
        PaStreamCallbackFlags statusFlags,
        void *userData);

    static int AudioCallbackNoiseDetection(const void *inputBuffer, void *outputBuffer,
        unsigned long framesPerBuffer,
        const PaStreamCallbackTimeInfo* timeInfo,
        PaStreamCallbackFlags statusFlags,
        void *userData);

    static int AudioCallbackInput(const void *inputBuffer, void *outputBuffer,
        unsigned long framesPerBuffer,
        const PaStreamCallbackTimeInfo* timeInfo,
        PaStreamCallbackFlags statusFlags,
        void *userData);

    static int AudioCallbackFreeze(const void *inputBuffer, void *outputBuffer,
        unsigned long framesPerBuffer,
        const PaStreamCallbackTimeInfo* timeInfo,
        PaStreamCallbackFlags statusFlags,
        void *userData);


    CGain Cgain;
    CLoudness Cloud;
    CLimiter Climiter;
    CGate Cgate;

    int LoudnessMode;
    float *LoudnessValues;

    int numBlocks;

    float **output;
    float **input;
    //float **inputBufferForGain;
    float *gain1;
    float *gain;
    float* gainToBe;
    float* adaptiveEndGain;
    float* increment;
    float *loud_I;
    float *loud_O;
    float* loud_output;

    int BlocksizeTemp;
    int noiseLoudnessLevelTemp;
    int inputLoudnessLevelTemp;
    int gainLevelTemp;

    float **noiseLoudnessLevelsBuffer;
    float *noiseLoudnessLevelBufferAvg;
    float *noiseLoudnessLevelBufferMax;
    float* noiseArray;
    float **inputLoudnessLevelsBuffer;
    float *inputLoudnessLevelBufferAvg;

    int numberOfNoiseLoudnessValues;
    int numberOfInputLoudnessValues;
    int numberOfGainValues;

    float* loudnessReferenceValues;
    float* current_loudness;
    float* limiterThreshold;
    float* gateThreshold;
    float *loudnessValues;

    float SLOW_TIME_CONSTANT;

    string noiseLoudnessLevelStart;
    string noiseLoudnessLevelIsDone;
    string inputLoudnessLevelStart;
    string inputLoudnessLevelIsDone;
    string gainLevelStart;
    string gainLevelIsDone;
    string adaptiveGainLevelStart;
    string adaptiveGainLevelIsDone;

    int channelTemp;
    int startChannel;
    int endChannel;
};
