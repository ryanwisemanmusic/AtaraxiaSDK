#import "ImageConverter.h"

@implementation ImageConverter

- (void)convertImageToPNG:(NSURL *)fileURL toExportPath:(NSString *)exportPath {
    NSLog(@"Converting %@ to PNG, saving to %@", fileURL, exportPath);
}

- (void)convertImageToJPEG:(NSURL *)fileURL toExportPath:(NSString *)exportPath {
    NSLog(@"Converting %@ to JPEG, saving to %@", fileURL, exportPath);
}

@end