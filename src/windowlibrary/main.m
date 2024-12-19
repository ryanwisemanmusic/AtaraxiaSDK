/*
This is the obj-c part that handles windowing. We use it as the main
to our application, since everything else can be defined in its own
function. 
*/

#import <Cocoa/Cocoa.h>
#import "windowCWrapper.h"
#import "colorFill.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // This initializes the application using the function from windowCWrapper.h
        void *app = ataraxiaApplication();
        
        // Create a window with the specified frame and style
        CGRect frame = CGRectMake(0, 0, 800, 600);
        int32_t style = WINDOW_STYLE_TITLED | WINDOW_STYLE_CLOSABLE;
        const char *title = "Ataraxia App";
        void *window = createWindow(frame, style, title);
        
        // Retrieve the color reference for custom red
        void *redColor = ATARAXIA_CUSTOM_RED_01();
        
        // Set the window background color to custom red
        setWindowBackgroundColor(window, redColor);
        
        // Run the application (handles events and UI)
        runApplication(app, window);
    }
    return 0;
}
