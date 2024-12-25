#import <Cocoa/Cocoa.h>

@interface FileConverterViewer : NSWindowController

- (void)showFileConverterWindow;

- (void)addConversionLogMessage:(NSString *)message;

- (void)openFile:(id)sender;

@end
