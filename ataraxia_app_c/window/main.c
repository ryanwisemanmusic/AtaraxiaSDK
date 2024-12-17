/*This is the foundation for the main window that is needed.

We will only use this section to handle main window sizing. This is
NOT a place to put additonal functions unless it relates to a performable
action on this window.

Resizing functions, anything that relates to the status of the main
window and not internals of said window, these functions are fine.

If you mess with this, the problem is on you
*/

#ifdef __OBJC__
#import "windowCWrapper.h"
#import "colorFill.h"
#else
#include "windowCWrapper.h"
#include "colorFill.h"
#endif

int main(int argc, const char *argv[])
{
    void *app = ataraxiaApplication();

    CGRect frame = CGRectMake(0, 0, 800, 600);
    int32_t style = WINDOW_STYLE_TITLED | WINDOW_STYLE_CLOSABLE;
    
    const char *title = "Ataraxia App";
    void *window = createWindow(frame, style, title);

    /*One of my biggest errors with this code is forgetting
    the paranthesis for this color reference*/
    void *redColor = ATARAXIA_CUSTOM_RED_01();

    /*Anytime you want to set a color within a window
    we will use the setWindowBackgroundColor function
    to do so.*/
    setWindowBackgroundColor(window, redColor);

    runApplication(app, window);
    
    return 0;

}