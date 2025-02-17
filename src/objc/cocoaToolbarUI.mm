/*
Author: Ryan Wiseman

Macs have a very specific menu call appraoch that isn't accessible by
SDL. Because of it, we are required to use Obj-C, paricularly, 
the Cocoa library.

*/
#import <Cocoa/Cocoa.h>
#import "cocoaToolbarHandler.h"

// AppDelegate declaration conforms to NSApplicationDelegate.
@interface AppDelegate : NSObject <NSApplicationDelegate>
- (IBAction)customAboutAction:(id)sender;
- (IBAction)blankOptionAction:(id)sender; 
- (IBAction)blankOption2Action:(id)sender;
- (IBAction)blankOption3Action:(id)sender;
- (IBAction)blankOption4Action:(id)sender;
- (IBAction)blankOption5Action:(id)sender;
- (IBAction)helpOption1Action:(id)sender; 
- (IBAction)helpOption2Action:(id)sender;
- (IBAction)helpOption3Action:(id)sender;
- (IBAction)helpOption4Action:(id)sender;
- (IBAction)helpOption5Action:(id)sender;
@end

@implementation AppDelegate

- (IBAction)customAboutAction:(id)sender {
    NSLog(@"customAboutAction triggered");
    openSDLWindowAboutMenu();
}

- (IBAction)blankOptionAction:(id)sender {
    NSLog(@"<operand 1> clicked!");
    [self openHelpWindowWithTitle:@"Help for Operand 1"];
}

- (IBAction)blankOption2Action:(id)sender {
    NSLog(@"<operand 2> clicked!");
    [self openHelpWindowWithTitle:@"Help for Operand 2"];
}

- (IBAction)blankOption3Action:(id)sender {
    NSLog(@"<operand 3> clicked!");
    [self openHelpWindowWithTitle:@"Help for Operand 3"];
}

- (IBAction)blankOption4Action:(id)sender {
    NSLog(@"<operand 4> clicked!");
    [self openHelpWindowWithTitle:@"Help for Operand 4"];
}

- (IBAction)blankOption5Action:(id)sender {
    NSLog(@"<operand 5> clicked!");
    [self openHelpWindowWithTitle:@"Help for Operand 5"];
}

- (IBAction)helpOption1Action:(id)sender {
    [self openHelpWindowWithTitle:@"Help Window 1"];
}

- (IBAction)helpOption2Action:(id)sender {
    [self openHelpWindowWithTitle:@"Help Window 2"];
}

- (IBAction)helpOption3Action:(id)sender {
    [self openHelpWindowWithTitle:@"Help Window 3"];
}

- (IBAction)helpOption4Action:(id)sender {
    [self openHelpWindowWithTitle:@"Help Window 4"];
}

- (IBAction)helpOption5Action:(id)sender {
    [self openHelpWindowWithTitle:@"Help Window 5"];
}

- (void)openHelpWindowWithTitle:(NSString *)title {
    NSWindow *helpWindow = [[NSWindow alloc] initWithContentRect:NSMakeRect(0, 0, 400, 300)
                                                    styleMask:(NSWindowStyleMaskTitled | NSWindowStyleMaskClosable)
                                                      backing:NSBackingStoreBuffered
                                                        defer:NO];
    [helpWindow setTitle:title];
    [helpWindow center];
    
    NSTextView *textView = [[NSTextView alloc] initWithFrame:NSMakeRect(0, 0, 400, 300)];
    [textView setString:[NSString stringWithFormat:@"This is the help content for %@.\n", title]];
    [textView setEditable:NO];
    [textView setSelectable:YES];
    
    NSScrollView *scrollView = [[NSScrollView alloc] initWithFrame:NSMakeRect(0, 0, 400, 300)];
    [scrollView setDocumentView:textView];
    [scrollView setHasVerticalScroller:YES];
    
    [helpWindow setContentView:scrollView];
    
    [helpWindow makeKeyAndOrderFront:nil];
}

@end

static AppDelegate *sharedDelegate = nil;
static NSWindow *aboutWindow = nil;

extern "C" void openSDLWindowAboutMenu() {
    if (aboutWindow != nil) {
        [aboutWindow makeKeyAndOrderFront:nil];
        return;
    }

    NSRect frame = NSMakeRect(0, 0, 500, 400);
    aboutWindow = [[NSWindow alloc] initWithContentRect:frame
                                                styleMask:(NSWindowStyleMaskTitled | NSWindowStyleMaskClosable)
                                                  backing:NSBackingStoreBuffered
                                                    defer:NO];
    [aboutWindow center];
    [aboutWindow setTitle:@"AtaraxiaSDK"];

    NSTextView *textView = [[NSTextView alloc] initWithFrame:NSMakeRect(0, 0, 500, 400)];
    [textView setString:@"AtaraxiaSDK Build 0.1.\nWelcome to this SDK!"];
    [textView setEditable:NO];
    [textView setSelectable:YES];

    NSScrollView *scrollView = [[NSScrollView alloc] initWithFrame:frame];
    [scrollView setDocumentView:textView];
    [scrollView setHasVerticalScroller:YES];

    [aboutWindow setContentView:scrollView];
    [aboutWindow makeKeyAndOrderFront:nil];
}

