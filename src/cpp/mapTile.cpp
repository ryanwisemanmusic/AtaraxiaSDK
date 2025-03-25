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
        
        if (SDL_FRect* sprite = tile_map.getTileSprite(1, 5)) 
        {
            if (SDL_FRect* pos = tile_map.getTilePosition(3, 4)) 
            {
                SDL_RenderTexture(renderer, tile_texture, sprite, pos);
            }
        }
    }

    void init_tile()
    {
        loadTileTexture();
        
        for (int col = 0; col < 16; col++) { 
            for (int row = 0; row < 12; row++) {
                tile_map.setTilePosition(col, row, col * 48, row * 48);
            }
        }
        
        Entity tile_entity = {
            .quit = quit,
            .handle_events = handle_events,
            .update = update,
            .render = render
        };
        
        entities_tile[entities_count_tile++] = tile_entity;
    }
}