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
