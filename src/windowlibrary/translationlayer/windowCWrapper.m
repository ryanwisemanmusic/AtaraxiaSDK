/*This is where we wrap our functions for implementation in C.
Everytime we need to call on a particular task, these functions being
in Obj-C can be used in the C project without compatiblity issues.

This is why we call this part of our translation layer.*/
#import <Cocoa/Cocoa.h>
#import "windowCWrapper.h"

void *ataraxiaApplication() {
    return (void *)[NSApplication sharedApplication];
}

void *createWindow(CGRect frame, int32_t style, const char *title) 
{
    NSRect nsFrame = NSMakeRect(
        frame.origin.x, frame.origin.y, 
        frame.size.width, frame.size.height);
    NSInteger nsStyle = 0;

    if (style & WINDOW_STYLE_TITLED) 
        nsStyle |= NSWindowStyleMaskTitled;
    if (style & WINDOW_STYLE_CLOSABLE) 
        nsStyle |= NSWindowStyleMaskClosable;
    if (style & WINDOW_STYLE_RESIZABLE) 
        nsStyle |= NSWindowStyleMaskResizable;
    if (style & WINDOW_STYLE_MINIATURIZABLE) 
        nsStyle |= NSWindowStyleMaskMiniaturizable;

    NSString *nsTitle = [NSString stringWithUTF8String:title];
    NSWindow *window = [[NSWindow alloc] initWithContentRect:nsFrame
                                                   styleMask:nsStyle
                                                     backing:NSBackingStoreBuffered
                                                       defer:NO];

    [window setTitle:nsTitle];
    return (void *)window;
}

void runApplication(void *app, void *window) {
    @autoreleasepool {
        NSApplication *nsApp = (NSApplication *)app;
        NSWindow *nsWindow = (NSWindow *)window;

        [nsWindow makeKeyAndOrderFront:nil];
        [nsApp run];
    }
}

void setWindowBackgroundColor(void *window, void *color)
{
    NSWindow *nsWindow = (__bridge NSWindow *)window;
    NSColor *nsColor = (__bridge NSColor *)color;
    [nsWindow setBackgroundColor:nsColor];
}


