#import <Cocoa/Cocoa.h>

@class FileConverterWindow;

@interface FileConverterDelegate : NSObject

@property (strong, nonatomic, readonly) FileConverterWindow *FileConverterWindow;

+ (instancetype)sharedInstance;
- (void)showFileConverterWindow;

@end