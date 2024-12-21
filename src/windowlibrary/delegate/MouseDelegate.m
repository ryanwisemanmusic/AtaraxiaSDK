#import "MouseDelegate.h"

@implementation MouseDelegate

- (void)mouseDown:(NSEvent *)event {
    NSLog(
        @"Mouse clicked at location: %@", 
        NSStringFromPoint(event.locationInWindow));
}

- (void)mouseUp:(NSEvent *)event {
    NSLog(
        @"Mouse released at location: %@", 
        NSStringFromPoint(event.locationInWindow));
}

- (void)mouseMoved:(NSEvent *)event {
    NSLog(
        @"Mouse moved to location: %@", 
        NSStringFromPoint(event.locationInWindow));
}

@end