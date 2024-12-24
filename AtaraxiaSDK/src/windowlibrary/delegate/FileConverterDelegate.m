#import "FileConverterDelegate.h"
#import "FileConverterWindow.h"

@implementation FileConverterDelegate

+ (instancetype)sharedInstance {
    static FileConverterDelegate *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[FileConverterDelegate alloc] init];
        sharedInstance.FileConverterWindow = [[FileConverterWindow alloc] init];
    });
    return sharedInstance;
}

- (void)showFileConverterWindow {
    [self.FileConverterWindow showFileConverterWindow];
}

@end


