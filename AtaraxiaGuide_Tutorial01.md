To understand this project, we will be going through some of the 
foundational aspects to how this entire SDK works. Through using 
Cocoa, Mac's native graphic library, we are able to generate 
graphics without the hassle of installing through homebrew, which
is rather depricated in terms of fucking up dynamic link libraries.

To understand how my code works, we will be going through aspects of
the SDK. 

In our src folder we have a main folder called src. Inside, we have 
two folders, a translationlayer and a windowlibrary. This code is
written in Obj-C, and my reasoning for it is that Obj-C handles a lot
of the backend anyways. Too often, people want C to be a main driving
force for their projects, and while this may be great, most backends
to the existing SDK are in Lua or some sort of bridge between C
anyways.

In our folder called ataraxia_app_c, this is where our C code will
live. For now, I'm focusing on developing the code to work with C.
Modern C++, especially when you are building upon an existing native
framework, can be abstraction hell compared to what you do with C.

As my project scope needs to be limited to just a single language,
it is time to look at how this code works.

