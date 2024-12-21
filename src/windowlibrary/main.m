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
        
        // Verify the window delegate is set
        NSLog(@"Window delegate set: %@", delegate);

        // Set the initial background color of the window
        [window setBackgroundColor:[NSColor redColor]]; 
        
        // Get the content view and check if it's not nil
        NSView *contentView = [window contentView];
        if (!contentView) {
            NSLog(@"Error: contentView is nil!");
        } else {
            NSLog(@"Content view successfully retrieved: %@", contentView);
            // Ensure content view is layer-backed
            [contentView setWantsLayer:YES];

            // Check if the layer is properly created
            if (contentView.layer) {
                NSLog(@"Layer exists for content view.");
                contentView.layer.backgroundColor = [NSColor redColor].CGColor; // Set background color using CALayer
                NSLog(@"Background color set on content view layer.");
            } else {
                NSLog(@"Error: No layer for content view.");
            }
        }

        // Add mouse event listener for debugging purposes
        [NSEvent addLocalMonitorForEventsMatchingMask:NSEventMaskLeftMouseDown handler:^NSEvent *(NSEvent *event) {
            NSLog(@"Mouse event detected at: %@", NSStringFromPoint(event.locationInWindow));
            return event; // Return the event to propagate it
        }];

        // Call screen transition logic by passing window and window delegate
        [ScreenManager handleScreenTransition:window withWindowDelegate:delegate];

        // Show the window and start the application
        [window makeKeyAndOrderFront:nil];

        NSLog(@"Running the application");

        // Start the application event loop
        [app run];

        NSLog(@"Application has exited.");
    }
    return 0; // Return 0 when the app exits
}



