#import "WindowDelegate.h"
#import "screen_management.h"

@implementation WindowDelegate

- (instancetype)initWithWindow:(NSWindow *)window {
    self = [super init];
    if (self) {
        _window = window; 
        NSLog(@"WindowDelegate initialized with window: %@", window);
    }
    return self;
}

- (void)mouseDown:(NSEvent *)event {
    NSLog(@"Mouse clicked in window.");
    NSWindow *window = self.window;
    if (window) 
    {
        [ScreenManager handleScreenTransition:window];
    }
    else 
    {
        NSLog(@"Window referenced is nil.");
    }
    
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


