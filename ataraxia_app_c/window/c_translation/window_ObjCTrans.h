#ifndef TRANSLATION_HEADER_H
#define TRANSLATION_HEADER_H

#ifdef __OBJC__
#import <Cocoa/Cocoa.h>
#endif

#ifdef __OBJC__
NSApplication *ataraxiaApplication();
NSWindow *createWindow(
    NSRect frame, NSInteger style, 
    NSString *title);
void runApplication(NSApplication *app, NSWindow *window);
#endif

#endif