/*
This is the obj-c part that handles windowing. We use it as the main
to our application, since everything else can be defined in its own
function. 
*/

#import <Cocoa/Cocoa.h>
#import "WindowDelegate.h"
#import "MouseDelegate.h"
#import "colorFill.h"
#import "screen_management.h" // Import screen management to access ScreenManager
#import "LogDelegate.h"       // Import LogDelegate to initialize the log viewer

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // Create the Cocoa application
        NSLog(@"Application starting...");

        NSApplication *app = [NSApplication sharedApplication];
        
        // Create the main window
        NSWindow *window = [[NSWindow alloc] initWithContentRect:NSMakeRect(0, 0, 800, 600)
                                                      styleMask:(NSWindowStyleMaskTitled | NSWindowStyleMaskClosable)
                                                        backing:NSBackingStoreBuffered
                                                          defer:NO];
        [window setTitle:@"Ataraxia App"];
        NSLog(@"Window created: %@", window);

        // Create and set the window delegate
        WindowDelegate *delegate = [[WindowDelegate alloc] initWithWindow:window];
        [window setDelegate:delegate];
        NSLog(@"Window delegate set: %@", delegate);

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

        // Add mouse event listener for debugging purposes
        [NSEvent addLocalMonitorForEventsMatchingMask:NSEventMaskLeftMouseDown handler:^NSEvent *(NSEvent *event) {
            NSLog(@"Mouse event detected at: %@", NSStringFromPoint(event.locationInWindow));
            return event; // Propagate event
        }];
        NSLog(@"Mouse event monitor added.");

        // Safely call screen transition logic
        @try {
            [ScreenManager handleScreenTransition:window withWindowDelegate:delegate];
            NSLog(@"Screen transition logic executed successfully.");
        } @catch (NSException *exception) {
            NSLog(@"Error during screen transition logic: %@", exception);
        }

        // Show the main application window
        [window makeKeyAndOrderFront:nil];
        NSLog(@"Main application window is visible.");

        // Start the application event loop
        NSLog(@"Starting application event loop...");
        @try {
            [app run];
        } @catch (NSException *exception) {
            NSLog(@"Application encountered an error in the event loop: %@", exception);
        }

        NSLog(@"Application has exited.");
    }
    return 0; // Return 0 when the app exits
}





