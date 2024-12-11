#import "basicWindow.h"

int main (int argc, const char *argv[])
{
    @autoreleasepool 
    {
        NSApplication *app = ataraxiaApplication();

        NSRect frame = NSMakeRect(100, 100, 400, 300);
        NSInteger style = NSWindowStyleMaskTitled |
        NSWindowStyleMaskClosable | NSWindowStyleMaskResizable;

        NSString *title = @"AtaraxiaSDK";

        NSWindow *window = createWindow(frame, style, title);
        runApplication(app, window);
    }
    return 0;
}