#include "screen_management.h" 
#include "windowCWrapper.h"      

void showIntroTitle(void)
{
    printf("Showing Intro Title Screen\n");
}

void showMainScreen1(void)
{
    printf("Showing Main Screen 1\n");
}


void handleScreenTransition(void *window)
{
    static int currentScreen = 0;

    typedef void (*ScreenHandler)(void);
    ScreenHandler screenHandlers[] = { 
        showIntroTitle, showMainScreen1
    };

    void **screenColors = getScreenColors();

    printf("Transitioning to Screen %d with color %p\n", 
            currentScreen + 1, screenColors[currentScreen]);
    
    int nextScreen = (currentScreen + 1) % 2;

    printf("Transitioning to Screen %d\n", nextScreen + 1);
    screenHandlers[nextScreen]();
    setWindowBackgroundColor(window, screenColors[nextScreen]);

    currentScreen = nextScreen;
}