#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface FileConversionUtility : NSObject

- (NSData *)convertDocumentToPDF:(NSURL *)fileURL;

- (NSData *)convertDocumentToTXT:(NSURL *)fileURL;

@end

NS_ASSUME_NONNULL_END