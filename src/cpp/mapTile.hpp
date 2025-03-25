#ifndef MAPTILE
#define MAPTILE

#include "AtaraxiaMain.hpp"
#include "entity.hpp"
//48x48 map tile map support
namespace two_d_tiles {
    inline SDL_Texture* tile_texture;

    inline SDL_FRect create_sprite_portion(float x, float y, float w, float h)
    {
        SDL_FRect portion = {
            x, y, w, h
        };
        return portion;
    }

    inline SDL_FRect create_sprite_position(float x, float y, float w, float h)
    {
        SDL_FRect position = {
            x, y, w, h
        };
        return position;
    }
    //This will be used to create tiles within our sprite map
    //Yes, there will be quite a lot of them

    //Column 1
    inline SDL_FRect tile_sprite_portion = create_sprite_portion(0, 0, 48, 48);
    inline SDL_FRect tile_sprite_potion_02 = create_sprite_portion(0, 48, 48, 48);
    inline SDL_FRect tile_sprite_potion_03 = create_sprite_portion(0, 48*2, 48, 48);
    inline SDL_FRect tile_sprite_potion_04 = create_sprite_portion(0, 48*3, 48, 48);
    inline SDL_FRect tile_sprite_potion_05 = create_sprite_portion(0, 48*4, 48, 48);
    inline SDL_FRect tile_sprite_potion_06 = create_sprite_portion(0, 48*5, 48, 48);
    inline SDL_FRect tile_sprite_potion_07 = create_sprite_portion(0, 48*6, 48, 48);
    inline SDL_FRect tile_sprite_potion_08 = create_sprite_portion(0, 48*7, 48, 48);
    inline SDL_FRect tile_sprite_potion_09 = create_sprite_portion(0, 48*8, 48, 48);
    inline SDL_FRect tile_sprite_potion_10 = create_sprite_portion(0, 48*9, 48, 48);
    inline SDL_FRect tile_sprite_potion_11 = create_sprite_portion(0, 48*10, 48, 48);
    inline SDL_FRect tile_sprite_potion_12 = create_sprite_portion(0, 48*11, 48, 48);

    //Column 2
    inline SDL_FRect tile_sprite_potion_x = create_sprite_portion(48, 0, 48, 48);
    inline SDL_FRect tile_sprite_potion_02 = create_sprite_portion(48, 48, 48, 48);
    inline SDL_FRect tile_sprite_potion_03 = create_sprite_portion(48, 48*2, 48, 48);
    inline SDL_FRect tile_sprite_potion_04 = create_sprite_portion(48, 48*3, 48, 48);
    inline SDL_FRect tile_sprite_potion_05 = create_sprite_portion(48, 48*4, 48, 48);
    inline SDL_FRect tile_sprite_potion_06 = create_sprite_portion(48, 48*5, 48, 48);
    inline SDL_FRect tile_sprite_potion_07 = create_sprite_portion(48, 48*6, 48, 48);
    inline SDL_FRect tile_sprite_potion_08 = create_sprite_portion(48, 48*7, 48, 48);
    inline SDL_FRect tile_sprite_potion_09 = create_sprite_portion(48, 48*8, 48, 48);
    inline SDL_FRect tile_sprite_potion_10 = create_sprite_portion(48, 48*9, 48, 48);
    inline SDL_FRect tile_sprite_potion_11 = create_sprite_portion(48, 48*10, 48, 48);
    inline SDL_FRect tile_sprite_potion_12 = create_sprite_portion(48, 48*11, 48, 48);

    //Column 3
    inline SDL_FRect tile_sprite_potion_x = create_sprite_portion(48*2, 0, 48, 48);
    inline SDL_FRect tile_sprite_potion_02 = create_sprite_portion(48*2, 48, 48, 48);
    inline SDL_FRect tile_sprite_potion_03 = create_sprite_portion(48*2, 48*2, 48, 48);
    inline SDL_FRect tile_sprite_potion_04 = create_sprite_portion(48*2, 48*3, 48, 48);
    inline SDL_FRect tile_sprite_potion_05 = create_sprite_portion(48*2, 48*4, 48, 48);
    inline SDL_FRect tile_sprite_potion_06 = create_sprite_portion(48*2, 48*5, 48, 48);
    inline SDL_FRect tile_sprite_potion_07 = create_sprite_portion(48*2, 48*6, 48, 48);
    inline SDL_FRect tile_sprite_potion_08 = create_sprite_portion(48*2, 48*7, 48, 48);
    inline SDL_FRect tile_sprite_potion_09 = create_sprite_portion(48*2, 48*8, 48, 48);
    inline SDL_FRect tile_sprite_potion_10 = create_sprite_portion(48*2, 48*9, 48, 48);
    inline SDL_FRect tile_sprite_potion_11 = create_sprite_portion(48*2, 48*10, 48, 48);
    inline SDL_FRect tile_sprite_potion_12 = create_sprite_portion(48*2, 48*11, 48, 48);

