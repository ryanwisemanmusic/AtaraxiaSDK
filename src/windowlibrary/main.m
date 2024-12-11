/*
This is the obj-c part that handles windowing. We use it as the main
to our application, since everything else can be defined in its own
function. 
*/
#import "windowCWrapper.h"
#import <Cocoa/Cocoa.h>

int main (int argc, const char *argv[])
{
    @autoreleasepool 
    {
        NSApplication *app = ataraxiaApplication();

        NSRect frame = NSMakeRect(300, 300, 600, 300);
        NSInteger style = NSWindowStyleMaskTitled |
        NSWindowStyleMaskClosable | NSWindowStyleMaskResizable;

        const char *title = "AtaraxiaSDK";

        NSWindow *window = createWindow(frame, style, title);
        runApplication(app, window);
    }
    return 0;
}