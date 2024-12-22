#import "LogViewer.h"

@interface LogViewer ()

@property (strong, nonatomic) NSTextView *logTextView;

@end

@implementation LogViewer

- (instancetype)init {
    self = [super initWithWindow:nil];
    if (self) {
        NSRect frame = NSMakeRect(0, 0, 400, 300);
        NSWindow *window = [[NSWindow alloc] initWithContentRect:frame
                                                       styleMask:(NSWindowStyleMaskTitled |
                                                                  NSWindowStyleMaskClosable |
                                                                  NSWindowStyleMaskResizable)
                                                         backing:NSBackingStoreBuffered
                                                           defer:NO];
        [window setTitle:@"Log Window"];
        [self setWindow:window];
        
        // Create a text view to display log messages
        self.logTextView = [[NSTextView alloc] initWithFrame:NSMakeRect(0, 0, 400, 300)];
        [self.logTextView setEditable:NO]; // Make it read-only
        [self.logTextView setFont:[NSFont fontWithName:@"Monaco" size:12]]; // Use a monospaced font
        [[window contentView] addSubview:self.logTextView];
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

@end



