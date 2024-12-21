#import "logWindow.h"

@implementation LogViewer

- (instancetype)init {
    self = [super init];
    if (self) {
        _logMessages = [NSMutableArray array];

        _logWindow = [[NSWindow alloc] initWithContentRect:NSMakeRect(100, 100, 500, 400)
                                                 styleMask:(NSWindowStyleMaskTitled |
                                                            NSWindowStyleMaskClosable |
                                                            NSWindowStyleMaskResizable)
                                                   backing:NSBackingStoreBuffered
                                                     defer:NO];
        _logWindow.title = @"Log Viewer";

        _logTextView = [[NSTextView alloc] initWithFrame:NSMakeRect(0, 0, 500, 400)];
        _logTextView.editable = NO;

        NSScrollView *scrollView = [[NSScrollView alloc] initWithFrame:_logWindow.contentView.frame];
        scrollView.documentView = _logTextView;
        scrollView.hasVerticalScroller = YES;
        [_logWindow setContentView:scrollView];
    }
    return self;
}

- (void)showLogWindow {
    [self.logWindow makeKeyAndOrderFront:nil];
}

- (void)addLogMessage:(NSString *)message {
    [_logMessages addObject:message];
    NSString *logText = [_logMessages componentsJoinedByString:@"\n"];
    [_logTextView setString:logText];
}

@end
