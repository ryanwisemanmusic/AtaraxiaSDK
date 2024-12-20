#import "WindowDelegate.h"
#import "screen_management.h"

@implementation WindowDelegate

- (instancetype)initWithWindow:(NSWindow *)window {
    self = [super init];
    if (self) {
        self.window = window; 
        NSLog(@"WindowDelegate initialized with window: %@", window);
    }
    return self;
}

- (void)mouseDown:(NSEvent *)event {
    NSLog(@"Mouse clicked in window.");
    NSWindow *window = self.window;
    [ScreenManager handleScreenTransition:window];
}

- (void)windowWillClose:(NSNotification *)notification {
    NSLog(@"Window is about to close");
}

- (BOOL)windowShouldClose:(NSWindow *)sender {
    NSLog(@"Window is about to close. Terminating AtaraxiaSDK.");
    [NSApp terminate:nil];
    return YES;
}

@end


