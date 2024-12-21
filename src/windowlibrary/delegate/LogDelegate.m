#import "logWindow.h"

@interface LogDelegate : NSObject
@property (strong, nonatomic) LogViewer *logViewer;
+ (instancetype)sharedInstance;
@end

@implementation LogDelegate

+ (instancetype)sharedInstance {
    static LogDelegate *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[LogDelegate alloc] init]; 
        sharedInstance.logViewer = [[LogViewer alloc] init];
        [sharedInstance.logViewer showLogWindow];
    });
    return sharedInstance;
}

- (void)logMessage:(NSString *)message {
    [self.logViewer addLogMessage:message];
}

@end
