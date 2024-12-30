#import "FileConversionUtility.h"
#import <Quartz/Quartz.h>
#import <AppKit/AppKit.h>

@implementation FileConversionUtility

- (NSData *)convertDocumentToPDF:(NSURL *)fileURL {
    NSError *error = nil;
    NSString *documentContent = [NSString stringWithContentsOfURL:fileURL encoding:NSUTF8StringEncoding error:&error];

    if (!documentContent) {
        NSLog(@"Error reading file at %@: %@", fileURL, error.localizedDescription);
        return nil;
    }

    NSURL *tempPDFURL = [NSURL fileURLWithPath:[NSTemporaryDirectory() stringByAppendingPathComponent:@"temp.pdf"]];
    CGRect mediaBox = CGRectMake(0, 0, 612, 792); // Letter size
    CGContextRef context = CGPDFContextCreateWithURL((__bridge CFURLRef)tempPDFURL, &mediaBox, NULL);

    if (!context) {
        NSLog(@"Error creating PDF context");
        return nil;
    }

    CGContextBeginPage(context, NULL);

    NSDictionary *attributes = @{NSFontAttributeName: [NSFont systemFontOfSize:12]};
    [documentContent drawInRect:CGRectMake(100, 100, 400, 800) withAttributes:attributes];

    CGContextEndPage(context);
    CGContextRelease(context);

    NSData *pdfData = [NSData dataWithContentsOfURL:tempPDFURL];
    [[NSFileManager defaultManager] removeItemAtURL:tempPDFURL error:nil]; 

    return pdfData;
}


- (NSData *)convertDocumentToTXT:(NSURL *)fileURL {
    NSError *error = nil;
    NSString *txtContent = [NSString stringWithContentsOfURL:fileURL encoding:NSUTF8StringEncoding error:&error];

    if (!txtContent) {
        NSLog(@"Error reading file at %@: %@", fileURL, error.localizedDescription);
        return nil;
    }

    return [txtContent dataUsingEncoding:NSUTF8StringEncoding];
}

@end

