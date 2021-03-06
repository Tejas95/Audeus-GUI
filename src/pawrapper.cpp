/*
 * This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3 of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along with this program;
 * if not, see <http://www.gnu.org/licenses/>.
*/
#include "pawrapper.h"
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include "Definitions.h"
#include "Audeus.h"

using namespace std;

PaStream *stream;
PaError err;

//int paWrapper::processingCallback(const void *inputBuffer,
//                                  void *outputBuffer,
//                                  unsigned long framesPerBuffer,
//                                  const PaStreamCallbackTimeInfo* timeInfo,
//                                  PaStreamCallbackFlags statusFlags)
//{
//  (void) inputBuffer; // Prevent unused variable warning.
//  (void) outputBuffer; // Prevent unused variable warning.
//  (void) framesPerBuffer; // Prevent unused variable warning.
//  (void) timeInfo; // Prevent unused variable warning.
//  (void) statusFlags; // Prevent unused variable warning.
//  return 0;
//}

paWrapper::paWrapper()
{
  printf("paWrapper::paWrapper()\n"); flush(cout);
  isRunning=false; //currently nothing is running
  initAudio();
}

void paWrapper::initAudio()
{
  printf("paWrapper::initAudio()\n"); flush(cout);
  int selectedDevice=Pa_GetDefaultOutputDevice();

  int err = Pa_Initialize();
  if( err != paNoError ) printf(  "PortAudio error: %s\n", Pa_GetErrorText( err ) );

  int noOfHostApis = Pa_GetHostApiCount();
  printf("%d host apis available\n",noOfHostApis);

  int noOfAudioDevices = Pa_GetDeviceCount();
  printf("%d audio devices available\n",noOfAudioDevices);

  selectedHostApi = Pa_GetDefaultHostApi();

  const PaDeviceInfo* di;

  for(int i=0; i < noOfAudioDevices; i++)
  {
    di = Pa_GetDeviceInfo(i);
    printf("Device %d: %s\n",i,di->name);
    if(i==selectedDevice)
    {
      suggestedLatency = di->defaultLowInputLatency;
    }
  }

  outputStreamParam.channelCount = NUM_CHANNELS;
  outputStreamParam.device = Pa_GetDefaultOutputDevice();
  outputStreamParam.sampleFormat = paFloat32;
  outputStreamParam.suggestedLatency = suggestedLatency;
  outputStreamParam.hostApiSpecificStreamInfo = NULL;

  inputStreamParam.channelCount = NUM_CHANNELS;
  inputStreamParam.device = Pa_GetDefaultInputDevice();
  inputStreamParam.sampleFormat = paFloat32;
  inputStreamParam.suggestedLatency = suggestedLatency;
  inputStreamParam.hostApiSpecificStreamInfo = NULL;

  printf("default output device is %d\n",Pa_GetDefaultOutputDevice());
  printf("default input device is %d\n",Pa_GetDefaultInputDevice());

  flush(cout);
}

paWrapper::~paWrapper()
{
  printf("paWrapper::~paWrapper()\n"); flush(cout);
  int err = Pa_Terminate();
  if( err != paNoError )
     printf("PortAudio error (Pa_Terminate): %s\n", Pa_GetErrorText( err ) );
}

int paWrapper::startAudioFreeze(void)
{
  CAudeus AUD;

  if(isRunning) return pawErrorAudioIsRunning;
  isRunning=true;
  err = Pa_OpenStream(&stream,
                      &inputStreamParam,
                      &outputStreamParam,
                      SAMPLE_RATE,
                      FRAMES_PER_BUFFER,
                      paNoFlag,
                      AUD.AudioCallbackFreeze,
                      (void*)&AUD);

  if(err != paNoError)
  {
    isRunning=false;
    return err;
  }
  int err = Pa_StartStream( stream );
  if(err != paNoError)
    isRunning=false;
  return err;
}

int paWrapper::startAudioNoise(void)
{
  CAudeus AUD;

  if(isRunning) return pawErrorAudioIsRunning;
  isRunning=true;
  err = Pa_OpenStream(&stream,
                      &inputStreamParam,
                      &outputStreamParam,
                      SAMPLE_RATE,
                      FRAMES_PER_BUFFER,
                      paNoFlag,
                      AUD.AudioCallbackNoiseDetection,
                      (void*)&AUD);

  if(err != paNoError)
  {
    isRunning=false;
    return err;
  }
  int err = Pa_StartStream( stream );
  if(err != paNoError)
    isRunning=false;
  return err;
}

int paWrapper::startAudioInput(void)
{
  CAudeus AUD;

  if(isRunning) return pawErrorAudioIsRunning;
  isRunning=true;
  err = Pa_OpenStream(&stream,
                      &inputStreamParam,
                      &outputStreamParam,
                      SAMPLE_RATE,
                      FRAMES_PER_BUFFER,
                      paNoFlag,
                      AUD.AudioCallbackInput,
                      (void*)&AUD);

  if(err != paNoError)
  {
    isRunning=false;
    return err;
  }
  int err = Pa_StartStream( stream );
  if(err != paNoError)
    isRunning=false;
  return err;
}



int paWrapper::stopAudio(void)
{
  int err=-1;
  if(isRunning)
  {
    err = Pa_AbortStream( stream );
    isRunning=false;

    if( err != paNoError ) return err;

    err = Pa_CloseStream( stream );
  }
  return err;
}



/**
  The wrapper for user messages. Replace text messages here for user convenience.
*/
const char* paWrapper::getErrorText(int errorId)
{
  switch(errorId)
  {
    case paInvalidChannelCount:
      return "No output channels available or device busy";
      break;
    case pawErrorAudioIsRunning:
      return "The audio processing is already running";
      break;
    default:
      return Pa_GetErrorText(errorId);
  }
}

