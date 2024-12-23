#import "SpacebarDelegate.h"

@implementation SpacebarDelegate

- (void) handleSpacebarPressInWindowDelegate:(WindowDelegate *)windowDelegate {
    NSLog(@"Spacebar pressed in SpacebarDelegate. Initiating screen transition...");
    [windowDelegate switchToNextScreen];
}

@end