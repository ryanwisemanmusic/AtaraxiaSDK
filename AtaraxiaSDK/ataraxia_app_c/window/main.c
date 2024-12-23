/*This is the foundation for the main window that is needed.

We will only use this section to handle main window sizing. This is
NOT a place to put additonal functions unless it relates to a performable
action on this window.

Resizing functions, anything that relates to the status of the main
window and not internals of said window, these functions are fine.

If you mess with this, the problem is on you
*/

#ifdef __OBJC__
#import "windowCWrapper.h"
#import "colorFill.h"
#else
#include "windowCWrapper.h"
#include "colorFill.h"
#endif

void titleCommands()
{
    
}
