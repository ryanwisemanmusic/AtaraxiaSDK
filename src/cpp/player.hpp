#ifndef PLAYER
#define PLAYER

#include "AtaraxiaMain.hpp"
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

    inline SDL_FRect player_sprite_position = create_sprite_position(250, 250, 48, 48);

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

    void loadPlayerTexture();
    void render(SDL_Renderer* renderer);
    void update(float delta_time);
    void init_player();

}

#endif
