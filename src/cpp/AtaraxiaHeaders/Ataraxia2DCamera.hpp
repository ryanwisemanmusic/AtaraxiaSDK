#pragma once
#include "AtaraxiaMain.hpp"
#include "entity.hpp"
#include "player.hpp"

namespace camera
{
    struct CameraObject 
    {
        Entity entity;
    };

    inline CameraObject camera_object;

    inline float x, y, w, h;

    inline void create_entity(CameraObject& cam_obj);

    void init_camera(SDL_Renderer* renderer);
    void update(float delta_time);
    void render(SDL_Renderer* renderer);
    void reset_camera(SDL_Renderer* renderer);
    void quit();
}

