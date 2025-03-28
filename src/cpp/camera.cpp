#include "Ataraxia2DCamera.hpp"

namespace camera
{
    inline void create_entity(CameraObject& cam_obj) 
    {
        entities[entities_count++] = cam_obj.entity;
    }

    void update(float delta_time)
    {
        // Log positions for debugging
        //SDL_Log("Camera position: (%.2f, %.2f)", x, y);
        //SDL_Log("Player position: (%.2f, %.2f)", player::player_sprite_position.x, player::player_sprite_position.y);
    }

    void render(SDL_Renderer* renderer)
    {
        int windowWidth, windowHeight;
        SDL_GetRenderOutputSize(renderer, &windowWidth, &windowHeight);
        
        // Fixed viewport size (can be adjusted)
        
        /*
        The ratio on this is that 600 needs to be divided by 2.
        */
        const int viewportWidth = 9600;
        const int viewportHeight = 9600;
        
        int viewportX = static_cast<int>((viewportWidth / 32) - x);
        int viewportY = static_cast<int>((viewportHeight / 32) - y);
        
        SDL_Rect viewport = {
            viewportX,
            viewportY,
            viewportWidth,
            viewportHeight
        };
        
        SDL_SetRenderViewport(renderer, &viewport);
    }

    void reset_camera(SDL_Renderer* renderer)
    {
        SDL_SetRenderViewport(renderer, NULL);
    }

    void quit()
    {
        SDL_Log("Camera resources cleaned up");
    }

    void init_camera(SDL_Renderer* renderer)
    {
        SDL_FPoint size;
        SDL_GetRenderOutputSize(
            renderer, reinterpret_cast<int*>(&size.x), 
            reinterpret_cast<int*>(&size.y));

        x = 0;
        y = 0;
        w = size.x;
        h = size.y;
        
        SDL_Log("Camera initialized with dimensions: (%.2f, %.2f)", w, h);
        
        camera_object.entity = {
            .quit = quit,
            .handle_events = nullptr,
            .update = update,
            .render = render
        };
        
        create_entity(camera_object);
    }
}
