#import "MouseDelegate.h"
#import "windowCWrapper.h"

@implementation MouseDelegate

- (void)mouseDown:(NSEvent *)event {
    NSWindow *window = [event window];

    static int colorIndex = 0;

    // Get the colors from the array
    NSArray<NSColor *> *colors = getScreenColors();

    if (colors) {
        // Access the current color
        NSColor *currentColor = colors[colorIndex];
        setWindowBackgroundColor((__bridge void *)(window), (__bridge void *)(currentColor));

        NSLog(@"Window color switched to: %@", currentColor);

        // Increment and loop through the color array
        colorIndex = (colorIndex + 1) % colors.count;
    }
}

@end

