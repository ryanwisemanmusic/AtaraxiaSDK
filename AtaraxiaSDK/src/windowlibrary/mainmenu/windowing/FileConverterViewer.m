#import "FileConverterViewer.h"

@interface FileConverterViewer ()

@property (strong, nonatomic) NSTextView *conversionTextView;
@property (strong, nonatomic) NSScrollView *scrollView;
@property (strong, nonatomic) NSTextField *fileNameLabel;

@end

@implementation FileConverterViewer

- (instancetype)init {
    self = [super initWithWindow:nil];
    if (self) {
        NSRect frame = NSMakeRect(0, 0, 600, 500);
        
        NSWindow *window = [[NSWindow alloc] initWithContentRect:frame
                                                      styleMask:(NSWindowStyleMaskTitled | NSWindowStyleMaskClosable | NSWindowStyleMaskResizable)
                                                        backing:NSBackingStoreBuffered
                                                          defer:NO];
        [window setTitle:@"File Converter"];
        [window setBackgroundColor:[NSColor whiteColor]];
        [self setWindow:window];

        self.scrollView = [[NSScrollView alloc] initWithFrame:NSMakeRect(20, 120, 560, 300)];
        self.scrollView.hasVerticalScroller = YES;
        
        self.conversionTextView = [[NSTextView alloc] initWithFrame:self.scrollView.bounds];
        self.conversionTextView.editable = NO;
        self.conversionTextView.font = [NSFont fontWithName:@"Monaco" size:12];
        self.conversionTextView.textColor = [NSColor blackColor];
        self.scrollView.documentView = self.conversionTextView;
        [[window contentView] addSubview:self.scrollView];

        NSButton *openFileButton = [[NSButton alloc] initWithFrame:NSMakeRect(20, 20, 100, 40)];
        [openFileButton setTitle:@"Open File"];
        [openFileButton setTarget:self];
        [openFileButton setAction:@selector(openFile:)];
        [openFileButton setBezelStyle:NSBezelStyleRounded];
        [[window contentView] addSubview:openFileButton];

        self.fileNameLabel = [[NSTextField alloc] initWithFrame:NSMakeRect(140, 20, 400, 40)];
        self.fileNameLabel.editable = NO;
        self.fileNameLabel.bezeled = NO;
        self.fileNameLabel.backgroundColor = [NSColor clearColor];
        self.fileNameLabel.textColor = [NSColor blackColor];
        self.fileNameLabel.font = [NSFont systemFontOfSize:14];
        self.fileNameLabel.alignment = NSTextAlignmentLeft;
        [self.fileNameLabel setStringValue:@"No file selected"];
        [[window contentView] addSubview:self.fileNameLabel];

        // Debug: Ensure layers are enabled
        [[window contentView] setWantsLayer:YES];
        self.scrollView.wantsLayer = YES;
        self.fileNameLabel.wantsLayer = YES;
        self.conversionTextView.wantsLayer = YES;

        // Debug: Log subviews
        NSLog(@"Subviews in window content view: %@", [[self.window contentView] subviews]);
    }
    return self;
}

- (void)showFileConverterWindow {
    NSLog(@"FileConverterViewer window shown");
    [self showWindow:nil];
}

- (void)addConversionLogMessage:(NSString *)message {
    NSString *existingText = self.conversionTextView.string ?: @"";
    NSString *newText = [existingText stringByAppendingFormat:@"\n%@", message];
    [self.conversionTextView setString:newText];
    [self.conversionTextView scrollRangeToVisible:NSMakeRange(newText.length - 1, 1)];
}

- (void)openFile:(id)sender {
    NSOpenPanel *openPanel = [NSOpenPanel openPanel];
    [openPanel setAllowsMultipleSelection:NO];
    [openPanel setCanChooseFiles:YES];
    [openPanel setCanChooseDirectories:NO];

    [openPanel beginWithCompletionHandler:^(NSInteger result) {
        if (result == NSModalResponseOK) {
            NSURL *fileURL = [openPanel URL];
            NSString *fileName = [fileURL lastPathComponent];
            
            [self.fileNameLabel setStringValue:[NSString stringWithFormat:@"Selected file: %@", fileName]];

            [self addConversionLogMessage:[NSString stringWithFormat:@"File selected: %@", fileURL.path]];

            NSLog(@"File selected: %@", fileURL.path);
        }
    }];
}

@end




