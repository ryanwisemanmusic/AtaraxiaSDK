One of the key ways that this SDK handles a lot of the boilerplate is
by having a series of defined functions to make your life easier. While you can
certainly peel back the hood and add your own stuff, which is recommended,
here are some key terminology you must use when working with a main
void render function:

For scenes, this is how you reference them:
if (currentScene == SceneState::name_of_scene) {}


When you set your scene, it is important you clear whatever existed before
in the render. This is just a good habit to make, and it's incredibly simple
on how to free up the memory you need for this new scene:
SDL_RenderClear(renderer); 


If you want to draw a simple color to the screen, we use:
SDL_SetRenderDrawColor(renderer, 155, 255, 255, 255);


SDL_TTF is a foundational aspect to this codebase, and I've already handled
how to render the text itself. At the moment, this text only renders off of
one particular font file. Here is how we go about rendering text with said
font:
renderText("AtaraxiaSDK", 180, 250, cMagenta); 
