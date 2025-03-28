#pragma once
#include "AtaraxiaMain.hpp"
#include "entity.hpp"
#include "player.hpp"

namespace camera
{
    // Define a camera object structure
    struct CameraObject {
        Entity entity;
    };

    // Create a camera object instance
    inline CameraObject camera_object;

    // Declare variables as inline to avoid duplicate symbol errors
    inline float x, y, w, h;

    inline void create_entity(CameraObject& cam_obj);

    void init_camera(SDL_Renderer* renderer);
    void update(float delta_time);
    void render(SDL_Renderer* renderer);
    void reset_camera(SDL_Renderer* renderer);
    void quit();
}

