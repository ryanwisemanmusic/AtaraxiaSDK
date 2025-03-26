#ifndef MAPTILE
#define MAPTILE

#include "AtaraxiaMain.hpp"
#include "entity.hpp"
#include <SDL3/SDL_render.h>
#include <unordered_map>
#include <string>
#include <vector>
//48x48 map tile map support
namespace two_d_tiles 
{
    inline SDL_Texture* tile_texture;
    
    //You increase the index by 1 for each tilemap you add
    const std::vector<std::string> TEXTURE_PATHS = 
    {
        "assets/images/outsideTileMap.png",
        "assets/images/trees.png"
    };
    const int NUM_TEXTURES = TEXTURE_PATHS.size();

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

    class TileMap 
    {
    private:
        static const int TILE_SIZE = 48;
        static const int MAP_SIZE = 48;
        std::unordered_map<std::string, SDL_Texture*> tile_textures;
        std::unordered_map<std::string, SDL_FRect> tile_sprites;
        std::unordered_map<std::string, SDL_FRect> tile_positions;

    public:
        TileMap() 
        {
            // Initialize tile sprites
            for (int col = 0; col < MAP_SIZE; col++) 
            {
                for (int row = 0; row < MAP_SIZE; row++) 
                {
                    std::string key = std::to_string(col) + "," + std::to_string(row);
                    tile_sprites[key] = create_sprite_portion(
                        col * TILE_SIZE, 
                        row * TILE_SIZE, 
                        TILE_SIZE, 
                        TILE_SIZE
                    );
                }
            }
        }

        ~TileMap() 
        {
            for (auto& pair : tile_textures) 
            {
                if (pair.second) {
                    SDL_DestroyTexture(pair.second);
                }
            }
        }

        bool loadTileTexture(const std::string& name, const char* path) 
        {
            SDL_Texture* texture = IMG_LoadTexture(renderer, path);
            if (!texture) 
            {
                SDL_Log("Tile texture '%s' could not be loaded! SDL error: %s\n", 
                    name.c_str(), SDL_GetError());
                return false;
            }
            SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);
            SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND);
            tile_textures[name] = texture;
            SDL_Log("Tile texture '%s' loaded successfully", name.c_str());
            return true;
        }

        // Get a specific tile texture
        SDL_Texture* getTileTexture(const std::string& name) 
        {
            auto it = tile_textures.find(name);
            return it != tile_textures.end() ? it->second : nullptr;
        }

        SDL_FRect* getTileSprite(int col, int row) 
        {
            std::string key = std::to_string(col) + "," + std::to_string(row);
            auto it = tile_sprites.find(key);
            return it != tile_sprites.end() ? &it->second : nullptr;
        }

        void setTilePosition(int col, int row, float x, float y) 
        {
            std::string key = std::to_string(col) + "," + std::to_string(row);
            tile_positions[key] = create_sprite_position(x, y, TILE_SIZE, TILE_SIZE);
        }

        SDL_FRect* getTilePosition(int col, int row) 
        {
            std::string key = std::to_string(col) + "," + std::to_string(row);
            auto it = tile_positions.find(key);
            return it != tile_positions.end() ? &it->second : nullptr;
        }
    };

    // Global tile map instance
    inline TileMap tile_map;

    void loadTileTexture();
    void quit();
    void handle_events(SDL_Event* event);
    void update();
    void render(SDL_Renderer* renderer);
    void init_tile();
}

#endif