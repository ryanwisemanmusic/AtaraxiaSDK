#import <Cocoa/Cocoa.h>

// Function declarations for the C/C++ interface
NSApplication *ataraxiaApplication();
NSWindow *createWindow(
    NSRect frame, NSInteger style, 
    NSString *title);
    
void runApplication(NSApplication *app, NSWindow *window);

