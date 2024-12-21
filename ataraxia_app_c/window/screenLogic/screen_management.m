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
            [NSColor redColor],
            [NSColor blueColor]
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

    NSLog(@"Transitioning to Screen %d with color %@", nextScreen, screenColors[nextScreen]);

    [windowDelegate switchWindowColor];

    currentScreen = nextScreen;
}

@end

