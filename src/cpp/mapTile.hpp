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
    inline SDL_FRect tile_sprite_potion_13 = create_sprite_portion(48, 0, 48, 48);
    inline SDL_FRect tile_sprite_potion_14 = create_sprite_portion(48, 48, 48, 48);
    inline SDL_FRect tile_sprite_potion_15 = create_sprite_portion(48, 48*2, 48, 48);
    inline SDL_FRect tile_sprite_potion_16 = create_sprite_portion(48, 48*3, 48, 48);
    inline SDL_FRect tile_sprite_potion_17 = create_sprite_portion(48, 48*4, 48, 48);
    inline SDL_FRect tile_sprite_potion_18 = create_sprite_portion(48, 48*5, 48, 48);
    inline SDL_FRect tile_sprite_potion_19 = create_sprite_portion(48, 48*6, 48, 48);
    inline SDL_FRect tile_sprite_potion_20 = create_sprite_portion(48, 48*7, 48, 48);
    inline SDL_FRect tile_sprite_potion_21 = create_sprite_portion(48, 48*8, 48, 48);
    inline SDL_FRect tile_sprite_potion_22 = create_sprite_portion(48, 48*9, 48, 48);
    inline SDL_FRect tile_sprite_potion_23 = create_sprite_portion(48, 48*10, 48, 48);
    inline SDL_FRect tile_sprite_potion_24 = create_sprite_portion(48, 48*11, 48, 48);

    //Column 3
    inline SDL_FRect tile_sprite_potion_25 = create_sprite_portion(48*2, 0, 48, 48);
    inline SDL_FRect tile_sprite_potion_26 = create_sprite_portion(48*2, 48, 48, 48);
    inline SDL_FRect tile_sprite_potion_27 = create_sprite_portion(48*2, 48*2, 48, 48);
    inline SDL_FRect tile_sprite_potion_28 = create_sprite_portion(48*2, 48*3, 48, 48);
    inline SDL_FRect tile_sprite_potion_29 = create_sprite_portion(48*2, 48*4, 48, 48);
    inline SDL_FRect tile_sprite_potion_30 = create_sprite_portion(48*2, 48*5, 48, 48);
    inline SDL_FRect tile_sprite_potion_31 = create_sprite_portion(48*2, 48*6, 48, 48);
    inline SDL_FRect tile_sprite_potion_32 = create_sprite_portion(48*2, 48*7, 48, 48);
    inline SDL_FRect tile_sprite_potion_33 = create_sprite_portion(48*2, 48*8, 48, 48);
    inline SDL_FRect tile_sprite_potion_34 = create_sprite_portion(48*2, 48*9, 48, 48);
    inline SDL_FRect tile_sprite_potion_35 = create_sprite_portion(48*2, 48*10, 48, 48);
    inline SDL_FRect tile_sprite_potion_36 = create_sprite_portion(48*2, 48*11, 48, 48);

    //Column 4
    inline SDL_FRect tile_sprite_potion_37 = create_sprite_portion(48*3, 0, 48, 48);
    inline SDL_FRect tile_sprite_potion_38 = create_sprite_portion(48*3, 48, 48, 48);
    inline SDL_FRect tile_sprite_potion_39 = create_sprite_portion(48*3, 48*2, 48, 48);
    inline SDL_FRect tile_sprite_potion_40 = create_sprite_portion(48*3, 48*3, 48, 48);
    inline SDL_FRect tile_sprite_potion_41 = create_sprite_portion(48*3, 48*4, 48, 48);
    inline SDL_FRect tile_sprite_potion_42 = create_sprite_portion(48*3, 48*5, 48, 48);
    inline SDL_FRect tile_sprite_potion_43 = create_sprite_portion(48*3, 48*6, 48, 48);
    inline SDL_FRect tile_sprite_potion_44 = create_sprite_portion(48*3, 48*7, 48, 48);
    inline SDL_FRect tile_sprite_potion_45 = create_sprite_portion(48*3, 48*8, 48, 48);
    inline SDL_FRect tile_sprite_potion_46 = create_sprite_portion(48*3, 48*9, 48, 48);
    inline SDL_FRect tile_sprite_potion_47 = create_sprite_portion(48*3, 48*10, 48, 48);
    inline SDL_FRect tile_sprite_potion_48 = create_sprite_portion(48*3, 48*11, 48, 48);
    
    //Column 5
    inline SDL_FRect tile_sprite_potion_49 = create_sprite_portion(48*4, 0, 48, 48);
    inline SDL_FRect tile_sprite_potion_50 = create_sprite_portion(48*4, 48, 48, 48);
    inline SDL_FRect tile_sprite_potion_51 = create_sprite_portion(48*4, 48*2, 48, 48);
    inline SDL_FRect tile_sprite_potion_52 = create_sprite_portion(48*4, 48*3, 48, 48);
    inline SDL_FRect tile_sprite_potion_53 = create_sprite_portion(48*4, 48*4, 48, 48);
    inline SDL_FRect tile_sprite_potion_54 = create_sprite_portion(48*4, 48*5, 48, 48);
    inline SDL_FRect tile_sprite_potion_55 = create_sprite_portion(48*4, 48*6, 48, 48);
    inline SDL_FRect tile_sprite_potion_56 = create_sprite_portion(48*4, 48*7, 48, 48);
    inline SDL_FRect tile_sprite_potion_57 = create_sprite_portion(48*4, 48*8, 48, 48);
    inline SDL_FRect tile_sprite_potion_58 = create_sprite_portion(48*4, 48*9, 48, 48);
    inline SDL_FRect tile_sprite_potion_59 = create_sprite_portion(48*4, 48*10, 48, 48);
    inline SDL_FRect tile_sprite_potion_60 = create_sprite_portion(48*4, 48*11, 48, 48);
    /*
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
    inline SDL_FRect tile_sprite_potion_x = create_sprite_portion(48*6, 0, 48, 48);
    inline SDL_FRect tile_sprite_potion_02 = create_sprite_portion(48*6, 48, 48, 48);
    inline SDL_FRect tile_sprite_potion_03 = create_sprite_portion(48*6, 48*2, 48, 48);
    inline SDL_FRect tile_sprite_potion_04 = create_sprite_portion(48*6, 48*3, 48, 48);
    inline SDL_FRect tile_sprite_potion_05 = create_sprite_portion(48*6, 48*4, 48, 48);
    inline SDL_FRect tile_sprite_potion_06 = create_sprite_portion(48*6, 48*5, 48, 48);
    inline SDL_FRect tile_sprite_potion_07 = create_sprite_portion(48*6, 48*6, 48, 48);
    inline SDL_FRect tile_sprite_potion_08 = create_sprite_portion(48*6, 48*7, 48, 48);
    inline SDL_FRect tile_sprite_potion_09 = create_sprite_portion(48*6, 48*8, 48, 48);
    inline SDL_FRect tile_sprite_potion_10 = create_sprite_portion(48*6, 48*9, 48, 48);
    inline SDL_FRect tile_sprite_potion_11 = create_sprite_portion(48*6, 48*10, 48, 48);
    inline SDL_FRect tile_sprite_potion_12 = create_sprite_portion(48*6, 48*11, 48, 48);
    
    //Column 8
    inline SDL_FRect tile_sprite_potion_x = create_sprite_portion(48*7, 0, 48, 48);
    inline SDL_FRect tile_sprite_potion_02 = create_sprite_portion(48*7, 48, 48, 48);
    inline SDL_FRect tile_sprite_potion_03 = create_sprite_portion(48*7, 48*2, 48, 48);
    inline SDL_FRect tile_sprite_potion_04 = create_sprite_portion(48*7, 48*3, 48, 48);
    inline SDL_FRect tile_sprite_potion_05 = create_sprite_portion(48*7, 48*4, 48, 48);
    inline SDL_FRect tile_sprite_potion_06 = create_sprite_portion(48*7, 48*5, 48, 48);
    inline SDL_FRect tile_sprite_potion_07 = create_sprite_portion(48*7, 48*6, 48, 48);
    inline SDL_FRect tile_sprite_potion_08 = create_sprite_portion(48*7, 48*7, 48, 48);
    inline SDL_FRect tile_sprite_potion_09 = create_sprite_portion(48*7, 48*8, 48, 48);
    inline SDL_FRect tile_sprite_potion_10 = create_sprite_portion(48*7, 48*9, 48, 48);
    inline SDL_FRect tile_sprite_potion_11 = create_sprite_portion(48*7, 48*10, 48, 48);
    inline SDL_FRect tile_sprite_potion_12 = create_sprite_portion(48*7, 48*11, 48, 48);

    //Column 9
    inline SDL_FRect tile_sprite_potion_x = create_sprite_portion(48*8, 0, 48, 48);
    inline SDL_FRect tile_sprite_potion_02 = create_sprite_portion(48*8, 48, 48, 48);
    inline SDL_FRect tile_sprite_potion_03 = create_sprite_portion(48*8, 48*2, 48, 48);
    inline SDL_FRect tile_sprite_potion_04 = create_sprite_portion(48*8, 48*3, 48, 48);
    inline SDL_FRect tile_sprite_potion_05 = create_sprite_portion(48*8, 48*4, 48, 48);
    inline SDL_FRect tile_sprite_potion_06 = create_sprite_portion(48*8, 48*5, 48, 48);
    inline SDL_FRect tile_sprite_potion_07 = create_sprite_portion(48*8, 48*6, 48, 48);
    inline SDL_FRect tile_sprite_potion_08 = create_sprite_portion(48*8, 48*7, 48, 48);
    inline SDL_FRect tile_sprite_potion_09 = create_sprite_portion(48*8, 48*8, 48, 48);
    inline SDL_FRect tile_sprite_potion_10 = create_sprite_portion(48*8, 48*9, 48, 48);
    inline SDL_FRect tile_sprite_potion_11 = create_sprite_portion(48*8, 48*10, 48, 48);
    inline SDL_FRect tile_sprite_potion_12 = create_sprite_portion(48*8, 48*11, 48, 48);

    //Column 10
    inline SDL_FRect tile_sprite_potion_x = create_sprite_portion(48*9, 0, 48, 48);
    inline SDL_FRect tile_sprite_potion_02 = create_sprite_portion(48*9, 48, 48, 48);
    inline SDL_FRect tile_sprite_potion_03 = create_sprite_portion(48*9, 48*2, 48, 48);
    inline SDL_FRect tile_sprite_potion_04 = create_sprite_portion(48*9, 48*3, 48, 48);
    inline SDL_FRect tile_sprite_potion_05 = create_sprite_portion(48*9, 48*4, 48, 48);
    inline SDL_FRect tile_sprite_potion_06 = create_sprite_portion(48*9, 48*5, 48, 48);
    inline SDL_FRect tile_sprite_potion_07 = create_sprite_portion(48*9, 48*6, 48, 48);
    inline SDL_FRect tile_sprite_potion_08 = create_sprite_portion(48*9, 48*7, 48, 48);
    inline SDL_FRect tile_sprite_potion_09 = create_sprite_portion(48*9, 48*8, 48, 48);
    inline SDL_FRect tile_sprite_potion_10 = create_sprite_portion(48*9, 48*9, 48, 48);
    inline SDL_FRect tile_sprite_potion_11 = create_sprite_portion(48*9, 48*10, 48, 48);
    inline SDL_FRect tile_sprite_potion_12 = create_sprite_portion(48*9, 48*11, 48, 48);

    //Column 11
    inline SDL_FRect tile_sprite_potion_x = create_sprite_portion(48*10, 0, 48, 48);
    inline SDL_FRect tile_sprite_potion_02 = create_sprite_portion(48*10, 48, 48, 48);
    inline SDL_FRect tile_sprite_potion_03 = create_sprite_portion(48*10, 48*2, 48, 48);
    inline SDL_FRect tile_sprite_potion_04 = create_sprite_portion(48*10, 48*3, 48, 48);
    inline SDL_FRect tile_sprite_potion_05 = create_sprite_portion(48*10, 48*4, 48, 48);
    inline SDL_FRect tile_sprite_potion_06 = create_sprite_portion(48*10, 48*5, 48, 48);
    inline SDL_FRect tile_sprite_potion_07 = create_sprite_portion(48*10, 48*6, 48, 48);
    inline SDL_FRect tile_sprite_potion_08 = create_sprite_portion(48*10, 48*7, 48, 48);
    inline SDL_FRect tile_sprite_potion_09 = create_sprite_portion(48*10, 48*8, 48, 48);
    inline SDL_FRect tile_sprite_potion_10 = create_sprite_portion(48*10, 48*9, 48, 48);
    inline SDL_FRect tile_sprite_potion_11 = create_sprite_portion(48*10, 48*10, 48, 48);
    inline SDL_FRect tile_sprite_potion_12 = create_sprite_portion(48*10, 48*11, 48, 48);

    //Column 12
    inline SDL_FRect tile_sprite_potion_x = create_sprite_portion(48*11, 0, 48, 48);
    inline SDL_FRect tile_sprite_potion_02 = create_sprite_portion(48*11, 48, 48, 48);
    inline SDL_FRect tile_sprite_potion_03 = create_sprite_portion(48*11, 48*2, 48, 48);
    inline SDL_FRect tile_sprite_potion_04 = create_sprite_portion(48*11, 48*3, 48, 48);
    inline SDL_FRect tile_sprite_potion_05 = create_sprite_portion(48*11, 48*4, 48, 48);
    inline SDL_FRect tile_sprite_potion_06 = create_sprite_portion(48*11, 48*5, 48, 48);
    inline SDL_FRect tile_sprite_potion_07 = create_sprite_portion(48*11, 48*6, 48, 48);
    inline SDL_FRect tile_sprite_potion_08 = create_sprite_portion(48*11, 48*7, 48, 48);
    inline SDL_FRect tile_sprite_potion_09 = create_sprite_portion(48*11, 48*8, 48, 48);
    inline SDL_FRect tile_sprite_potion_10 = create_sprite_portion(48*11, 48*9, 48, 48);
    inline SDL_FRect tile_sprite_potion_11 = create_sprite_portion(48*11, 48*10, 48, 48);
    inline SDL_FRect tile_sprite_potion_12 = create_sprite_portion(48*11, 48*11, 48, 48);

    //Column 13
    inline SDL_FRect tile_sprite_potion_x = create_sprite_portion(48*12, 0, 48, 48);
    inline SDL_FRect tile_sprite_potion_02 = create_sprite_portion(48*12, 48, 48, 48);
    inline SDL_FRect tile_sprite_potion_03 = create_sprite_portion(48*12, 48*2, 48, 48);
    inline SDL_FRect tile_sprite_potion_04 = create_sprite_portion(48*12, 48*3, 48, 48);
    inline SDL_FRect tile_sprite_potion_05 = create_sprite_portion(48*12, 48*4, 48, 48);
    inline SDL_FRect tile_sprite_potion_06 = create_sprite_portion(48*12, 48*5, 48, 48);
    inline SDL_FRect tile_sprite_potion_07 = create_sprite_portion(48*12, 48*6, 48, 48);
    inline SDL_FRect tile_sprite_potion_08 = create_sprite_portion(48*12, 48*7, 48, 48);
    inline SDL_FRect tile_sprite_potion_09 = create_sprite_portion(48*12, 48*8, 48, 48);
    inline SDL_FRect tile_sprite_potion_10 = create_sprite_portion(48*12, 48*9, 48, 48);
    inline SDL_FRect tile_sprite_potion_11 = create_sprite_portion(48*12, 48*10, 48, 48);
    inline SDL_FRect tile_sprite_potion_12 = create_sprite_portion(48*12, 48*11, 48, 48);

    //Column 14
    inline SDL_FRect tile_sprite_potion_x = create_sprite_portion(48*13, 0, 48, 48);
    inline SDL_FRect tile_sprite_potion_02 = create_sprite_portion(48*13, 48, 48, 48);
    inline SDL_FRect tile_sprite_potion_03 = create_sprite_portion(48*13, 48*2, 48, 48);
    inline SDL_FRect tile_sprite_potion_04 = create_sprite_portion(48*13, 48*3, 48, 48);
    inline SDL_FRect tile_sprite_potion_05 = create_sprite_portion(48*13, 48*4, 48, 48);
    inline SDL_FRect tile_sprite_potion_06 = create_sprite_portion(48*13, 48*5, 48, 48);
    inline SDL_FRect tile_sprite_potion_07 = create_sprite_portion(48*13, 48*6, 48, 48);
    inline SDL_FRect tile_sprite_potion_08 = create_sprite_portion(48*13, 48*7, 48, 48);
    inline SDL_FRect tile_sprite_potion_09 = create_sprite_portion(48*13, 48*8, 48, 48);
    inline SDL_FRect tile_sprite_potion_10 = create_sprite_portion(48*13, 48*9, 48, 48);
    inline SDL_FRect tile_sprite_potion_11 = create_sprite_portion(48*13, 48*10, 48, 48);
    inline SDL_FRect tile_sprite_potion_12 = create_sprite_portion(48*13, 48*11, 48, 48);

    //Column 15
    inline SDL_FRect tile_sprite_potion_x = create_sprite_portion(48*14, 0, 48, 48);
    inline SDL_FRect tile_sprite_potion_02 = create_sprite_portion(48*14, 48, 48, 48);
    inline SDL_FRect tile_sprite_potion_03 = create_sprite_portion(48*14, 48*2, 48, 48);
    inline SDL_FRect tile_sprite_potion_04 = create_sprite_portion(48*14, 48*3, 48, 48);
    inline SDL_FRect tile_sprite_potion_05 = create_sprite_portion(48*14, 48*4, 48, 48);
    inline SDL_FRect tile_sprite_potion_06 = create_sprite_portion(48*14, 48*5, 48, 48);
    inline SDL_FRect tile_sprite_potion_07 = create_sprite_portion(48*14, 48*6, 48, 48);
    inline SDL_FRect tile_sprite_potion_08 = create_sprite_portion(48*14, 48*7, 48, 48);
    inline SDL_FRect tile_sprite_potion_09 = create_sprite_portion(48*14, 48*8, 48, 48);
    inline SDL_FRect tile_sprite_potion_10 = create_sprite_portion(48*14, 48*9, 48, 48);
    inline SDL_FRect tile_sprite_potion_11 = create_sprite_portion(48*14, 48*10, 48, 48);
    inline SDL_FRect tile_sprite_potion_12 = create_sprite_portion(48*14, 48*11, 48, 48);

    //Column 16
    inline SDL_FRect tile_sprite_potion_x = create_sprite_portion(48*15, 0, 48, 48);
    inline SDL_FRect tile_sprite_potion_02 = create_sprite_portion(48*15, 48, 48, 48);
    inline SDL_FRect tile_sprite_potion_03 = create_sprite_portion(48*15, 48*2, 48, 48);
    inline SDL_FRect tile_sprite_potion_04 = create_sprite_portion(48*15, 48*3, 48, 48);
    inline SDL_FRect tile_sprite_potion_05 = create_sprite_portion(48*15, 48*4, 48, 48);
    inline SDL_FRect tile_sprite_potion_06 = create_sprite_portion(48*15, 48*5, 48, 48);
    inline SDL_FRect tile_sprite_potion_07 = create_sprite_portion(48*15, 48*6, 48, 48);
    inline SDL_FRect tile_sprite_potion_08 = create_sprite_portion(48*15, 48*7, 48, 48);
    inline SDL_FRect tile_sprite_potion_09 = create_sprite_portion(48*15, 48*8, 48, 48);
    inline SDL_FRect tile_sprite_potion_10 = create_sprite_portion(48*15, 48*9, 48, 48);
    inline SDL_FRect tile_sprite_potion_11 = create_sprite_portion(48*15, 48*10, 48, 48);
    inline SDL_FRect tile_sprite_potion_12 = create_sprite_portion(48*15, 48*11, 48, 48);
    */

    inline SDL_FRect tile_sprite_position = create_sprite_position(250, 250, 48, 48);

    void loadTileTexture();
    void quit();
    void handle_events(SDL_Event* event);
    void update();
    void render(SDL_Renderer* renderer);
    void init_tile();
}

#endif