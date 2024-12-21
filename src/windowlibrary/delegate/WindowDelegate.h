#ifndef WINDOWDELEGATE_H
#define WINDOWDELEGATE_H

#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>

@class WindowDelegate;

@interface WindowDelegate : NSObject <NSWindowDelegate>

@property (nonatomic, strong) NSWindow *window;

- (instancetype)initWithWindow:(NSWindow *)window;
- (void)mouseDown:(NSEvent *)event;
- (void)mouseUp:(NSEvent *)event;  // Add mouseUp event handling if you want to use it
- (void)switchWindowColor:(NSColor *)nextColor forWindow:(NSWindow *)window;
- (void)windowWillClose:(NSNotification *)notification;
- (void)switchToNextScreen;

@end

#endif




