/*This is where we wrap our functions for implementation in C.
Everytime we need to call on a particular task, these functions being
in Obj-C can be used in the C project without compatiblity issues.

This is why we call this part of our translation layer.*/
#import "windowCWrapper.h"
#import <Cocoa/Cocoa.h>

// Converts NSApplication to void* (non-owning)
void *ataraxiaApplication()
{
    return (__bridge void *)[NSApplication sharedApplication];
}

// Converts NSWindow to void* (non-owning)
void *createWindow(CGRect frame, int32_t style, const char *title)
{
    NSWindow *window = [[NSWindow alloc] initWithContentRect:NSRectFromCGRect(frame)
                                                   styleMask:style
                                                     backing:NSBackingStoreBuffered
                                                       defer:NO];
    [window setTitle:[NSString stringWithUTF8String:title]];
    return (__bridge void *)window;
}

// Converts void* to NSApplication (owning)
void runApplication(void *app, void *window)
{
    @autoreleasepool
    {
        NSApplication *nsApp = (__bridge NSApplication *)app; 
        NSWindow *nsWindow = (__bridge NSWindow *)window; 

        if (nsApp && nsWindow)
        {
            [nsWindow makeKeyAndOrderFront:nil];
            [nsApp run];
        }
        else
        {
            NSLog(@"Application or Window is NULL");
        }
    }
}

void setWindowBackgroundColor(void *window, void *color)
{
    NSWindow *nsWindow = (__bridge NSWindow *)window;
    NSColor *nsColor = (__bridge NSColor *)color;

    if (nsWindow && nsColor)
    {
        [nsWindow setBackgroundColor:nsColor];
    }
    else
    {
        NSLog(@"Window or Color is NULL");
    }
}




