#import "logWindow.h"

@interface LogDelegate : NSObject
@property (strong, nonatomic) LogViewer *logViewer;
@property (strong, nonatomic) NSPipe *logPipe;
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
        [sharedInstance setupLogRedirection];
    });
    return sharedInstance;
}

- (void)logMessage:(NSString *)message {
    [self.logViewer addLogMessage:message];
}

- (void)setupLogRedirection {
    self.logPipe = [NSPipe pipe];
    NSFileHandle *fileHandle = self.logPipe.fileHandleForReading;

    // Redirect stderr to the pipe
    dup2(self.logPipe.fileHandleForWriting.fileDescriptor, STDERR_FILENO);

    // Use a weak reference to avoid a retain cycle
    __weak NSFileHandle *weakFileHandle = fileHandle;
    dispatch_queue_t logQueue = dispatch_queue_create("com.logdelegate.queue", DISPATCH_QUEUE_SERIAL);
    fileHandle.readabilityHandler = ^(NSFileHandle *handle) {
        NSData *data = handle.availableData;
        if (data.length > 0) {
            NSString *log = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
            
            // Dispatch to the main queue to update the UI
            dispatch_async(dispatch_get_main_queue(), ^{
                [self logMessage:log];
            });
        } else {
            // Use the weak reference to break the retain cycle
            weakFileHandle.readabilityHandler = nil;
        }
    };
}


@end

