#import "LogViewer.h"

@interface LogViewer ()

@property (strong, nonatomic) NSTextView *logTextView;
@property (strong, nonatomic) NSScrollView *scrollView;

@end

@implementation LogViewer

- (instancetype)init {
    self = [super initWithWindow:nil];
    if (self) {
        NSRect frame = NSMakeRect(0, 0, 600, 500);
        NSWindow *window = [
            [NSWindow alloc] initWithContentRect:frame
            styleMask:(NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskResizable)
            backing:NSBackingStoreBuffered
            defer:NO
        ];
        [window setTitle:@"Log Window"];
        [self setWindow:window];

        // Create a text view to display log messages
        self.logTextView = [[NSTextView alloc] initWithFrame:NSMakeRect(0, 0, 400, 300)];
        [self.logTextView setEditable:NO]; // Make it read-only
        [self.logTextView setFont:[NSFont fontWithName:@"Monaco" size:12]]; // Use a monospaced font
        
        // Add some test text
        [self addLogMessage:@"Initial test log message."];
        
        // Create a scroll view to contain the text view
        self.scrollView = [[NSScrollView alloc] initWithFrame:frame];
        [self.scrollView setDocumentView:self.logTextView];
        [self.scrollView setHasVerticalScroller:YES]; // Enable vertical scrolling
        [self.scrollView setAutohidesScrollers:YES];   // Hide the scroller when not needed
        [[window contentView] addSubview:self.scrollView];

        // Allow window resizing, making sure both the scroll view and text view resize
        [self.scrollView setAutoresizingMask:(NSViewWidthSizable | NSViewHeightSizable)];
    }
    return self;
}

- (void)showLogWindow {
    [self showWindow:nil]; // Show the log window
}

- (void)addLogMessage:(NSString *)message {
    NSString *existingText = self.logTextView.string;
    NSString *newText = [existingText stringByAppendingFormat:@"\n%@", message];
    
    // Append the new log message
    [self.logTextView setString:newText];
    
    // Optionally scroll to the bottom
    [self.logTextView scrollRangeToVisible:NSMakeRange(newText.length - 1, 1)];
}

- (NSString *)getLogText {
    if (self.logTextView.string.length > 0) {
        return self.logTextView.string;  // Return the text in the NSTextView
    } else {
        NSLog(@"LogViewer: No text in log.");
        return @"";  // Return an empty string if there's no text
    }
}


@end




