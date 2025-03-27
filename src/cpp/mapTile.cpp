#include "AtaraxiaMain.hpp"
#define SDL_MAIN_USE_CALLBACKS
#include "mapTile.hpp"
#include "player.hpp"
#include "AtaraxiaTime.hpp"
#include "AtaraxiaInput.hpp"

namespace two_d_tiles {
    void loadTileTexture()
    {
        if (!tile_map.loadTileTexture("0", "assets/images/outsideTileMap.png")) {
            SDL_Log("Failed to load tilemap texture: %s", SDL_GetError());
        }
        if (!tile_map.loadTileTexture("1", "assets/images/trees.png")) {
            SDL_Log("Failed to load trees texture: %s", SDL_GetError());
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

    /*
    This is where we'll store player interactions with the tile, given
    that we now are getting the coordinates of the tile. We need cross
    talk between the player and the tile, but luckily, it shouldn't be
    hard to pull the co-ordinates.
    
    If you check how the terminal logs what you do, you'll see how
    there is cross talk exactly with everything as it should. This means
    that soon, our collision system will be setup to handle how we process
    sprites with player, a better colission system
    */
    void update(float delta_time)
    {
        player::player_tracker();
    
        if (player::player_current_grid_x == 5 && player::player_current_grid_y == 5) {
            SDL_Log("Player is at the special tile (5,5)!");
        }
        
        if (player::player_is_moving) {
        }
        
        if (player::is_position_blocked(player::player_target_grid_x, player::player_target_grid_y)) {
            SDL_Log("Player trying to move to a blocked position!");
        }
        
        if (input::is_key_pressed(SDL_SCANCODE_SPACE)) {
            SDL_Log("Spacebar pressed! Cross talk enabled");
        }
    }

    void render(SDL_Renderer* renderer)
    {
        if (SDL_Texture* texture = tile_map.getTileTexture("0"))
        {
            SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);
            
            if (SDL_FRect* sprite = tile_map.getTileSprite(7, 3)) 
            {
                //Row 1
                if (SDL_FRect* pos = tile_map.getTilePosition(0, 0)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(1, 0)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(2, 0)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(3, 0)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(4, 0)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(5, 0)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(6, 0)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(7, 0)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(8, 0)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(9, 0)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(10, 0)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(11, 0)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(12, 0)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }

                //Row 2
                if (SDL_FRect* pos = tile_map.getTilePosition(0, 1)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(1, 1)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(2, 1)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(3, 1)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(4, 1)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(5, 1)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(6, 1)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(7, 1)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(8, 1)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(9, 1)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(10, 1)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(11, 1)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(12, 1)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }

                //Row 3
                if (SDL_FRect* pos = tile_map.getTilePosition(0, 2)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(1, 2)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(2, 2)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(3, 2)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(4, 2)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(5, 2)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(6, 2)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(7, 2)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(8, 2)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(9, 2)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(10, 2)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(11, 2)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(12, 2)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }

                //Row 4
                if (SDL_FRect* pos = tile_map.getTilePosition(0, 3)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(1, 3)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(2, 3)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(3, 3)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(4, 3)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(5, 3)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(6, 3)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(7, 3)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(8, 3)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(9, 3)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(10, 3)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(11, 3)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(12, 3)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }

                //Row 5
                if (SDL_FRect* pos = tile_map.getTilePosition(0, 4)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(1, 4)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(2, 4)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(3, 4)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(4, 4)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(5, 4)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(6, 4)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(7, 4)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(8, 4)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(9, 4)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(10, 4)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(11, 4)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(12, 4)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }

                //Row 6
                if (SDL_FRect* pos = tile_map.getTilePosition(0, 5)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(1, 5)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(2, 5)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(3, 5)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(4, 5)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(5, 5)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(6, 5)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(7, 5)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(8, 5)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(9, 5)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(10, 5)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(11, 5)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(12, 5)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }

                //Row 7
                if (SDL_FRect* pos = tile_map.getTilePosition(0, 6)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(1, 6)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(2, 6)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(3, 6)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(4, 6)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(5, 6)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(6, 6)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(7, 6)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(8, 6)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(9, 6)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(10, 6)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(11, 6)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(12, 6)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }

                //Row 8
                if (SDL_FRect* pos = tile_map.getTilePosition(0, 7)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(1, 7)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(2, 7)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(3, 7)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(4, 7)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(5, 7)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(6, 7)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(7, 7)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(8, 7)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(9, 7)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(10, 7)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(11, 7)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(12, 7)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }

                //Row 9
                if (SDL_FRect* pos = tile_map.getTilePosition(0, 8)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(1, 8)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(2, 8)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(3, 8)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(4, 8)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(5, 8)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(6, 8)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(7, 8)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(8, 8)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(9, 8)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(10, 8)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(11, 8)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(12, 8)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }

                //Row 10
                if (SDL_FRect* pos = tile_map.getTilePosition(0, 9)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(1, 9)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(2, 9)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(3, 9)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(4, 9)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(5, 9)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(6, 9)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(7, 9)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(8, 9)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(9, 9)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(10, 9)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(11, 9)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(12, 9)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }

                //Row 11
                if (SDL_FRect* pos = tile_map.getTilePosition(0, 10)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(1, 10)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(2, 10)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(3, 10)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(4, 10)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(5, 10)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(6, 10)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(7, 10)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(8, 10)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(9, 10)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(10, 10)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(11, 10)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(12, 10)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }

                //Row 11
                if (SDL_FRect* pos = tile_map.getTilePosition(0, 11)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(1, 11)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(2, 11)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(3, 11)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(4, 11)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(5, 11)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(6, 11)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(7, 11)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(8, 11)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(9, 11)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(10, 11)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(11, 11)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(12, 11)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }

                //Row 12
                if (SDL_FRect* pos = tile_map.getTilePosition(0, 12)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(1, 12)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(2, 12)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(3, 12)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(4, 12)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(5, 12)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(6, 12)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(7, 12)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(8, 12)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(9, 12)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(10, 12)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(11, 12)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(12, 12)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }

                //Row 13
                if (SDL_FRect* pos = tile_map.getTilePosition(0, 13)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(1, 13)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(2, 13)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(3, 13)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(4, 13)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(5, 13)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(6, 13)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(7, 13)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(8, 13)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(9, 13)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(10, 13)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(11, 13)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(12, 13)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
            }
        }
        
        //Grassy plane render
        

        //Pond render
        if (SDL_Texture* texture = tile_map.getTileTexture("0")) 
        {
            //Top left
            if (SDL_FRect* sprite = tile_map.getTileSprite(4, 1))
            {
                if (SDL_FRect* pos = tile_map.getTilePosition(4, 2)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
            }
            //Top right
            if (SDL_FRect* sprite = tile_map.getTileSprite(5, 1))
            {
                if (SDL_FRect* pos = tile_map.getTilePosition(5, 2)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
            }
            //Bottom left
            if (SDL_FRect* sprite = tile_map.getTileSprite(4, 2))
            {
                if (SDL_FRect* pos = tile_map.getTilePosition(4, 3)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
            }
            //Bottom right
            if (SDL_FRect* sprite = tile_map.getTileSprite(5, 2))
            {
                if (SDL_FRect* pos = tile_map.getTilePosition(5, 3)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
            }
        }

        //Tree render
        if (SDL_Texture* texture = tile_map.getTileTexture("1"))
        {
            SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);
            SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);

            if (SDL_FRect* sprite = tile_map.getTileSprite(0, 2))
            {
                if (SDL_FRect* pos = tile_map.getTilePosition(6, 6)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
            }
            
            if (SDL_FRect* sprite = tile_map.getTileSprite(1, 2))
            {
                if (SDL_FRect* pos = tile_map.getTilePosition(7, 6)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
            }
            
            if (SDL_FRect* sprite = tile_map.getTileSprite(0, 3))
            {
                if (SDL_FRect* pos = tile_map.getTilePosition(6, 7)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
            }
            
            if (SDL_FRect* sprite = tile_map.getTileSprite(1, 3))
            {
                if (SDL_FRect* pos = tile_map.getTilePosition(7, 7)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
            }
                
        }
    }

    void init_tile()
    {
        loadTileTexture();
        //Set this to the size of your map
        for (int col = 0; col < 16; col++) 
        { 
            for (int row = 0; row < 13; row++) 
            {
                tile_map.setTilePosition(col, row, col * 48, row * 48);
            }
        }
        //Pond tiles blocked
        tile_map.setTileBlocked(3, 1, true);
        tile_map.setTileBlocked(4, 1, true);
        tile_map.setTileBlocked(3, 2, true);
        tile_map.setTileBlocked(4, 2, true);

        //Tree tiles blocked
        tile_map.setTileBlocked(5, 5, true);
        tile_map.setTileBlocked(6, 5, true);
        tile_map.setTileBlocked(5, 6, true);
        tile_map.setTileBlocked(6, 6, true);

        
        Entity tile_entity = 
        {
            .quit = quit,
            .handle_events = handle_events,
            .update = update, 
            .render = render
        };
        
        entities_tile[entities_count_tile++] = tile_entity;
    }
}
