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
        
        // Set the initial background color
        [window setBackgroundColor:[NSColor redColor]]; 
        
        // My custom red has some issues with being recognized,
        [window setBackgroundColor:[NSColor redColor]]; 
        
        // We are verifying the window and mouse events here
        NSView *contentView = [window contentView];
        contentView.allowedTouchTypes = NSTouchTypeMaskDirect; // Enable direct touch
        [contentView setWantsLayer:YES]; // Ensure the content view is layer-backed
        NSLog(@"Content view setup complete with mouse events enabled.");

        // Add the mouse event listener
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

