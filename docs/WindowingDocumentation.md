Because SDL3 has significantly shifted, here are some important notes:

SDL_RENDERER_ACCELERATED is a long depricated function that is very common
in SDL2. It usually doesn't flag you with an alternative.

Previously, when generating a window in SDL2, we would use:
window = SDL_CreateWindow(
        "AtaraxiaSDK", ScreenWidth,
        ScreenHeight, SDL_RENDERER_ACCELERATED);

Even if you do: #define SDL_RENDERER_ACCELERATED 0x00000002
    you may not get this macro to work with your project based on whether or not
    SDL3 is still allocating memory in Assembly for this definition. There are
    successful attempts in using it, I was completely unsuccessful when doing so

When we are generating a window, we must do this:
SDL_Init(SDL_INIT_VIDEO);

window = SDL_CreateWindow(
        "AtaraxiaSDK", ScreenWidth,
        ScreenHeight, SDL_WINDOW_OPENGL);

It is not a bad idea to error check this with an if (!init), but we want to ensure
that we initialize in the function, error check into main, instead of error checking in the
bool function prior to calling main.

This is an example of a bad approach for bool init:
SDL_Init(SDL_INIT_VIDEO);
if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("SDL_Init failed: %s\n", SDL_GetError());
        return false;
    }
    SDL_Log("SDL_Init succeeded.");

It is often a really shitty idea to check if it isn't 0 in this context,
because you can't peel back the layer of what SDL_Init(SDL_Init_Video) to see
what you've set this value to. Mostly this becomes a problem when you've allowed
the video and window to be set to null, because that will be interpreted as not a 0
automatically, hence borking your code.
