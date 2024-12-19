#ifndef SCREEN_MANAGEMENT_H
#define SCREEN_MANAGEMENT_H

#include <stdio.h>
#include "windowCWrapper.h"

#ifdef __cplusplus
extern "c" {
#endif

void **getScreenColors(void);

#ifdef __cplusplus
}
#endif

void showIntroTitle(void);
void showMainScreen1(void);

void handleScreenTransition(void *window);

void **getScreenColors(void);

#endif 
