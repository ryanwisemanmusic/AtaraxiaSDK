#import "ImageConversionUtility.h"
#import <CoreGraphics/CoreGraphics.h>
#import <AppKit/AppKit.h>

@implementation ImageConversionUtility

- (NSData *)convertImageToJPEG:(NSURL *)fileURL {
    NSImage *image = [[NSImage alloc] initWithContentsOfURL:fileURL];
    if (!image) {
        NSLog(@"Error reading image at %@", fileURL);
        return nil;
    }

    // Extract CGImageRef from NSImage
    CGImageRef cgImage = [self CGImageFromNSImage:image];
    if (!cgImage) {
        NSLog(@"Error converting NSImage to CGImage");
        return nil;
    }

    // Create a JPEG representation
    NSMutableData *jpegData = [NSMutableData data];
    CGImageDestinationRef destination = CGImageDestinationCreateWithData((__bridge CFMutableDataRef)jpegData, kUTTypeJPEG, 1, NULL);
    if (!destination) {
        NSLog(@"Error creating JPEG destination");
        return nil;
    }

    CGImageDestinationAddImage(destination, cgImage, NULL);
    if (!CGImageDestinationFinalize(destination)) {
        NSLog(@"Error finalizing JPEG image destination");
        CFRelease(destination);
        return nil;
    }

    CFRelease(destination);
    return jpegData;
}

- (NSData *)convertImageToPNG:(NSURL *)fileURL {
    NSImage *image = [[NSImage alloc] initWithContentsOfURL:fileURL];
    if (!image) {
        NSLog(@"Error reading image at %@", fileURL);
        return nil;
    }

    // Extract CGImageRef from NSImage
    CGImageRef cgImage = [self CGImageFromNSImage:image];
    if (!cgImage) {
        NSLog(@"Error converting NSImage to CGImage");
        return nil;
    }

    // Create a PNG representation
    NSMutableData *pngData = [NSMutableData data];
    CGImageDestinationRef destination = CGImageDestinationCreateWithData((__bridge CFMutableDataRef)pngData, kUTTypePNG, 1, NULL);
    if (!destination) {
        NSLog(@"Error creating PNG destination");
        return nil;
    }

    CGImageDestinationAddImage(destination, cgImage, NULL);
    if (!CGImageDestinationFinalize(destination)) {
        NSLog(@"Error finalizing PNG image destination");
        CFRelease(destination);
        return nil;
    }

    CFRelease(destination);
    return pngData;
}

- (CGImageRef)CGImageFromNSImage:(NSImage *)image {
    // Get the best representation of the image as a CGImage
    NSRect imageRect = NSMakeRect(0, 0, image.size.width, image.size.height);
    CGImageRef cgImage = [image CGImageForProposedRect:&imageRect context:nil hints:nil];
    return cgImage;
}

@end
