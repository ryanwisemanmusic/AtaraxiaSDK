#import <Foundation/Foundation.h>

void logMessage(NSString *message) {
    NSString *logPath = [NSHomeDirectory() stringByAppendingPathComponent:@"Documents/MyApp.log"];
    if (![[NSFileManager defaultManager] fileExistsAtPath:logPath]) {
        [[NSFileManager defaultManager] createFileAtPath:logPath contents:nil attributes:nil];
    }
    
    NSFileHandle *fileHandle = [NSFileHandle fileHandleForWritingAtPath:logPath];
    if (!fileHandle) {
        NSLog(@"Failed to open log file for writing: %@", logPath);
        return;
    }
    [fileHandle seekToEndOfFile];

    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:@"yyyy-MM-dd HH:mm:ss"];
    NSString *timestamp = [formatter stringFromDate:[NSDate date]];

    NSString *formattedMessage = [NSString stringWithFormat:@"%@: %@\n", timestamp, message];
    [fileHandle writeData:[formattedMessage dataUsingEncoding:NSUTF8StringEncoding]];
    [fileHandle closeFile];
}
