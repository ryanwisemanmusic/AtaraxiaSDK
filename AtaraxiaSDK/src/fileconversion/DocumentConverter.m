#import "DocumentConverter.h"

@implementation DocumentConverter

- (void)convertDocumentToPDF:(NSURL *)fileURL toExportPath:(NSString *)exportPath {
    NSLog(@"Converting %@ to PDF, saving to %@", fileURL, exportPath);
}

- (void)convertDocumentToTXT:(NSURL *)fileURL toExportPath:(NSString *)exportPath { 
    NSLog(@"Converting %@ to TXT, saving to %@", fileURL, exportPath);
}

@end

