#import "FileConverterWindow.h"

@implementation FileConverterWindow

- (instancetype)init {
    self = [super initWithWindowNibName:@"FileConverterWindow"];
    if (self) {
        // Initialization zone
    }
    return self;
}

- (void)showFileConverterWindow {
    [self showWindow:nil]; // Calls the inherited method to show the window
}

@end

