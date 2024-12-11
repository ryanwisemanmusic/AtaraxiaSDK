#import <Cocoa/Cocoa.h>

//We store this NSApplication as a pointer
NSApplication *ataraxiaApplication();

//We then store a function related to the window itself
NSWindow *createWindow(
    NSRect frame, NSInteger style, NSString *title);

//Our nonreturn fuction we use as means of 
//referencing the app and window pointer
void runApplication(NSApplication *app, NSWindow *window);
