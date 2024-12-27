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
#import "screen_management.h"
#import "LogDelegate.h"
#import "FileConverterDelegate.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        NSLog(@"--- Application Startup ---");

        // Step 1: Create the shared application instance
        NSLog(@"Initializing NSApplication...");
        NSApplication *app = [NSApplication sharedApplication];

        // Step 2: Set up AppDelegate
        NSLog(@"Setting up AppDelegate...");
        AppDelegate *appDelegate = [[AppDelegate alloc] init];
        if (!appDelegate) {
            NSLog(@"Error: Failed to initialize AppDelegate.");
            return 1; // Exit with error code
        }
        [app setDelegate:appDelegate];
        NSLog(@"AppDelegate set successfully.");

        // Step 3: Create and configure the main window
        NSLog(@"Creating main window...");
        NSWindow *window = [[NSWindow alloc] initWithContentRect:NSMakeRect(0, 0, 800, 600)
                                                      styleMask:(NSWindowStyleMaskTitled | NSWindowStyleMaskClosable)
                                                        backing:NSBackingStoreBuffered
                                                          defer:NO];
        if (!window) {
            NSLog(@"Error: Failed to create main window.");
            return 1;
        }
        [window setTitle:@"Ataraxia App"];
        NSLog(@"Main window created: %@", window);

        // Step 4: Set up WindowDelegate
        NSLog(@"Setting up WindowDelegate...");
        WindowDelegate *windowDelegate = [[WindowDelegate alloc] initWithWindow:window];
        if (!windowDelegate) {
            NSLog(@"Error: Failed to initialize WindowDelegate.");
            return 1;
        }
        [window setDelegate:windowDelegate];
        NSLog(@"WindowDelegate set successfully: %@", windowDelegate);

        // Step 5: Set the initial background color of the window
        [window setBackgroundColor:[NSColor redColor]];
        NSLog(@"Main window background color set to red.");

        // Step 6: Initialize LogDelegate and show the log window
        NSLog(@"Initializing LogDelegate...");
        @try {
            LogDelegate *logDelegate = [LogDelegate sharedInstance];
            [logDelegate showLogWindow];
            NSLog(@"Log window shown successfully.");
        } @catch (NSException *exception) {
            NSLog(@"Error initializing LogDelegate: %@", exception);
        }

        // Step 7: Initialize FileConverterDelegate and trigger the window for testing
        NSLog(@"Initializing FileConverterDelegate...");
        @try {
            FileConverterDelegate *fileConverterDelegate = [FileConverterDelegate sharedInstance];
            NSLog(@"FileConverterDelegate initialized successfully.");

            // Optional: Show the File Converter window at startup for testing
            [fileConverterDelegate showFileConverterWindow];
        } @catch (NSException *exception) {
            NSLog(@"Error initializing FileConverterDelegate: %@", exception);
        }

        // Step 8: Add global monitoring for mouse and keyboard events
        NSLog(@"Setting up global mouse and keyboard event monitoring...");
        [NSEvent addGlobalMonitorForEventsMatchingMask:(NSEventMaskLeftMouseDown | NSEventMaskKeyDown) handler:^(NSEvent *event) {
            if (event.type == NSEventTypeLeftMouseDown) {
                NSLog(@"Mouse click detected at: %@", NSStringFromPoint(event.locationInWindow));
            } else if (event.type == NSEventTypeKeyDown && [event keyCode] == 49) { // 49 = Spacebar
                NSLog(@"Spacebar pressed.");
            }
        }];

        // Step 9: Show and prepare the main window
        [window makeKeyAndOrderFront:nil];
        [window setAcceptsMouseMovedEvents:YES];
        NSLog(@"Main window is ready and accepting events.");

        // Step 10: Execute screen transition logic
        NSLog(@"Executing screen transition logic...");
        @try {
            [ScreenManager handleScreenTransition:window withWindowDelegate:windowDelegate];
            NSLog(@"Screen transition logic executed successfully.");
        } @catch (NSException *exception) {
            NSLog(@"Error during screen transition: %@", exception);
        }

        // Step 11: Start the application event loop
        NSLog(@"Starting application event loop...");
        @try {
            [app run];
        } @catch (NSException *exception) {
            NSLog(@"Error in application event loop: %@", exception);
        }

        NSLog(@"Application has exited.");
    }

    return 0; // Exit code for success
}


