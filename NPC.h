#pragma once
#ifndef GAME_NPC_H
#define GAME_NPC_H
#include "Animation.h"
#include <SFML/Graphics.hpp>
using namespace sf;

//Test gita

class NPC: public sf::Drawable {
public:
    NPC(Texture *texture);
    ~NPC() override = default;
    float rand_x;
    float rand_y;
    float pos_x=0.0f;
    float pos_y=0.0f;

private:
    RectangleShape body_npc;

    void draw(RenderTarget &target, RenderStates state) const override;
};


#endif //GAME_NPC_H
