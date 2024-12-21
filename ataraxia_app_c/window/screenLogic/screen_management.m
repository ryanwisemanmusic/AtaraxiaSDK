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

    // Assuming `switchWindowColor` method is part of the WindowDelegate class.
    // Make sure this method is properly switching the color after all initialization.
    [windowDelegate switchWindowColor:nextColor forWindow:window];

    currentScreen = nextScreen;
}

@end