    //Column 4
    inline SDL_FRect tile_sprite_potion_x = create_sprite_portion(48*3, 0, 48, 48);
    inline SDL_FRect tile_sprite_potion_02 = create_sprite_portion(48*3, 48, 48, 48);
    inline SDL_FRect tile_sprite_potion_03 = create_sprite_portion(48*3, 48*2, 48, 48);
    inline SDL_FRect tile_sprite_potion_04 = create_sprite_portion(48*3, 48*3, 48, 48);
    inline SDL_FRect tile_sprite_potion_05 = create_sprite_portion(48*3, 48*4, 48, 48);
    inline SDL_FRect tile_sprite_potion_06 = create_sprite_portion(48*3, 48*5, 48, 48);
    inline SDL_FRect tile_sprite_potion_07 = create_sprite_portion(48*3, 48*6, 48, 48);
    inline SDL_FRect tile_sprite_potion_08 = create_sprite_portion(48*3, 48*7, 48, 48);
    inline SDL_FRect tile_sprite_potion_09 = create_sprite_portion(48*3, 48*8, 48, 48);
    inline SDL_FRect tile_sprite_potion_10 = create_sprite_portion(48*3, 48*9, 48, 48);
    inline SDL_FRect tile_sprite_potion_11 = create_sprite_portion(48*3, 48*10, 48, 48);
    inline SDL_FRect tile_sprite_potion_12 = create_sprite_portion(48*3, 48*11, 48, 48);
    
    //Column 5
    inline SDL_FRect tile_sprite_potion_x = create_sprite_portion(48*4, 0, 48, 48);
    inline SDL_FRect tile_sprite_potion_02 = create_sprite_portion(48*4, 48, 48, 48);
    inline SDL_FRect tile_sprite_potion_03 = create_sprite_portion(48*4, 48*2, 48, 48);
    inline SDL_FRect tile_sprite_potion_04 = create_sprite_portion(48*4, 48*3, 48, 48);
    inline SDL_FRect tile_sprite_potion_05 = create_sprite_portion(48*4, 48*4, 48, 48);
    inline SDL_FRect tile_sprite_potion_06 = create_sprite_portion(48*4, 48*5, 48, 48);
    inline SDL_FRect tile_sprite_potion_07 = create_sprite_portion(48*4, 48*6, 48, 48);
    inline SDL_FRect tile_sprite_potion_08 = create_sprite_portion(48*4, 48*7, 48, 48);
    inline SDL_FRect tile_sprite_potion_09 = create_sprite_portion(48*4, 48*8, 48, 48);
    inline SDL_FRect tile_sprite_potion_10 = create_sprite_portion(48*4, 48*9, 48, 48);
    inline SDL_FRect tile_sprite_potion_11 = create_sprite_portion(48*4, 48*10, 48, 48);
    inline SDL_FRect tile_sprite_potion_12 = create_sprite_portion(48*4, 48*11, 48, 48);

    //Column 6
    inline SDL_FRect tile_sprite_potion_x = create_sprite_portion(48*5, 0, 48, 48);
    inline SDL_FRect tile_sprite_potion_02 = create_sprite_portion(48*5, 48, 48, 48);
    inline SDL_FRect tile_sprite_potion_03 = create_sprite_portion(48*5, 48*2, 48, 48);
    inline SDL_FRect tile_sprite_potion_04 = create_sprite_portion(48*5, 48*3, 48, 48);
    inline SDL_FRect tile_sprite_potion_05 = create_sprite_portion(48*5, 48*4, 48, 48);
    inline SDL_FRect tile_sprite_potion_06 = create_sprite_portion(48*5, 48*5, 48, 48);
    inline SDL_FRect tile_sprite_potion_07 = create_sprite_portion(48*5, 48*6, 48, 48);
    inline SDL_FRect tile_sprite_potion_08 = create_sprite_portion(48*5, 48*7, 48, 48);
    inline SDL_FRect tile_sprite_potion_09 = create_sprite_portion(48*5, 48*8, 48, 48);
    inline SDL_FRect tile_sprite_potion_10 = create_sprite_portion(48*5, 48*9, 48, 48);
    inline SDL_FRect tile_sprite_potion_11 = create_sprite_portion(48*5, 48*10, 48, 48);
    inline SDL_FRect tile_sprite_potion_12 = create_sprite_portion(48*5, 48*11, 48, 48);
    //Column 7
    //Column 8
    //Column 9
    //Column 10
    //Column 11
    //Column 12
    //Column 13
    //Column 14
    //Column 15
    //Column 16


    inline SDL_FRect tile_sprite_position = create_sprite_position(250, 250, 48, 48);

    void loadTileTexture();
    void quit();
    void handle_events(SDL_Event* event);
    void update();
    void render(SDL_Renderer* renderer);
    void init_tile();
}

#endif