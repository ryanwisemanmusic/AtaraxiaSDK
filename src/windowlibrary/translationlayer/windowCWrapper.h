#ifndef WINDOW_C_WRAPPER_H
#define WINDOW_C_WRAPPER_H

#define WINDOW_STYLE_TITLED 1 << 0
#define WINDOW_STYLE_CLOSABLE 1 << 1
#define WINDOW_STYLE_RESIZABLE 1 << 3
#define WINDOW_STYLE_MINIATURIZABLE (1 << 2)

#include <CoreGraphics/CGGeometry.h> 
#include <stdint.h> 

/*This makes sure that we pass in Cocoa by reference for any
object we call upon in this project.*/
#ifdef __OBJC__
#import <Cocoa/Cocoa.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*Anytime we want to pass through Obj-C code, we do it here
This is where we will set up the bulk majority of our functions*/
void *ataraxiaApplication(); 
void *createWindow(
    CGRect frame, int32_t style, const char *title); 

/*Make sure you do not use NS datatypes when it comes
to what you reference in function calls. 

For example, NSColor was returning an error during compiling with
make.*/
void setWindowBackgroundColor(void *window, void *color);

/*Fix the return type consistency for runApplication*/
void runApplication(void *app, void *window);  

#ifdef __cplusplus
}
#endif

#endif // WINDOW_C_WRAPPER_H







