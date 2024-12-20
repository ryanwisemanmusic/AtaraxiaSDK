#import <Cocoa/Cocoa.h>

@interface WindowDelegate : NSObject <NSWindowDelegate>
@property (weak, nonatomic) NSWindow *window;
- (instancetype)initWithWindow:(NSWindow *)window;
- (void)mouseDown:(NSEvent *)event;

@end