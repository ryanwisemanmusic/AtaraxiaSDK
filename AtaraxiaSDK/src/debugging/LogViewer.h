#import <Cocoa/Cocoa.h>

@interface LogViewer : NSWindowController

- (void)showLogWindow;
- (void)addLogMessage:(NSString *)message;
- (NSString *)getLogText;

@end





