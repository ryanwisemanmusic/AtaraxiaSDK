#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

enum class SceneState
{
    MAIN_MENU,
    GAME,
    NETWORK_TEST,
    COMPRESSOR,
    END_SCREEN
};

void handleMainMenu(SDL_Renderer* renderer, SceneState& currentScene);
void handleGame(SDL_Renderer* renderer, SceneState& currentScene);
void handleEndScreen(SDL_Renderer* renderer, SceneState& currentScene);