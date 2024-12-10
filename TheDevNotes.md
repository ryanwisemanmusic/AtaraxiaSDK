The process of working with any type of windowing on Apple silicone
is an exhausting one. With dynamic link libraries being a bigger
hassle than not when you work with libraries like VulkanSDK, SDL,
or raylib, there needs to be a better approach to generating 
graphics.

This was my solution to handling the problem of modern Macs needing
a translation layer. Silicone macs are awful at dynamically linking,
and to make matters worse, they require a translation layer that gets
more and more difficult to handle.

Through just a simple Obj-C file, it is easy to compile a window 
through using Cocoa. Through this project, I aim to handle graphics
in a Mac friendly manner.

Windows is not a priority for a project like this, as there requires
a level of translation I am not skilled enough in tackling. 

Since windowing on Mac is an after thought and very much neglected,
I decided to make this a personal project of mine. Succesfully, this
program runs a window, we just have nothing to store inside.