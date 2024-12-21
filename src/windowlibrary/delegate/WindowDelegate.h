#ifndef WINDOWDELEGATE_H
#define WINDOWDELEGATE_H

#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>

@class WindowDelegate;

@interface WindowDelegate : NSObject <NSWindowDelegate>

// Reference to the window
@property (nonatomic, strong) NSWindow *window;

// Initialization method with window
- (instancetype)initWithWindow:(NSWindow *)window;

// Mouse event handling
- (void)mouseDown:(NSEvent *)event;
- (void)mouseUp:(NSEvent *)event;  // Optional: add mouse up handling

// Color switching and screen transitions
- (void)switchWindowColor:(NSColor *)nextColor forWindow:(NSWindow *)window;
- (void)windowWillClose:(NSNotification *)notification;

// Transition to next screen (example logic)
- (void)switchToNextScreen;

@end

#endif





