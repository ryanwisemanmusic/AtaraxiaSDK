

#ifndef ATARAXIATIMER
#define ATARAXIATIMER
#include <SDL3/SDL_timer.h>

bool SDL_GetCurrentTime(SDL_Time * ticks);
SDL_TimerID SDL_AddTimer(Uint32 interval, SDL_TimerCallback callback, void *userdata);

#endif