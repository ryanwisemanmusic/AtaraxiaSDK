#import <Cocoa/Cocoa.h>

int main(int argc, const char* argv[])
{
    @autoreleasepool
    {
        NSApplication *app = [NSApplication sharedApplication];

        NSRect frame = NSMakeRect(100, 100, 400, 300);
        NSInteger style = NSWindowStyleMaskTitled | 
        NSWindowStyleMaskClosable | NSWindowStyleMaskResizable;
        NSWindow *window = [[NSWindow alloc] initWithContentRect:frame
        styleMask:style
        backing:NSBackingStoreBuffered
        defer:NO];

        [window setTitle:@"My Simple Window"];
        [window makeKeyAndOrderFront:nil];

        [app run];
    }
    return 0;
}