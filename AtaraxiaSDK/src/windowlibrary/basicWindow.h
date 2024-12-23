#import <Cocoa/Cocoa.h>

// Function declarations for the C/C++ interface, using void* for compatibility
void *ataraxiaApplication(); 
void *createWindow(NSRect frame, NSInteger style, NSString *title); 
void runApplication(void *app, void *window); 


