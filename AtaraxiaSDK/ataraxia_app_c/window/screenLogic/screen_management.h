#ifndef SCREEN_MANAGEMENT_H
#define SCREEN_MANAGEMENT_H

#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>
#import "WindowDelegate.h" 

@interface ScreenManager : NSObject

+ (NSArray<NSColor *> *)getScreenColors;
+ (void)showIntroTitle;
+ (void)showMainScreen1;
+ (void)handleScreenTransition:(NSWindow *)window withWindowDelegate:(WindowDelegate *)windowDelegate; 

@end

#endif




