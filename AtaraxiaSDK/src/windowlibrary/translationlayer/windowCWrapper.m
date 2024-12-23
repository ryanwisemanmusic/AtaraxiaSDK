/*This is where we wrap our functions for implementation in C.
Everytime we need to call on a particular task, these functions being
in Obj-C can be used in the C project without compatiblity issues.

This is why we call this part of our translation layer.*/
#import "windowCWrapper.h"
#import <Cocoa/Cocoa.h>
#include "screen_management.h"

// Color functions
NSColor *getColorForIntro()
{
    return [NSColor colorWithSRGBRed:0.0 green:0.0 blue:1.0 alpha:1.0];
}

NSColor *getColorForMain()
{
    return [NSColor colorWithSRGBRed:0.0 green:1.0 blue:0.0 alpha:1.0];
}

// Application and window functions
void *ataraxiaApplication()
{
    return (__bridge void *)[NSApplication sharedApplication];
}

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

@interface AtaraxiaAppWrapper : NSObject
@property (strong, nonatomic) WindowDelegate *delegate;
@end

@implementation AtaraxiaAppWrapper

- (instancetype)init {
    self = [super init];
    if (self) {
        self.delegate = [[WindowDelegate alloc] init];
        NSLog(@"WindowDelegate initialized.");
    }
    return self;
}

@end

void runApplication(void *app, void *window)
{
    @autoreleasepool
    {
        NSApplication *nsApp = (__bridge NSApplication *)app; 
        NSWindow *nsWindow = (__bridge NSWindow *)window; 

        if (nsApp && nsWindow)
        {
            AtaraxiaAppWrapper *appWrapper = [[AtaraxiaAppWrapper alloc] init];
            appWrapper.delegate = [[WindowDelegate alloc] init];
            [nsWindow setDelegate:appWrapper.delegate];

            // Double-checking if delegate was set
            NSLog(@"WindowDelegate set on window: %@", nsWindow);

            // Start the window and run the app
            [nsWindow makeKeyAndOrderFront:nil];
            [nsApp run];
        }
        else
        {
            NSLog(@"Application or Window is NULL");
        }
    }
}

void setWindowBackgroundColor(void *window, void *color) {
    // Bridge the passed window and color from void* to appropriate types
    NSWindow *nsWindow = (__bridge NSWindow *)window;
    NSColor *nsColor = (__bridge NSColor *)color;

    // Log the color being set
    NSLog(@"Setting background color to: %@", nsColor);

    // Set the window's background color
    [nsWindow setBackgroundColor:nsColor];
    
    // Force a redraw of the window content with a slight delay to ensure the UI updates
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        [nsWindow display]; // Ensures the content is displayed after the color change
        NSLog(@"Window color set after delay: %@", nsColor);
    });

    // Get the content view of the window and force it to redraw immediately
    NSView *contentView = [nsWindow contentView];
    [contentView setNeedsDisplay:YES];  // Redraw the content view (this is correct)
    NSLog(@"Window color set and content view redrawing initiated.");
}






// Updated getScreenColors function using NSArray
NSArray<NSColor *> *getScreenColors(void) {
    return @[
        [NSColor redColor],
        [NSColor greenColor],
        [NSColor blueColor],
        [NSColor yellowColor]
    ];
}
