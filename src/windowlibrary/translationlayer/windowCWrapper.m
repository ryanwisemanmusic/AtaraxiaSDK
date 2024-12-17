/*This is where we wrap our functions for implementation in C.
Everytime we need to call on a particular task, these functions being
in Obj-C can be used in the C project without compatiblity issues.

This is why we call this part of our translation layer.*/
#import "windowCWrapper.h"
#import <Cocoa/Cocoa.h>
#include "screen_management.h"

/* For windowing events, we must create parameters that accept windowing
actions. So far, we can launch a window, we must have it interface with
the rest of the code. */
@interface WindowDelegate : NSObject <NSWindowDelegate>
@end

@implementation WindowDelegate
/*This is our logic to closing the window. We set it as a bool
since each flag can be handled with either a yes or no.*/
- (BOOL)windowShouldClose:(NSWindow *)sender
{
    NSLog(@"Window is closing.");
    [[NSApplication sharedApplication] terminate:nil];
    return YES;
}

/*We use mouseDown as a way of handling clicking within said window.*/
-(void)mouseDown:(NSEvent *)event
{
    NSLog(@"Mouse clicked in window. Triggering screen transition.");
    handleScreenTransition((__bridge void *)self);
}

@end

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
    
    if (style & WINDOW_STYLE_CLOSABLE)
    {
        [window setAcceptsMouseMovedEvents:YES];
    }
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
            //We use this to delegate window events
            WindowDelegate *delegate = [[WindowDelegate alloc] init];
            [nsWindow setDelegate:delegate];

            //Then, we use this to close the events
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




