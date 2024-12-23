#import "screen_management.h"
#import "WindowDelegate.h"
#import <Cocoa/Cocoa.h>

@implementation ScreenManager

+ (NSArray<NSColor *> *)getScreenColors
{
    static NSArray<NSColor *> *screenColors = nil;
    if (!screenColors)
    {
        screenColors = @[
            [NSColor redColor],  // First screen color
            [NSColor blueColor]  // Second screen color
        ];
    }
    return screenColors;
}

+ (void)showIntroTitle
{
    NSLog(@"Showing Intro Title Screen");
}

+ (void)showMainScreen1
{
    NSLog(@"Showing Main Screen 1");
}

+ (void)handleScreenTransition:(NSWindow *)window withWindowDelegate:(WindowDelegate *)windowDelegate
{
    static int currentScreen = 0;
    NSArray<NSColor *> *screenColors = [self getScreenColors];

    int nextScreen = (currentScreen + 1) % screenColors.count;
    NSColor *nextColor = screenColors[nextScreen];

    NSLog(@"Transitioning to Screen %d with color %@", nextScreen, nextColor);

    // Ensure windowDelegate is not nil
    if (windowDelegate) {
        NSLog(@"WindowDelegate is valid, switching color.");
        [windowDelegate switchWindowColor:nextColor forWindow:window];
    } else {
        NSLog(@"Error: WindowDelegate is nil.");
    }

    currentScreen = nextScreen;
}


@end


