#include "AtaraxiaMain.hpp"
#define SDL_MAIN_USE_CALLBACKS
#include "mapTile.hpp"

namespace two_d_tiles {
    void loadTileTexture()
    {
        const char path[] = "assets/images/outsideTileMap.png";
        tile_texture = IMG_LoadTexture(renderer, path);
        SDL_SetTextureScaleMode(tile_texture, SDL_SCALEMODE_NEAREST);

        if (!tile_texture) 
        {
            SDL_Log("Tile texture could not be loaded! SDL error: %s\n", 
                SDL_GetError());
            SDL_Quit();
        }
        else
        {
            SDL_Log("Tile texture loaded successfully");
        }
    }

    void quit()
    {
        if (tile_texture) {
            SDL_DestroyTexture(tile_texture);
            tile_texture = nullptr;
        }
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
        SDL_RenderTexture(
            renderer, tile_texture, 
            &tile_sprite_portion, &tile_sprite_position);
    }

    void init_tile()
    {
        loadTileTexture(); 
        
        Entity tile_entity = {
            .quit = quit,
            .handle_events = handle_events,
            .update = update,
            .render = render
        };
        
        entities_tile[entities_count_tile++] = tile_entity;
    }
}