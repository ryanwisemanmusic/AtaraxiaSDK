#import <Cocoa/Cocoa.h>

@interface FileConverterWindow : NSWindowController

- (void)showFileConverterWindow; // Add this method to match the delegate call
- (void)openFile:(id)sender; // Declare the openFile method

@end


