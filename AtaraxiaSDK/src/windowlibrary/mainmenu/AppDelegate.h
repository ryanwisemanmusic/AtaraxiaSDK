#import <Cocoa/Cocoa.h>
#import "FileConverterWindow.h"

@interface AppDelegate: NSObject <NSApplicationDelegate>

@property (strong, nonatomic) NSMenu *appMenu;
@property (strong, nonatomic) NSMenuItem *quitMenuItem;
@property (strong, nonatomic) FileConverterWindowController *FileConverterWindowController;

- (void)quitApplication:(id)sender;
- (IBAction)showFileConverter:(id)sender;

@end