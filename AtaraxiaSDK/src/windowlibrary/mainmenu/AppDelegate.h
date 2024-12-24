#import <Cocoa/Cocoa.h>

@interface AppDelegate : NSObject <NSApplicationDelegate>

@property (strong, nonatomic) NSMenu *appMenu;
@property (strong, nonatomic) NSMenuItem *quitMenuItem;

- (void)quitApplication:(id)sender;
- (IBAction)showFileConverter:(id)sender;

@end
