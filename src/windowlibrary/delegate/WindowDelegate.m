#import "WindowDelegate.h"
#import "screen_management.h"

@interface WindowDelegate ()

// Color switching properties
@property (nonatomic, strong) NSArray<NSColor *> *colorSequence;
@property (nonatomic, assign) NSUInteger currentColorIndex;

@end

@implementation WindowDelegate

- (instancetype)initWithWindow:(NSWindow *)window {
    self = [super init];
    if (self) {
        _window = window; 
        NSLog(@"WindowDelegate initialized with window: %@", window);

        // Initialize the color sequence
        _colorSequence = @[
            [NSColor redColor],
            [NSColor greenColor],
            [NSColor blueColor],
            [NSColor yellowColor]
        ];
        _currentColorIndex = 0;

        // Log color sequence for verification
        NSLog(@"Color sequence initialized: %@", _colorSequence);

        // Set initial color
        [self.window setBackgroundColor:_colorSequence[_currentColorIndex]];
    }
    return self;
}

- (void)mouseDown:(NSEvent *)event {
    NSLog(@"Mouse clicked in window.");
    NSWindow *window = self.window;
    if (window) {
        [self switchWindowColor:_colorSequence[self.currentColorIndex] forWindow:window];  // Pass the color to the method
    } else {
        NSLog(@"Window referenced is nil.");
    }
}

- (void)switchWindowColor:(NSColor *)nextColor forWindow:(NSWindow *)window {
    // Cycle through each color and apply it to the window
    NSLog(@"switchWindowColor called with color: %@", nextColor);
    
    [window.contentView setWantsLayer:YES];
    window.contentView.layer.backgroundColor = nextColor.CGColor;

    // Log the color change
    NSLog(@"Window color switched to: %@", nextColor);
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





