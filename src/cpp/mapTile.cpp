#include "AtaraxiaMain.hpp"
#define SDL_MAIN_USE_CALLBACKS
#include "mapTile.hpp"

namespace two_d_tiles {
    void loadTileTexture()
    {

        SDL_SetTextureScaleMode(tile_texture, SDL_SCALEMODE_NEAREST);

    }

    void quit()
    {

    }

    void handle_events(SDL_Event* event)
    {
    }

    void update()
    {

    }

    void render(SDL_Renderer* renderer)
    {
        SDL_SetTextureScaleMode(tile_texture, SDL_SCALEMODE_NEAREST);
    }

    void init_tile()
    {
        
        Entity tile_entity = {
            .quit = quit,
            .handle_events = handle_events,
            .update = update,
            .render = render
        };
        
        entities_tile[entities_count_tile++] = tile_entity;
    }
}