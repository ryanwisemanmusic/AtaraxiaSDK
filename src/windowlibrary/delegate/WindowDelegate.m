#import "WindowDelegate.h"
#import "screen_management.h"  // Assuming you have this header for your screen management

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

// Mouse click event handling
- (void)mouseDown:(NSEvent *)event {
    NSLog(@"Mouse clicked in window.");
    NSWindow *window = self.window;
    if (window) {
        [self switchWindowColor:_colorSequence[self.currentColorIndex] forWindow:window];
    } else {
        NSLog(@"Window referenced is nil.");
    }
}

// Mouse release event handling (Optional, you can modify based on your needs)
- (void)mouseUp:(NSEvent *)event {
    NSLog(@"Mouse release detected at: %@", NSStringFromPoint([event locationInWindow]));
    // Transition to the next screen on mouse release if needed
    [self transitionToNextScreen];
}

// Handle Spacebar press for screen transition
- (void)keyDown:(NSEvent *)event {
    if ([event keyCode] == 49) {  // 49 is the keycode for the spacebar
        NSLog(@"Spacebar pressed. Switching to the next screen...");
        [self switchToNextScreen];
    }
}

// Transition to the next screen (Example color switching)
- (void)transitionToNextScreen {
    static int currentScreen = 0;
    NSArray *colors = @[
        [NSColor redColor],
        [NSColor greenColor],
        [NSColor blueColor],
        [NSColor yellowColor]
    ];
    
    currentScreen = (currentScreen + 1) % colors.count;
    NSColor *nextColor = colors[currentScreen];
    [self switchWindowColor:nextColor forWindow:self.window];
}

// Switch window color
- (void)switchWindowColor:(NSColor *)nextColor forWindow:(NSWindow *)window {
    NSLog(@"switchWindowColor called with color: %@", nextColor);
    
    [window.contentView setWantsLayer:YES];
    window.contentView.layer.backgroundColor = nextColor.CGColor;

    // Log the color change
    NSLog(@"Window color switched to: %@", nextColor);
}

// Switch to the next screen logic (For cleanup or other actions)
- (void)switchToNextScreen {
    NSLog(@"Switching to the next screen...");
    // Add your screen transition logic here, if needed
}

// Handle window close event
- (void)windowWillClose:(NSNotification *)notification {
    NSLog(@"Window has closed. Perform necessary actions.");
    [self switchToNextScreen];  // Transition to the next screen or handle cleanup
    [NSApp terminate:nil];  // Terminate the application if necessary
}

@end






