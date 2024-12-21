#import <Foundation/Foundation.h>
#import "logWindow.h"

@interface LogDelegate : NSObject

+ (instancetype)sharedInstance;
- (void)logMessage:(NSString *)message;

@end