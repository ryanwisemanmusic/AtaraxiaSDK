#import "FileConverterWindow.h"
#import <UniformTypeIdentifiers/UniformTypeIdentifiers.h> // Import the UniformTypeIdentifiers framework

@interface FileConverterWindow ()

@property (nonatomic, strong) NSTextField *fileNameLabel; // To display the selected file name

@end

@implementation FileConverterWindow

- (instancetype)init {
    self = [super init];
    if (self) {
        // Window setup
        NSRect frame = NSMakeRect(0, 0, 600, 400); 
        NSWindow *window = [[NSWindow alloc] initWithContentRect:frame
                                                      styleMask:(NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskResizable)
                                                        backing:NSBackingStoreBuffered
                                                          defer:NO];
        [window setTitle:@"File Converter"];
        [window setBackgroundColor:[NSColor whiteColor]]; // Set background color to white
        [self setWindow:window];
        
        // Add "Open File" button
        NSButton *openButton = [[NSButton alloc] initWithFrame:NSMakeRect(20, 100, 100, 30)];
        [openButton setTitle:@"Open File"];
        [openButton setTarget:self];
        [openButton setAction:@selector(openFile:)];
        [openButton setBezelStyle:NSBezelStyleRounded];  // Ensure rounded button style
        [openButton setFont:[NSFont systemFontOfSize:14]]; // Optional: Set font size for better visibility
        
        // Set button text color using an attributed string
        NSAttributedString *buttonTitle = [[NSAttributedString alloc] initWithString:@"Open File"
                                                                         attributes:@{NSForegroundColorAttributeName: [NSColor blackColor]}];
        [openButton setAttributedTitle:buttonTitle];

        [[window contentView] addSubview:openButton];
        
        // Add label to display the selected file name
        self.fileNameLabel = [[NSTextField alloc] initWithFrame:NSMakeRect(140, 100, 400, 30)];
        [self.fileNameLabel setEditable:NO];
        [self.fileNameLabel setBordered:NO];
        [self.fileNameLabel setBackgroundColor:[NSColor clearColor]];
        [self.fileNameLabel setFont:[NSFont systemFontOfSize:14]];
        [self.fileNameLabel setTextColor:[NSColor blackColor]]; // Set the text color to black
        [self.fileNameLabel setStringValue:@"No file selected"];
        [[window contentView] addSubview:self.fileNameLabel];
        
        // Debug: Enable layer support for content view and subviews
        [[window contentView] setWantsLayer:YES];
        [self.fileNameLabel setWantsLayer:YES];
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

        [self.fileNameLabel setStringValue:selectedFileURL.lastPathComponent];
    }
}

@end






