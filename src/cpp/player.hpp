#ifndef PLAYER
#define PLAYER

#include "AtaraxiaMain.hpp"
#include "AtaraxiaGame.hpp"
#include "entity.hpp"
#include <unordered_map>
#include <string>



namespace player {
    const std::unordered_map<std::string, std::string> PLAYER_TEXTURES = 
    {
        {"player", "assets/images/elaine_walking.png"}
    };

    inline SDL_Texture* player_texture;

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

    inline SDL_FRect player_sprite_position = create_sprite_position(500, 500, 48, 48);

    inline SDL_FRect* getPlayerSprite(int col, int row) 
    {
        static SDL_FRect sprite;
        sprite.x = col * 48.0f;
        sprite.y = row * 48.0f;
        sprite.w = 48.0f;
        sprite.h = 48.0f;
        return &sprite;
    }

    inline int current_sprite_col = 0;
    inline int current_sprite_row = 0;

    // Player position variables
    inline float player_x;
    inline float player_y;
    inline int player_grid_x;
    inline int player_grid_y;
    extern bool player_is_moving;
    inline int player_direction;

    inline int player_prev_grid_x = 0;
    inline int player_prev_grid_y = 0;
    inline bool player_grid_changed = false;

    extern float player_adjusted_x;
    extern float player_adjusted_y;
    extern int player_current_grid_x;
    extern int player_current_grid_y;
    extern int player_target_grid_x;
    extern int player_target_grid_y;
    
    bool is_position_blocked(int grid_x, int grid_y);
    void move_player(float delta_time);
    
    void init_player();
    
    void player_tracker();

}

#endif
