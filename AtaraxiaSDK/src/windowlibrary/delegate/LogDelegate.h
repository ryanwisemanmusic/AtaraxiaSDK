#import <Cocoa/Cocoa.h>

@class LogViewer; // Forward declaration of LogViewer

@interface LogDelegate : NSObject

@property (strong, nonatomic) LogViewer *logViewer; // Correct type for the LogViewer instance
@property (strong, nonatomic) NSPipe *logPipe;

+ (instancetype)sharedInstance;
- (void)showLogWindow;

@end





