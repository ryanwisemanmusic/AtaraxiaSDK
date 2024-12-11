#include "windowCWrapper.h"

void setupWindow() {
    void *app = ataraxiaApplication();

    CGRect frame = CGRectMake(0, 0, 800, 600);
    int32_t style = WINDOW_STYLE_TITLED;
    const char *title = "Ataraxia App";

    void *window = createWindow(frame, style, title);
    runApplication(app, window);
}