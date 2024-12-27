#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ImageConversionUtility : NSObject

- (NSData *)convertImageToJPEG:(NSURL *)fileURL;

- (NSData *)convertImageToPNG:(NSURL *)fileURL;

@end

NS_ASSUME_NONNULL_END