#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ImageConverter : NSObject

- (void)convertImageToPNG:(NSURL *)fileURL toExportPath:(NSString *)exportPath;

- (void)convertImageToJPEG:(NSURL *)fileURL toExportPath:(NSString *)exportPath;

@end

NS_ASSUME_NONNULL_END