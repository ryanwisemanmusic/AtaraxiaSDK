#import <Cocoa/Cocoa.h>

extern "C" void  cocoaBaseMenuBar()
{
    NSApplication *app = [NSApplication sharedApplication];

    NSMenu *menuBar = [[NSMenu alloc] init];
    NSMenuItem *appMainMenuToolbar = [[NSMenuItem alloc] init];
    [menuBar addItem:appMainMenuToolbar];

    NSMenu *mainMenu = [[NSMenu alloc] init];
    NSMenuItem *quitMenuItem = [[NSMenuItem alloc] initWithTitle:@"Quit"
                                                          action:@selector(terminate:)
                                                   keyEquivalent:@"q"];
    
    [mainMenu addItem:quitMenuItem];
    [appMainMenuToolbar setSubmenu:mainMenu];

    [app setMainMenu:menuBar];
}