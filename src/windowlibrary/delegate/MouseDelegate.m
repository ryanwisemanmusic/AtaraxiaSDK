#import "MouseDelegate.h"
#import "windowCWrapper.h"

@implementation MouseDelegate

- (void)mouseDown:(NSEvent *)event {
    NSWindow *window = [event window];
    
    static int colorIndex = 0;

    // Get the colors from the array
    NSArray<NSColor *> *colors = getScreenColors();

    if (colors) {
        // Log the current color being applied
        NSColor *currentColor = colors[colorIndex];
        NSLog(@"Attempting to set window background color: %@", currentColor);
        
        // Set the window background color
        setWindowBackgroundColor((__bridge void *)(window), (__bridge void *)(currentColor));

        // Ensure the content view is redrawn
        NSView *contentView = [window contentView];
        [contentView setNeedsDisplay:YES];
        NSLog(@"Window content view redrawing initiated.");
        
        // Increment and loop through the color array
        colorIndex = (colorIndex + 1) % colors.count;
    } else {
        NSLog(@"No colors found in getScreenColors!");
    }
}





@end


