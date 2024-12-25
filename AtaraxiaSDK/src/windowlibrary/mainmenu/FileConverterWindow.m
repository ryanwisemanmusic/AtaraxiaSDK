#import "FileConverterWindow.h"
#import <UniformTypeIdentifiers/UniformTypeIdentifiers.h> // Import the UniformTypeIdentifiers framework

@implementation FileConverterWindow

- (instancetype)init {
    self = [super init];
    if (self) {
        NSRect frame = NSMakeRect(0, 0, 600, 400); 
        NSWindow *window = [[NSWindow alloc] initWithContentRect:frame
                                                      styleMask:(NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskResizable)
                                                        backing:NSBackingStoreBuffered
                                                          defer:NO];
        [window setTitle:@"File Converter"];
        [self setWindow:window];
        
        NSButton *openButton = [[NSButton alloc] initWithFrame:NSMakeRect(20, 20, 100, 30)];
        [openButton setTitle:@"Open File"];
        [openButton setTarget:self];
        [openButton setAction:@selector(openFile:)];
        [window.contentView addSubview:openButton]; 
    }
    return self;
}

- (void)showFileConverterWindow {
    [self showWindow:nil]; 
}

- (void)openFile:(id)sender {
    NSLog(@"Open File method called");

    NSOpenPanel *panel = [NSOpenPanel openPanel];
    
    panel.allowedContentTypes = @[
        [UTType typeWithIdentifier:@"public.plain-text"], // for .txt files
        [UTType typeWithIdentifier:@"com.adobe.pdf"],    // for .pdf files
        [UTType typeWithIdentifier:@"public.jpeg"]       // for .jpg files
    ]; 

    panel.allowsMultipleSelection = NO;

    if ([panel runModal] == NSModalResponseOK) {
        NSURL *selectedFileURL = [panel URL];
        NSLog(@"File selected: %@", selectedFileURL);
    }
}

@end




