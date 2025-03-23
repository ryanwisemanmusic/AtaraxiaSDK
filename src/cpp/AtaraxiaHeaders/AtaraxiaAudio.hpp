#ifndef ATARAXIAAUDIO
#define ATARAXIAAUDIO

#include <SDL3/SDL_audio.h>

//Global variables
inline SDL_AudioDeviceID audioDevice = 0;
inline SDL_AudioStream* audioStream = nullptr;
inline Uint8* audioBuffer = nullptr;
inline Uint32 audioLength = 0;

#endif