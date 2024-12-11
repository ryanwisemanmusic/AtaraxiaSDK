#import <Cocoa/Cocoa.h>

#ifndef WINDOW_C_WRAPPER_H
#define WINDOW_C_WRAPPER_H

#ifdef __cplusplus
extern "C" {
#endif

NSApplication *ataraxiaApplication(); 
NSWindow *createWindow(
    NSRect frame, NSInteger style, 
    NSString *title); 

void runApplication(
    NSApplication *app, NSWindow *window);  

#ifdef __cplusplus
}

#endif

#endif

