#import "windowCWrapper.h"
#import "basicWindow.h"
#import "colorFill.h"

NSApplication *ataraxiaApplication() {
    return [NSApplication sharedApplication];
}

NSWindow *createWindow(
    NSRect frame, NSInteger style, 
    NSString *title) 
{
    NSWindow *window = [[NSWindow alloc] initWithContentRect:frame
    styleMask:style  backing:NSBackingStoreBuffered  defer:NO];

    [window setTitle:title];
    [window.contentView setWantsLayer:YES];
    window.contentView.layer.backgroundColor = 
    [[ATARAXIA_CUSTOM_RED_01() colorUsingColorSpace:[
        NSColorSpace deviceRGBColorSpace]] CGColor];
    return window;
}

void runApplication(
    NSApplication *app, NSWindow *window) 
{
    [window makeKeyAndOrderFront:nil];
    [app run];
}


