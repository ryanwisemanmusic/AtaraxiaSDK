#import "AppDelegate.h"

@implementation AppDelegate

- (instancetype)init {
    self = [super init];
    if (self) {
        [self setupAppMenu];
    }
    return self;
}

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification 
{

}

- (void)setupAppMenu {
    NSMenu *mainMenu = [[NSMenu alloc] initWithTitle:@"Main Menu"];

    NSMenuItem *windowMenuItem = [[NSMenuItem alloc] initWithTitle:@"SimpleWindow" action:nil keyEquivalent:@""];
    NSMenu *windowMenu = [[NSMenu alloc] initWithTitle:@"Window"];
    [windowMenuItem setSubmenu:windowMenu];
    [mainMenu addItem:windowMenuItem];

    self.quitMenuItem = [[NSMenuItem alloc] initWithTitle:@"Quit SimpleWindow" action:@selector(quitApplication:) keyEquivalent:@"q"];
    [self.quitMenuItem setKeyEquivalentModifierMask:NSEventModifierFlagCommand];
    [windowMenu addItem:self.quitMenuItem];

    [NSApp setMainMenu:mainMenu];
}

- (void)quitApplication:(id)sender {
    NSLog(@"Quit application triggered.");
    [NSApp terminate:nil];
}

@end