/*
This is the obj-c part that handles windowing. We use it as the main
to our application, since everything else can be defined in its own
function. 
*/

#import <Cocoa/Cocoa.h>
#import "AppDelegate.h"
#import "WindowDelegate.h"
#import "MouseDelegate.h"
#import "colorFill.h"
#import "screen_management.h" // Import screen management to access ScreenManager
#import "LogDelegate.h"       // Import LogDelegate to initialize the log viewer

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // Create the Cocoa application
        NSLog(@"Application starting...");

        // Create the shared application instance
        NSApplication *app = [NSApplication sharedApplication];
        
        // Set the AppDelegate to handle application-wide events (like quitting the app)
        AppDelegate *appDelegate = [[AppDelegate alloc] init];
        [app setDelegate:appDelegate];

        // Create the main window
        NSWindow *window = [[NSWindow alloc] initWithContentRect:NSMakeRect(0, 0, 800, 600)
                                                      styleMask:(NSWindowStyleMaskTitled | NSWindowStyleMaskClosable)
                                                        backing:NSBackingStoreBuffered
                                                          defer:NO];
        [window setTitle:@"Ataraxia App"];
        NSLog(@"Window created: %@", window);

        // Create and set the window delegate to handle window-specific events
        WindowDelegate *windowDelegate = [[WindowDelegate alloc] initWithWindow:window];
        [window setDelegate:windowDelegate];
        NSLog(@"Window delegate set: %@", windowDelegate);

        // Set the initial background color of the window
        [window setBackgroundColor:[NSColor redColor]];

        // Ensure the content view exists
        NSView *contentView = [window contentView];
        if (!contentView) {
            NSLog(@"Error: contentView is nil!");
        } else {
            NSLog(@"Content view successfully retrieved: %@", contentView);
            [contentView setWantsLayer:YES]; // Ensure layer-backed view
            if (contentView.layer) {
                contentView.layer.backgroundColor = [NSColor redColor].CGColor; // Set initial background color
                NSLog(@"Background color set on content view layer.");
            } else {
                NSLog(@"Error: No layer available for content view.");
            }
        }

        // Initialize LogDelegate to ensure the log viewer window is created
        @try {
            [LogDelegate sharedInstance]; // Ensure this doesn't disrupt execution
            NSLog(@"Log viewer initialized successfully.");
        } @catch (NSException *exception) {
            NSLog(@"Error initializing LogDelegate: %@", exception);
        }

        // Show the log window explicitly after initializing LogDelegate
        [[LogDelegate sharedInstance] showLogWindow];

        // Monitor for mouse clicks and spacebar key press globally
        [NSEvent addGlobalMonitorForEventsMatchingMask:(NSEventMaskLeftMouseDown | NSEventMaskKeyDown) handler:^(NSEvent *event) {
            if (event.type == NSEventTypeLeftMouseDown) {
                // Handle mouse click event
                NSLog(@"Mouse click event detected at: %@", NSStringFromPoint(event.locationInWindow));
            } else if (event.type == NSEventTypeKeyDown && [event keyCode] == 49) { // 49 is the keycode for the spacebar
                // Handle spacebar press event
                NSLog(@"Spacebar pressed.");
                // You can add your action logic for spacebar here (e.g., trigger sound, toggle action, etc.)
            }
        }];
        NSLog(@"Global mouse and spacebar event monitoring initialized.");

        // Ensure the window is focused and ready to accept input
        [window makeKeyAndOrderFront:nil]; // Bring the window to the front
        [window setAcceptsMouseMovedEvents:YES]; // Accept mouse move events (optional for your needs)
        NSLog(@"Window is focused and ready to accept key and mouse events.");

        // Test ScreenManager independently to verify screen transition logic
        @try {
            [ScreenManager handleScreenTransition:window withWindowDelegate:windowDelegate];
            NSLog(@"Screen transition logic executed successfully.");
        } @catch (NSException *exception) {
            NSLog(@"Error during screen transition logic: %@", exception);
        }

        // Start the application event loop
        @try {
            [app run];
        } @catch (NSException *exception) {
            NSLog(@"Application encountered an error in the event loop: %@", exception);
        }

        NSLog(@"Application has exited.");
    }
    return 0; // Return 0 when the app exits
}







