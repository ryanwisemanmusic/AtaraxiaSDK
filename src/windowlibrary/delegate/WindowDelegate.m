#import "WindowDelegate.h"
#import "screen_management.h"

@implementation WindowDelegate

- (instancetype)initWithWindow:(NSWindow *)window {
    self = [super init];
    if (self) {
        _window = window;
    }
    return self;
}

- (void)mouseDown:(NSEvent *)event {
    NSLog(@"Mouse clicked in window.");
    [ScreenManager handleScreenTransition:self.window];
}

- (BOOL)windowShouldClose:(NSWindow *)sender {
    NSLog(@"Window is about to close. Terminating AtaraxiaSDK.");
    [NSApp terminate:nil];
    return YES;
}

@end

