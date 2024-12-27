#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DocumentConverter: NSObject

- (void)convertDocumentToPDF:(NSURL *)fileURL toExportPath:(NSString *)exportPath;
- (void)convertDocumentToTXT:(NSURL *)fileURL toExportPath:(NSString *)exportPath;

@end

NS_ASSUME_NONNULL_END