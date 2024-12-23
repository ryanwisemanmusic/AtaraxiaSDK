#import "EventHandling.h"

@implementation EventHandling

- (void)startListeningForEvents {
    // Global event monitoring
    NSLog(@"Function called, starListeningForEvents is initialized");
    [NSEvent addGlobalMonitorForEventsMatchingMask:(NSEventMaskLeftMouseDown | NSEventMaskKeyDown) handler:^(NSEvent *event) {
        if (event.type == NSEventTypeLeftMouseDown) {
            // Handle mouse click event
            NSLog(@"Mouse click detected at: %@", NSStringFromPoint(event.locationInWindow));
        } else if (event.type == NSEventTypeKeyDown) {
            if ([event keyCode] == 49) { // Spacebar keycode
                // Handle spacebar press event
                NSLog(@"Spacebar pressed.");
            }
        }
    }];
}

@end
