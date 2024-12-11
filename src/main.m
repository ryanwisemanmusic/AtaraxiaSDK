#import "basicWindow.h"

int main (int argc, const char *argv[])
{
    @autoreleasepool 
    {
        NSApplication *app = ataraxiaApplication();

        NSRect frame = NSMakeRect(300, 300, 600, 300);
        NSInteger style = NSWindowStyleMaskTitled |
        NSWindowStyleMaskClosable | NSWindowStyleMaskResizable;

        NSString *title = @"AtaraxiaSDK";

        NSWindow *window = createWindow(frame, style, title);
        runApplication(app, window);
    }
    return 0;
}