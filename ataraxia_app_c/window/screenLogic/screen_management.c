#include "screen_management.h"

void showIntroTitle(void)
{

}

void showMainScreen1(void)
{

}

void handleScreenTransition(void *window)
{
    static int currentScreen = 1;
    if (currentScreen == 1)
    {
        showMainScreen1();
        currentScreen = 2;
    }
    else
    {
        showIntroTitle();
        currentScreen = 1;
    }
    
}