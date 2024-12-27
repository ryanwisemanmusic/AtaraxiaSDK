#import "FileConversionUtility.h"
#import <Quartz/Quartz.h>

@implementation FileConversionUtility

- (NSData *)convertDocumentToPDF:(NSURL *)fileURL {

    NSString *documentContent = [NSString stringWithContentsofURL:fileURL encoding:NSUTF8StringEncoding error:nil];

    if (!documentContent) {
        NSLog(@"Error reading file at %@", fileURL);
        return nil;
    }

    NSMutableData *pdfData = [NSMutableData data];
    CGContextRef context = CGPDFContextCreateWithURL((__bridge CFURLRef)fileURL, NULL, NULL);
    CGContextBeginPage(context, NULL);

    [documentContent drawInRect:CGRectMake(100, 100, 400, 800)
                 withAttributes:@{NSFontAttributeName: [UIFont systemFontOfSize:12]}];

    CGContextEndPage(context);
    CGContextRelease(context);

    return pdfData;
}

- (NSData *)convertDocumentToTXT:(NSURL *)fileURL {
    NSString *txtContent = [NSString stringWithContentsofURL:fileURL encoding:NSUTF8StringEncoding error:nil];
    if (!txtContent) {
        NSLog(@"Error reading file at %@", fileURL);
        return nil;
    }

    return [txtContent dataUsingEncoding:NSUTF8StringEncoding];
}



