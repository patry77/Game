#pragma once
#ifndef GAME_ANIMATION_H
#define GAME_ANIMATION_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Animation {
public:
    Animation(Texture *texture, Vector2u image_count, float switch_time);
    ~Animation();

    void update(int row, float delta_time);

    IntRect uv_rect;

private:
    Vector2u image_count;
    Vector2u current_image;

    float total_time{};
    float switch_time{};
};


#endif //GAME_ANIMATION_H
