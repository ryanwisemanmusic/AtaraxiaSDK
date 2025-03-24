#include "player.hpp"

void player_quit()
{

}
void player_handle_events()
{

}
void player_update()
{
    const bool *keyboard_state = SDL_GetKeyboardState(NULL);

    if (keyboard_state[SDL_SCANCODE_W])
    {
        player_sprite_position.y -= 0.1;
    }
    if (keyboard_state[SDL_SCANCODE_S])
    {
        player_sprite_position.y += 0.1;
    }
    if (keyboard_state[SDL_SCANCODE_A])
    {
        player_sprite_position.x -= 0.1;
    }
    if (keyboard_state[SDL_SCANCODE_D])
    {
        player_sprite_position.x += 0.1;
    }
}
void player_render()
{
    SDL_RenderTexture(
        renderer, player_texture, 
        &player_sprite_portion, &player_sprite_position);
}
void init_player()
{

}