extern "C" void cocoaBaseMenuBar() {
    NSApplication *app = [NSApplication sharedApplication];
    
    sharedDelegate = [[AppDelegate alloc] init];
    [app setDelegate:sharedDelegate];
    
    NSMenu *menuBar = [[NSMenu alloc] init];
    NSMenuItem *appMenuItem = [[NSMenuItem alloc] init];
    [menuBar addItem:appMenuItem];
    
    NSMenu *appMenu = [[NSMenu alloc] init];
    
    NSMenuItem *aboutMenuItem = [[NSMenuItem alloc] initWithTitle:@"About AtaraxiaSDK"
                                                           action:@selector(customAboutAction:)
                                                    keyEquivalent:@""];
    [aboutMenuItem setTarget:sharedDelegate];
    
    NSMenuItem *quitMenuItem = [[NSMenuItem alloc] initWithTitle:@"Quit"
                                                          action:@selector(terminate:)
                                                   keyEquivalent:@"q"];
    
    [appMenu addItem:aboutMenuItem];
    [appMenu addItem:quitMenuItem];
    [appMenuItem setSubmenu:appMenu];
    
    NSMenu *fileMenu = [[NSMenu alloc] initWithTitle:@"File"];
    
    NSMenuItem *blankOption = [[NSMenuItem alloc] initWithTitle:@"<operand 1>"
                                                         action:@selector(blankOptionAction:)
                                                  keyEquivalent:@""];
    [blankOption setTarget:sharedDelegate];
    [fileMenu addItem:blankOption];

    NSMenuItem *blankOption2 = [[NSMenuItem alloc] initWithTitle:@"<operand 2>"
                                                         action:@selector(blankOption2Action:)
                                                  keyEquivalent:@""];
    [blankOption2 setTarget:sharedDelegate];
    [fileMenu addItem:blankOption2];

    NSMenuItem *blankOption3 = [[NSMenuItem alloc] initWithTitle:@"<operand 3>"
                                                         action:@selector(blankOption3Action:)
                                                  keyEquivalent:@""];
    [blankOption3 setTarget:sharedDelegate];
    [fileMenu addItem:blankOption3];

    NSMenuItem *blankOption4 = [[NSMenuItem alloc] initWithTitle:@"<operand 4>"
                                                         action:@selector(blankOption4Action:)
                                                  keyEquivalent:@""];
    [blankOption4 setTarget:sharedDelegate];
    [fileMenu addItem:blankOption4];

    NSMenuItem *blankOption5 = [[NSMenuItem alloc] initWithTitle:@"<operand 5>"
                                                         action:@selector(blankOption5Action:)
                                                  keyEquivalent:@""];
    [blankOption5 setTarget:sharedDelegate];
    [fileMenu addItem:blankOption5];
    
    NSMenuItem *fileMenuItem = [[NSMenuItem alloc] initWithTitle:@"File"
                                                         action:nil
                                                  keyEquivalent:@""];
    [fileMenuItem setSubmenu:fileMenu];
    [menuBar addItem:fileMenuItem];

    NSMenu *editMenu = [[NSMenu alloc] initWithTitle:@"Edit"];
    
    NSMenuItem *editOption1 = [[NSMenuItem alloc] initWithTitle:@"<operand 1>"
                                                         action:@selector(blankOptionAction:)
                                                  keyEquivalent:@""];
    [editOption1 setTarget:sharedDelegate]; 
    [editMenu addItem:editOption1];
    
    NSMenuItem *editOption2 = [[NSMenuItem alloc] initWithTitle:@"<operand 2>"
                                                         action:@selector(blankOption2Action:)
                                                  keyEquivalent:@""];
    [editOption2 setTarget:sharedDelegate];
    [editMenu addItem:editOption2];

    NSMenuItem *editOption3 = [[NSMenuItem alloc] initWithTitle:@"<operand 3>"
                                                         action:@selector(blankOption3Action:)
                                                  keyEquivalent:@""];
    [editOption3 setTarget:sharedDelegate];
    [editMenu addItem:editOption3];

    NSMenuItem *editOption4 = [[NSMenuItem alloc] initWithTitle:@"<operand 4>"
                                                         action:@selector(blankOption4Action:)
                                                  keyEquivalent:@""];
    [editOption4 setTarget:sharedDelegate];
    [editMenu addItem:editOption4];

    NSMenuItem *editOption5 = [[NSMenuItem alloc] initWithTitle:@"<operand 5>"
                                                         action:@selector(blankOption5Action:)
                                                  keyEquivalent:@""];
    [editOption5 setTarget:sharedDelegate];
    [editMenu addItem:editOption5];
    
    NSMenuItem *editMenuItem = [[NSMenuItem alloc] initWithTitle:@"Edit"
                                                          action:nil
                                                   keyEquivalent:@""];
    [editMenuItem setSubmenu:editMenu];
    [menuBar addItem:editMenuItem];
    
    NSMenu *windowMenu = [[NSMenu alloc] initWithTitle:@"Window"];
    
    NSMenuItem *windowOption1 = [[NSMenuItem alloc] initWithTitle:@"<operand 1>"
                                                         action:@selector(blankOptionAction:)
                                                  keyEquivalent:@""];
    [windowOption1 setTarget:sharedDelegate];
    [windowMenu addItem:windowOption1];
    
    NSMenuItem *windowOption2 = [[NSMenuItem alloc] initWithTitle:@"<operand 2>"
                                                         action:@selector(blankOption2Action:)
                                                  keyEquivalent:@""];
    [windowOption2 setTarget:sharedDelegate];
    [windowMenu addItem:windowOption2];

    NSMenuItem *windowOption3 = [[NSMenuItem alloc] initWithTitle:@"<operand 3>"
                                                         action:@selector(blankOption3Action:)
                                                  keyEquivalent:@""];
    [windowOption3 setTarget:sharedDelegate];
    [windowMenu addItem:windowOption3];

    NSMenuItem *windowOption4 = [[NSMenuItem alloc] initWithTitle:@"<operand 4>"
                                                         action:@selector(blankOption4Action:)
                                                  keyEquivalent:@""];
    [windowOption4 setTarget:sharedDelegate];
    [windowMenu addItem:windowOption4];

    NSMenuItem *windowOption5 = [[NSMenuItem alloc] initWithTitle:@"<operand 5>"
                                                         action:@selector(blankOption5Action:)
                                                  keyEquivalent:@""];
    [windowOption5 setTarget:sharedDelegate];
    [windowMenu addItem:windowOption5];
    
    NSMenuItem *windowMenuItem = [[NSMenuItem alloc] initWithTitle:@"Window"
                                                           action:nil
                                                    keyEquivalent:@""];
    [windowMenuItem setSubmenu:windowMenu];
    [menuBar addItem:windowMenuItem];

    NSMenu *helpMenu = [[NSMenu alloc] initWithTitle:@"Help"];
    
    NSMenuItem *helpOption1 = [[NSMenuItem alloc] initWithTitle:@"Help Window 1"
                                                         action:@selector(helpOption1Action:)
                                                  keyEquivalent:@""];
    [helpOption1 setTarget:sharedDelegate];
    [helpMenu addItem:helpOption1];
    
    NSMenuItem *helpOption2 = [[NSMenuItem alloc] initWithTitle:@"Help Window 2"
                                                         action:@selector(helpOption2Action:)
                                                  keyEquivalent:@""];
    [helpOption2 setTarget:sharedDelegate];
    [helpMenu addItem:helpOption2];

    NSMenuItem *helpOption3 = [[NSMenuItem alloc] initWithTitle:@"Help Window 3"
                                                         action:@selector(helpOption3Action:)
                                                  keyEquivalent:@""];
    [helpOption3 setTarget:sharedDelegate];
    [helpMenu addItem:helpOption3];

    NSMenuItem *helpOption4 = [[NSMenuItem alloc] initWithTitle:@"Help Window 4"
                                                         action:@selector(helpOption4Action:) 
                                                  keyEquivalent:@""];
    [helpOption4 setTarget:sharedDelegate];
    [helpMenu addItem:helpOption4];

    NSMenuItem *helpOption5 = [[NSMenuItem alloc] initWithTitle:@"Help Window 5"
                                                         action:@selector(helpOption5Action:)
                                                  keyEquivalent:@""];
    [helpOption5 setTarget:sharedDelegate];
    [helpMenu addItem:helpOption5];
    
    NSMenuItem *helpMenuItem = [[NSMenuItem alloc] initWithTitle:@"Help"
                                                          action:nil
                                                   keyEquivalent:@""];
    [helpMenuItem setSubmenu:helpMenu];
    [menuBar addItem:helpMenuItem];

    [app setMainMenu:menuBar];
}
