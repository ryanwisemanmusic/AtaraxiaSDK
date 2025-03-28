#include "AtaraxiaMain.hpp"
#define SDL_MAIN_USE_CALLBACKS
#include "mapTile.hpp"
#include "player.hpp"
#include "AtaraxiaTime.hpp"
#include "AtaraxiaInput.hpp"

namespace two_d_tiles 
{
    void loadTileTexture()
    {
        if (!tile_map.loadTileTexture("0", "assets/images/outsideTileMap.png")) 
        {
            SDL_Log("Failed to load tilemap texture: %s", SDL_GetError());
        }
        if (!tile_map.loadTileTexture("1", "assets/images/trees.png")) 
        {
            SDL_Log("Failed to load trees texture: %s", SDL_GetError());
        }
    }

    void quit()
    {
        if (tile_texture) 
        {
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
        // Call player_tracker to update player position info
        player::player_tracker();
        
        if (player::player_is_moving && 
            tile_map.isTileBlocked(
                player::player_target_grid_x, 
                player::player_target_grid_y)) 
                {
                    SDL_Log("Player trying to move to a blocked position!");
                }
        
        if (input::is_key_pressed(SDL_SCANCODE_SPACE)) 
        {
            int px = player::player_current_grid_x;
            int py = player::player_current_grid_y;
            
            // Example: Check if player is next to a tree
            if ((px == 5 && py == 6) || (px == 7 && py == 6) || 
                (px == 6 && py == 5) || (px == 6 && py == 7)) 
                {
                SDL_Log("Interacting with tree!");
            }
            
            SDL_Log("Spacebar pressed! Checking for interactions");
        }
    }

    //This is where you draw each tile. 
    void render(SDL_Renderer* renderer)
    {
        float camX = camera::x;
        float camY = camera::y;
        
        // Match this to what is set in camera.cpp
        int viewportWidth = 9600; 
        int viewportHeight = 9600; 
        
        int startCol = std::max(0, static_cast<int>((camX - viewportWidth/2) / 48) - 2);
        int endCol = std::min(499, static_cast<int>((camX + viewportWidth/2) / 48) + 2);
        int startRow = std::max(0, static_cast<int>((camY - viewportHeight/2) / 48) - 2);
        int endRow = std::min(499, static_cast<int>((camY + viewportHeight/2) / 48) + 2);
        
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
                if (SDL_FRect* pos = tile_map.getTilePosition(13, 0)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(14, 0)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(15, 0)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(16, 0)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(17, 0)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(18, 0)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(19, 0)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(20, 0)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(21, 0)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(22, 0)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(23, 0)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(24, 0)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(25, 0)) 
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
                if (SDL_FRect* pos = tile_map.getTilePosition(13, 1)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(14, 1)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(15, 1)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(16, 1)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(17, 1)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(18, 1)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(19, 1)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(20, 1)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(21, 1)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(22, 1)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(23, 1)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(24, 1)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(25, 1)) 
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
                if (SDL_FRect* pos = tile_map.getTilePosition(13, 2)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(14, 2)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(15, 2)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(16, 2)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(17, 2)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(18, 2)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(19, 2)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(20, 2)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(21, 2)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(22, 2)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(23, 2)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(24, 2)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(25, 2)) 
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
                if (SDL_FRect* pos = tile_map.getTilePosition(13, 3)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(14, 3)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(15, 3)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(16, 3)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(17, 3)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(18, 3)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(19, 3)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(20, 3)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(21, 3)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(22, 3)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(23, 3)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(24, 3)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(25, 3)) 
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
                if (SDL_FRect* pos = tile_map.getTilePosition(13, 4)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(14, 4)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(15, 4)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(16, 4)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(17, 4)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(18, 4)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(19, 4)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(20, 4)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(21, 4)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(22, 4)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(23, 4)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(24, 4)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(25, 4)) 
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
                if (SDL_FRect* pos = tile_map.getTilePosition(13, 5)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(14, 5)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(15, 5)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(16, 5)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(17, 5)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(18, 5)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(19, 5)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(20, 5)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(21, 5)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(22, 5)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(23, 5)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(24, 5)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(25, 5)) 
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
                if (SDL_FRect* pos = tile_map.getTilePosition(13, 6)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(14, 6)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(15, 6)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(16, 6)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(17, 6)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(18, 6)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(19, 6)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(20, 6)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(21, 6)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(22, 6)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(23, 6)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(24, 6)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(25, 6)) 
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
                if (SDL_FRect* pos = tile_map.getTilePosition(13, 7)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(14, 7)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(15, 7)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(16, 7)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(17, 7)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(18, 7)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(19, 7)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(20, 7)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(21, 7)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(22, 7)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(23, 7)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(24, 7)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(25, 7)) 
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
                if (SDL_FRect* pos = tile_map.getTilePosition(13, 8)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(14, 8)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(15, 8)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(16, 8)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(17, 8)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(18, 8)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(19, 8)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(20, 8)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(21, 8)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(22, 8)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(23, 8)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(24, 8)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(25, 8)) 
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
                if (SDL_FRect* pos = tile_map.getTilePosition(13, 9)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(14, 9)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(15, 9)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(16, 9)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(17, 9)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(18, 9)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(19, 9)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(20, 9)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(21, 9)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(22, 9)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(23, 9)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(24, 9)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(25, 9)) 
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
                if (SDL_FRect* pos = tile_map.getTilePosition(13, 10)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(14, 10)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(15, 10)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(16, 10)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(17, 10)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(18, 10)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(19, 10)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(20, 10)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(21, 10)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(22, 10)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(23, 10)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(24, 10)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(25, 10)) 
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
                if (SDL_FRect* pos = tile_map.getTilePosition(13, 11)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(14, 11)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(15, 11)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(16, 11)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(17, 11)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(18, 11)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(19, 11)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(20, 11)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(21, 11)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(22, 11)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(23, 11)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(24, 11)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(25, 11)) 
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
                if (SDL_FRect* pos = tile_map.getTilePosition(13, 12)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(14, 12)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(15, 12)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(16, 12)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(17, 12)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(18, 12)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(19, 12)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(20, 12)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(21, 12)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(22, 12)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(23, 12)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(24, 12)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(25, 12)) 
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
                if (SDL_FRect* pos = tile_map.getTilePosition(13, 13)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(14, 13)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(15, 13)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(16, 13)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(17, 13)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(18, 13)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(19, 13)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(20, 13)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(21, 13)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(22, 13)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(23, 13)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(24, 13)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(25, 13)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }

                //Row 14
                if (SDL_FRect* pos = tile_map.getTilePosition(0, 14)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(1, 14)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(2, 14)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(3, 14)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(4, 14)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(5, 14)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(6, 14)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(7, 14)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(8, 14)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(9, 14)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(10, 14)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(11, 14)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(12, 14)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(13, 14)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(14, 14)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(15, 14)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(16, 14)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(17, 14)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(18, 14)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(19, 14)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(20, 14)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(21, 14)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(22, 14)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(23, 14)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(24, 14)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(25, 14)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }

                //Row 15
                if (SDL_FRect* pos = tile_map.getTilePosition(0, 15)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(1, 15)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(2, 15)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(3, 15)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(4, 15)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(5, 15)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(6, 15)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(7, 15)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(8, 15)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(9, 15)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(10, 15)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(11, 15)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(12, 15)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(13, 15)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(14, 15)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(15, 15)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(16, 15)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(17, 15)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(18, 15)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(19, 15)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(20, 15)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(21, 15)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(22, 15)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(23, 15)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(24, 15)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(25, 15)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }

                //Row 16
                if (SDL_FRect* pos = tile_map.getTilePosition(0, 16)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(1, 16)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(2, 16)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(3, 16)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(4, 16)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(5, 16)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(6, 16)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(7, 16)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(8, 16)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(9, 16)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(10, 16)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(11, 16)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(12, 16)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(13, 16)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(14, 16)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(15, 16)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(16, 16)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(17, 16)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(18, 16)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(19, 16)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(20, 16)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(21, 16)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(22, 16)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(23, 16)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(24, 16)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(25, 16)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }

                //Row 18
                if (SDL_FRect* pos = tile_map.getTilePosition(0, 17)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(1, 17)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(2, 17)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(3, 17)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(4, 17)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(5, 17)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(6, 17)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(7, 17)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(8, 17)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(9, 17)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(10, 17)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(11, 17)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(12, 17)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(13, 17)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(14, 17)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(15, 17)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(16, 17)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(17, 17)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(18, 17)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(19, 17)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(20, 17)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(21, 17)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(22, 17)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(23, 17)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(24, 17)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(25, 17)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }

                //Row 19
                if (SDL_FRect* pos = tile_map.getTilePosition(0, 18)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(1, 18)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(2, 18)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(3, 18)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(4, 18)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(5, 18)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(6, 18)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(7, 18)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(8, 18)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(9, 18)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(10, 18)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(11, 18)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(12, 18)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(13, 18)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(14, 18)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(15, 18)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(16, 18)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(17, 18)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(18, 18)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(19, 18)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(20, 18)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(21, 18)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(22, 18)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(23, 18)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(24, 18)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
                if (SDL_FRect* pos = tile_map.getTilePosition(25, 18)) 
                {
                    SDL_RenderTexture(renderer, texture, sprite, pos);
                }
            }
        }
        

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
        
        //Map Size
        int mapWidth = 500;
        int mapHeight = 500;
        
        // Initialize all tile positions
        for (int col = 0; col < mapWidth; col++) 
        { 
            for (int row = 0; row < mapHeight; row++) 
            {
                tile_map.setTilePosition(col, row, col * 48, row * 48);
            }
        }
        
        /*
        Right here are function calls for your various objects 
        with barriers. It is best to wrap these in the .hpp section since
        it looks better in terms of logic
        */
        pondBarrier();
        treeBarrier();
        
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
