#import "FileConverterWindow.h"

@implementation FileConverterWindow

- (instancetype)init {
    self = [super init];
    if (self) {
        NSRect frame = NSMakeRect(0, 0, 600, 400); // Adjust size as needed
        NSWindow *window = [[NSWindow alloc] initWithContentRect:frame
                                                      styleMask:(NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskResizable)
                                                        backing:NSBackingStoreBuffered
                                                          defer:NO];
        [window setTitle:@"File Converter"];
        [self setWindow:window];
}
return self;

    return self;
}

- (void)showFileConverterWindow {
    [self showWindow:nil]; // Calls the inherited method to show the window
}

@end

