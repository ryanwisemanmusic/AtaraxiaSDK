#import "FileConverterViewer.h"

@interface FileConverterViewer ()

@property (strong, nonatomic) NSTextView *conversionTextView;
@property (strong, nonatomic) NSScrollView *scrollView;

@end

@implementation FileConverterViewer

- (instancetype)init {
    self = [super initWithWindow:nil];
    if (self) {
        // Define the window frame
        NSRect frame = NSMakeRect(0, 0, 600, 500);
        
        // Create the window programmatically
        NSWindow *window = [[NSWindow alloc] initWithContentRect:frame
                                                      styleMask:(NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskResizable)
                                                        backing:NSBackingStoreBuffered
                                                          defer:NO];
        [window setTitle:@"File Converter"];
        [self setWindow:window];

        // Create the text view for log messages or file conversion details
        self.conversionTextView = [[NSTextView alloc] initWithFrame:NSMakeRect(0, 0, 400, 300)];
        [self.conversionTextView setEditable:NO]; // Make it read-only
        [self.conversionTextView setFont:[NSFont fontWithName:@"Monaco" size:12]]; // Monospaced font

        // Create a scroll view for the text view
        self.scrollView = [[NSScrollView alloc] initWithFrame:frame];
        [self.scrollView setDocumentView:self.conversionTextView];
        [self.scrollView setHasVerticalScroller:YES];
        [self.scrollView setAutohidesScrollers:YES];
        [[window contentView] addSubview:self.scrollView];

        // Resize the scroll view and text view with the window
        [self.scrollView setAutoresizingMask:(NSViewWidthSizable | NSViewHeightSizable)];
    }
    return self;
}

- (void)showFileConverterWindow {
    [self showWindow:nil]; // Show the File Converter window
}

- (void)addConversionLogMessage:(NSString *)message {
    NSString *existingText = self.conversionTextView.string;
    NSString *newText = [existingText stringByAppendingFormat:@"\n%@", message];
    
    // Append the log message
    [self.conversionTextView setString:newText];
    
    // Optionally scroll to the bottom
    [self.conversionTextView scrollRangeToVisible:NSMakeRange(newText.length - 1, 1)];
}

@end
