#include <stdio.h>
#include "screen_management.h" 
#include "windowCWrapper.h"      

void showIntroTitle(void)
{
    printf("Showing Intro Title Screen");
}

void showMainScreen1(void)
{
    printf("Showing Intro Title Screen");
}

void handleScreenTransition(void *window)
{
    static int currentScreen = 1;

    void *introColor = getColorForIntro();
    void *mainScreen1Color = getColorForMain();

    if (currentScreen == 1)
    {
        showMainScreen1();
        setWindowBackgroundColor(window, mainScreen1Color);
        currentScreen = 2;
    }
    else
    {
        showIntroTitle();
        setWindowBackgroundColor(window, introColor);
        currentScreen = 1;
    }
    
}