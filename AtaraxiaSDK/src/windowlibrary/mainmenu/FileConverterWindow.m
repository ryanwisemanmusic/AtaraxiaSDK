#import "FileConverterWindow.h"

@implementation FileConverterWindowController

- (instancetype)init {
    self = [super initWithWindowNibName:@"FileConverterWindow"];
    if (self) {
        //Initialize zone
    }
    return self;
}

- (void)showFileConverterWindow {
    [self showWindow:self];
}

@end