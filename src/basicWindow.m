#import "basicWindow.h"

/*Our function for calling the Ataraxia made
application*/
NSApplication *ataraxiaApplication()
{
    return [NSApplication sharedApplication];
}

NSWindow *createWindow(
    NSRect frame, NSInteger style,
    NSString *title)
{
    /*Creating the window first starts with us allocation, then
    we can make sure it follows some of the cocoa definitions
    by expressing their inheritence*/
    NSWindow *window = [[NSWindow alloc] initWithContentRect:frame
    styleMask:style  backing:NSBackingStoreBuffered  defer:NO];

    [window setTitle:title];
    return window;
}

void runApplication(NSApplication *app, NSWindow *window)
{
    [window makeKeyAndOrderFront:nil];
    [app run];
}