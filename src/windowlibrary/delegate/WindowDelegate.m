#import "WindowDelegate.h"
#import "screen_management.h"

@interface WindowDelegate ()

//Color switching properties are added here
@property (nonatomic, strong) NSArray<NSColor *> *colorSequence;
@property (nonatomic, assign) NSUInteger currentColorIndex;

@end

@implementation WindowDelegate

- (instancetype)initWithWindow:(NSWindow *)window {
    self = [super init];
    if (self) {
        _window = window; 
        NSLog(@"WindowDelegate initialized with window: %@", window);

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
        [self switchWindowColor];
    } else {
        NSLog(@"Window referenced is nil.");
    }
}


- (void)switchWindowColor {
    // This will cycle through each color and verify that we've done so
    NSLog(@"switchWindowColor called.");
    self.currentColorIndex = (self.currentColorIndex + 1) % self.colorSequence.count;
    NSColor *nextColor = self.colorSequence[self.currentColorIndex];
    
    [self.window.contentView setWantsLayer:YES];
    self.window.contentView.layer.backgroundColor = nextColor.CGColor;

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



