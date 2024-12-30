#import "LogDelegate.h"
#import "LogViewer.h"

@implementation LogDelegate

+ (instancetype)sharedInstance {
    static LogDelegate *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[LogDelegate alloc] init];
        sharedInstance.logViewer = [[LogViewer alloc] init]; // Initialize LogViewer
        [sharedInstance.logViewer showLogWindow]; // Show LogViewer window
        [sharedInstance setupLogRedirection]; // Set up redirection for log messages
    });
    return sharedInstance;
}

- (void)setupLogRedirection {
    self.logPipe = [NSPipe pipe];
    NSFileHandle *fileHandle = self.logPipe.fileHandleForReading;
    
    // Redirect stderr to the pipe
    dup2(self.logPipe.fileHandleForWriting.fileDescriptor, STDERR_FILENO);
    
    // Use a weak reference to avoid retain cycle
    __weak typeof(fileHandle) weakFileHandle = fileHandle;
    dispatch_queue_t logQueue = dispatch_queue_create("com.logdelegate.queue", DISPATCH_QUEUE_SERIAL);
    fileHandle.readabilityHandler = ^(NSFileHandle *handle) {
        NSData *data = handle.availableData;
        if (data.length > 0) {
            NSString *log = [[NSString alloc] initWithData:data encoding:NSUTF8StringEncoding];
            
            // Dispatch to the main queue to update the UI
            dispatch_async(dispatch_get_main_queue(), ^{
                [self.logViewer addLogMessage:log]; // Ensure LogViewer displays the message
            });
        } else {
            weakFileHandle.readabilityHandler = nil; // Stop reading when no data
        }
    };
}

- (void)logMessage:(NSString *)message {
    [self.logViewer addLogMessage:message]; // Pass the log message to LogViewer
}

- (void)showLogWindow {
    [self.logViewer showLogWindow]; // Call LogViewer's showLogWindow method
}

- (NSString *)getLogText {
    // Provide the current log text from the LogViewer instance
    return [self.logViewer getLogText];
}

@end
