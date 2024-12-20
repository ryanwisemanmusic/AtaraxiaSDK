#ifndef SCREEN_MANAGEMENT_H
#define SCREEN_MANAGEMENT_H

#import <Foundation/Foundation.h>
#import <Cocoa/Cocoa.h>

@interface ScreenManager : NSObject

+ (NSArray<NSColor *> *)getScreenColors;
+ (void)showIntroTitle;
+ (void)showMainScreen1;
+ (void)handleScreenTransition:(NSWindow *)window;

@end

#endif



