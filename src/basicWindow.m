#import "basicWindow.h"
#import "colorFill.h"

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

    [window.contentView setWantsLayer:YES];

    /*We use this as means of setting a color for the application*/
    window.contentView.layer.backgroundColor = 
    [[ATARAXIA_CUSTOM_RED_01() colorUsingColorSpace:
    [NSColorSpace deviceRGBColorSpace]] CGColor];

    return window;
}

void runApplication(NSApplication *app, NSWindow *window)
{
    [window makeKeyAndOrderFront:nil];
    [app run];
}