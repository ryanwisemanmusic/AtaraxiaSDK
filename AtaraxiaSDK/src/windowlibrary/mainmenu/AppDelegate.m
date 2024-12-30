#import "AppDelegate.h"
#import "FileConverterDelegate.h"
#import "LogViewer.h"

@implementation AppDelegate

- (instancetype)init {
    self = [super init];
    if (self) {
        [self setupAppMenu]; // Set up the app menu when the app starts
        self.logViewer = [[LogViewer alloc] init];  // Initialize logViewer
    }
    return self;
}

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    // Any additional setup you need after the application launches
    if (!self.logViewer) {
        self.logViewer = [[LogViewer alloc] init];  // Ensure logViewer is initialized
    }
}

- (void)setupAppMenu {
    // Create the main menu
    NSMenu *mainMenu = [[NSMenu alloc] initWithTitle:@"Main Menu"];

    // "SimpleWindow" menu
    NSMenuItem *windowMenuItem = [[NSMenuItem alloc] initWithTitle:@"SimpleWindow" action:nil keyEquivalent:@""];
    NSMenu *windowMenu = [[NSMenu alloc] initWithTitle:@"Window"];
    [windowMenuItem setSubmenu:windowMenu];
    [mainMenu addItem:windowMenuItem];

    // "Quit" menu item
    self.quitMenuItem = [[NSMenuItem alloc] initWithTitle:@"Quit SimpleWindow" action:@selector(quitApplication:) keyEquivalent:@"q"];
    [self.quitMenuItem setKeyEquivalentModifierMask:NSEventModifierFlagCommand];
    [windowMenu addItem:self.quitMenuItem];

    // "File" menu with "New File Conversion"
    NSMenuItem *fileMenuItem = [[NSMenuItem alloc] initWithTitle:@"File" action:nil keyEquivalent:@""];
    NSMenu *fileMenu = [[NSMenu alloc] initWithTitle:@"File"];
    [fileMenuItem setSubmenu:fileMenu];
    [mainMenu addItem:fileMenuItem];

    // "New File Conversion" menu item
    NSMenuItem *newFileConversionMenuItem = [[NSMenuItem alloc] initWithTitle:@"New File Conversion" action:@selector(showFileConverter:) keyEquivalent:@""];
    [fileMenu addItem:newFileConversionMenuItem];

    // "Edit" menu with "Copy" option
    NSMenuItem *editMenuItem = [[NSMenuItem alloc] initWithTitle:@"Edit" action:nil keyEquivalent:@""];
    NSMenu *editMenu = [[NSMenu alloc] initWithTitle:@"Edit"];
    [editMenuItem setSubmenu:editMenu];
    [mainMenu addItem:editMenuItem];

    // "Copy" menu item
    NSMenuItem *copyMenuItem = [[NSMenuItem alloc] initWithTitle:@"Copy" action:@selector(copyTextFromLogViewer:) keyEquivalent:@"c"];
    [copyMenuItem setKeyEquivalentModifierMask:NSEventModifierFlagCommand];
    [editMenu addItem:copyMenuItem];

    // Set the app's main menu
    [NSApp setMainMenu:mainMenu];
}

- (void)quitApplication:(id)sender {
    NSLog(@"Quit application triggered.");
    [NSApp terminate:nil];
}

- (void)showFileConverter:(id)sender {
    // Show the File Converter window using the FileConverterDelegate
    [[FileConverterDelegate sharedInstance] showFileConverterWindow];
}

- (void)copyTextFromLogViewer:(id)sender {
    // Check if the LogViewer instance exists
    if (self.logViewer) {
        // Get the log text from the LogViewer instance
        NSString *logText = [self.logViewer getLogText];
        
        // Debug log to check the content
        NSLog(@"Log text fetched: %@", logText);
        
        // Make sure logText is not empty
        if (logText && logText.length > 0) {
            // Copy it to the clipboard
            NSPasteboard *pasteboard = [NSPasteboard generalPasteboard];
            [pasteboard clearContents];  // Clear existing pasteboard contents
            [pasteboard setString:logText forType:NSPasteboardTypeString];  // Set new string
            
            // Debug log to confirm text has been copied
            NSLog(@"Log text copied to clipboard: %@", logText);
            
            // Add a delay to ensure pasteboard operation completes
            dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(0.1 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
                // Try reading back from the pasteboard to confirm
                NSString *clipboardContent = [pasteboard stringForType:NSPasteboardTypeString];
                NSLog(@"Clipboard content after copy: %@", clipboardContent);  // Should match the logText
                
                // Check if the clipboard content matches
                if ([clipboardContent isEqualToString:logText]) {
                    NSLog(@"Clipboard successfully set.");
                } else {
                    NSLog(@"Clipboard not set correctly.");
                }
            });
        } else {
            NSLog(@"No log text to copy.");
        }
    } else {
        NSLog(@"LogViewer not found.");
    }
}

// Example method to get the LogViewer instance
- (LogViewer *)getLogViewerInstance {
    // You can implement this method to return the currently displayed LogViewer instance.
    return self.logViewer; // Assuming you have a reference to the LogViewer instance
}

- (void)showLogWindow {
    if (!self.logViewer) {
        self.logViewer = [[LogViewer alloc] init];  // Create LogViewer if not already created
    }
    [self.logViewer showLogWindow];  // Show the window
}

@end
