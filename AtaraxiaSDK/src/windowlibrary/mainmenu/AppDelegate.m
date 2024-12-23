#import "AppDelegate.h"

@implementation AppDelegate

- (instancetype)init {
    self = [super init];
    if (self) {
        [self setupAppMenu]; // Set up the app menu when the app starts
    }
    return self;
}

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification {
    // Any additional setup you need after the application launches
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

    // Set the app's main menu
    [NSApp setMainMenu:mainMenu];
}

- (void)quitApplication:(id)sender {
    NSLog(@"Quit application triggered.");
    [NSApp terminate:nil];
}

- (IBAction)showFileConverter:(id)sender {
    // If the file converter window controller isn't created yet, initialize it
    if (!self.FileConverterWindowController) {
        self.FileConverterWindowController = [[FileConverterWindowController alloc] init];
    }
    // Show the file converter window
    [self.FileConverterWindowController showFileConverterWindow];
}

@end
