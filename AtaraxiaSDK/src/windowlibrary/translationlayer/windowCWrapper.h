#ifndef WINDOW_C_WRAPPER_H
#define WINDOW_C_WRAPPER_H

#define WINDOW_STYLE_TITLED 1 << 0
#define WINDOW_STYLE_CLOSABLE 1 << 1
#define WINDOW_STYLE_RESIZABLE 1 << 3
#define WINDOW_STYLE_MINIATURIZABLE (1 << 2)

#include <CoreGraphics/CGGeometry.h>
#include <stdint.h>

#ifdef __OBJC__
#import <Cocoa/Cocoa.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

// Function declarations
void *ataraxiaApplication();
void *createWindow(CGRect frame, int32_t style, const char *title);

#ifdef __OBJC__
// Declare the functions returning NSColor objects
NSArray<NSColor *> *getScreenColors(void);  // Returning an array of NSColor pointers
NSColor *getColorForIntro();
NSColor *getColorForMain();
#else
// For non-Objective-C code, declare them as void pointers
const void **getScreenColors(void); // Declare as returning void* for non-Objective-C code
void *getColorForIntro();
void *getColorForMain();
#endif

void setWindowBackgroundColor(void *window, void *color);
void runApplication(void *app, void *window);

#ifdef __cplusplus
}
#endif

#endif // WINDOW_C_WRAPPER_H
















