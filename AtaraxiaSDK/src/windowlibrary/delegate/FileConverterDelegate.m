#import "FileConverterDelegate.h"
#import "FileConverterWindow.h"

@interface FileConverterDelegate ()
@property (strong, nonatomic) FileConverterWindow *fileConverterWindow; // Private property
@end

@implementation FileConverterDelegate

+ (instancetype)sharedInstance {
    static FileConverterDelegate *sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[FileConverterDelegate alloc] init];
    });
    return sharedInstance;
}

- (instancetype)init {
    self = [super init];
    if (self) {
        _fileConverterWindow = [[FileConverterWindow alloc] init];
    }
    return self;
}

- (void)showFileConverterWindow {
    [self.fileConverterWindow showFileConverterWindow];
}

@end



