/*
Author: Ryan Wiseman

Macs have a very specific menu call appraoch that isn't accessible by
SDL. Because of it, we are required to use Obj-C, paricularly, 
the Cocoa library.

*/
#import <Cocoa/Cocoa.h>

/* If you need additional menu calls, you do this by making 
   external functions. that will get implemented in C++. 
   We need these to be external, so we can call to Obj-C code
   in C++. */

extern "C" void openSDLWindowAboutMenu();
extern "C" void  cocoaBaseMenuBar()
{
    NSApplication *app = [NSApplication sharedApplication];

    NSMenu *menuBar = [[NSMenu alloc] init];
    NSMenuItem *appMainMenuToolbar = [[NSMenuItem alloc] init];
    [menuBar addItem:appMainMenuToolbar];
    //We store this so when we call upon it, we create an application menu
    NSMenu *mainMenu = [[NSMenu alloc] init];

    /* For your own application, update the initWithTitle's string with your own
       application name. This is set to the name of the underlying SDK I've built. */
    NSMenuItem *aboutMenuItem = [[NSMenuItem alloc] initWithTitle:@"About AtaraxiaSDK"
                                                           action:@selector(orderFrontStandardAboutPanel:)
                                                    keyEquivalent:@""];

    //Do not modify, this is to quit the application. If this gets changed, the button won't work
    NSMenuItem *quitMenuItem = [[NSMenuItem alloc] initWithTitle:@"Quit"
                                                          action:@selector(terminate:)
                                                   keyEquivalent:@"q"];
    
    //Order matters if you decide to add additional menu itmes
    [mainMenu addItem:aboutMenuItem];
    [mainMenu addItem:quitMenuItem];

    //After creating the menu items, we set a dropdown window
    [appMainMenuToolbar setSubmenu:mainMenu];

    //When then create the menu bar that is displayed for the user
    [app setMainMenu:menuBar];
}