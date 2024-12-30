#import "ImageConversionUtility.h"
#import <CoreGraphics/CoreGraphics.h>
#import <AppKit/AppKit.h>
#import <UniformTypeIdentifiers/UniformTypeIdentifiers.h> 

@implementation ImageConversionUtility

- (NSData *)convertImageToJPEG:(NSURL *)fileURL {
    NSImage *image = [[NSImage alloc] initWithContentsOfURL:fileURL];
    if (!image) {
        NSLog(@"Error reading image at %@", fileURL);
        return nil;
    }

    CGImageRef cgImage = [self CGImageFromNSImage:image];
    if (!cgImage) {
        NSLog(@"Error converting NSImage to CGImage");
        return nil;
    }

    NSMutableData *jpegData = [NSMutableData data];
    CGImageDestinationRef destination = CGImageDestinationCreateWithData((__bridge CFMutableDataRef)jpegData, (__bridge CFStringRef)UTTypeJPEG.identifier, 1, NULL);
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

    CGImageRef cgImage = [self CGImageFromNSImage:image];
    if (!cgImage) {
        NSLog(@"Error converting NSImage to CGImage");
        return nil;
    }

    NSMutableData *pngData = [NSMutableData data];
    CGImageDestinationRef destination = CGImageDestinationCreateWithData((__bridge CFMutableDataRef)pngData, (__bridge CFStringRef)UTTypePNG.identifier, 1, NULL);
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
    NSRect imageRect = NSMakeRect(0, 0, image.size.width, image.size.height);
    CGImageRef cgImage = [image CGImageForProposedRect:&imageRect context:nil hints:nil];
    return cgImage;
}

@end
