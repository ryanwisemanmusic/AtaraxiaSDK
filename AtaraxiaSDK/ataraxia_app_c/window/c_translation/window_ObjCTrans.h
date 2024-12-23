/*This is our Obj-C header that allows the objects under Windows, 
which is stored under Obj-C code, to be accessed by C code.

Since a lot of these Cocoa objects and not accessible in standard C 
(for example, NSWindow is very much something that is easier done in
Obj-C), we must give some if statements that parse when we reference
Obj-C.
*/

#ifndef WINDOW_OBJC_TRANS_H
#define WINDOW_OBJC_TRANS_H

#ifdef __OBJC__
#import <Cocoa/Cocoa.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

/*If we are referencing Obj-C, define these objects. ifdef is the way
we handle the bridge between the two languages. Since our backend
is entirely in Obj-C, this is an important bridge*/
void *ataraxiaApplication(void);
void *createWindow(
    CGRect frame, int32_t style, 
    const char *title);
void runApplication(void*app, void *window);

#ifdef __cplusplus
}
#endif

#endif