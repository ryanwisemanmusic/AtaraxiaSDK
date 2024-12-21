#import <Cocoa/Cocoa.h>

@interface LogViewer : NSObject

@property (strong, nonatomic) NSWindow *logWindow;
@property (strong, nonatomic) NSTextView *logTextView;
@property (strong, nonatomic) NSMutableArray<NSString *> *logMessages;

- (void)showLogWindow;
- (void)addLogMessage:(NSString *)message;

@end