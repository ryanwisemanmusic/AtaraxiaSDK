/*This is our Obj-C header that allows the objects under Windows, 
which is stored under Obj-C code, to be accessed by C code.

Since a lot of these Cocoa objects and not accessible in standard C 
(for example, NSWindow is very much something that is easier done in
Obj-C), we must give some if statements that parse when we reference
Obj-C.
*/

#ifndef TRANSLATION_HEADER_H
#define TRANSLATION_HEADER_H

#ifdef __OBJC__
#import <Cocoa/Cocoa.h>
#endif

/*If we are referencing Obj-C, define these objects. ifdef is the way
we handle the bridge between the two languages. Since our backend
is entirely in Obj-C, this is an important bridge*/
#ifdef __OBJC__
NSApplication *ataraxiaApplication();
NSWindow *createWindow(
    NSRect frame, NSInteger style, 
    NSString *title);
void runApplication(NSApplication *app, NSWindow *window);
#endif

#endif