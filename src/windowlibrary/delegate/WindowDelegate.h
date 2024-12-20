#import <Cocoa/Cocoa.h>

@interface WindowDelegate : NSObject <NSWindowDelegate>
@property (weak, nonatomic) NSWindow *window;
- (void)mouseDown:(NSEvent *)event;

@end