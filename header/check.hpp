#ifndef checkDef
#define checkDef

#include <SDL3/SDL.h>
#include <vector>
#include <window.hpp>

using namespace std;

bool is_border(SDL_Rect player)
{
    windowSize winSize;

    if (player.x < 0 || player.x > winSize.width - 10 ||
        player.y < 0 || player.y > winSize.height - 10)
    {
        return true;
    }
    return false;
}

bool is_touch(const SDL_Rect &player, const vector<SDL_Rect> &walls)
{
    for (const auto &wall : walls)
    {
        if (SDL_HasRectIntersection(&player, &wall))
        {
            return true;
        }
    }
    return false;
}

#endif