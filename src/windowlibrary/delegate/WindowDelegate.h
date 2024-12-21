#ifndef WINDOWDELEGATE_H
#define WINDOWDELEGATE_H

#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>

@class WindowDelegate;

@interface WindowDelegate : NSObject <NSWindowDelegate> 

@property (nonatomic, strong) NSWindow *window;

- (instancetype)initWithWindow:(NSWindow *)window;
- (void)mouseDown:(NSEvent *)event;
- (void)switchWindowColor:(NSColor *)nextColor forWindow:(NSWindow *)window;
- (void)windowWillClose:(NSNotification *)notification;
- (BOOL)windowShouldClose:(NSWindow *)sender;

@end

#endif



