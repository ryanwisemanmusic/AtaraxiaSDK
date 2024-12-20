#import "WindowDelegate.h"
#import "screen_management.h"

@implementation WindowDelegate

- (void)mouseDown:(NSEvent *)event {
    NSLog(@"Mouse clicked in window.");

    NSWindow *window = (NSWindow *)self.window;
    [ScreenManager handleScreenTransition:window];
}

@end
