#import <Cocoa/Cocoa.h>

@interface WindowDelegate : NSObject <NSWindowDelegate>
@property (weak, nonatomic) NSWindow *window;

- (void)switchWindowColor;
- (instancetype)initWithWindow:(NSWindow *)window;

@end

