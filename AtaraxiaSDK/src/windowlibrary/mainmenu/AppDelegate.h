#import <Cocoa/Cocoa.h>
#import "LogViewer.h"  // Ensure LogViewer is properly imported

@interface AppDelegate : NSObject <NSApplicationDelegate>

@property (strong, nonatomic) NSMenu *appMenu;          // Menu for the app
@property (strong, nonatomic) NSMenuItem *quitMenuItem;  // Quit menu item
@property (strong, nonatomic) LogViewer *logViewer;     // LogViewer property to store the instance

- (void)quitApplication:(id)sender;               // Action for quitting the app
- (IBAction)showFileConverter:(id)sender;         // Action for showing file converter
- (void)copyTextFromLogViewer:(id)sender;          // Action for copying text from LogViewer

@end



