#include "NPC.h"
#include <cstdlib>
#include <ctime>

NPC::NPC(Texture *texture){

    srand( time( NULL ) );
    pos_x = ( std::rand() % 1921 );
    pos_y = ( std::rand() % 1081 );

    body_npc.setSize(Vector2f(64.0f, 64.0f));
    body_npc.setOrigin(body_npc.getSize() / 2.0f);
    body_npc.setPosition(pos_x, pos_y);
    body_npc.setTexture(texture);
}
NPC::NPC(Texture *texture, float pos_x, float pos_y){
    body_npc.setSize(Vector2f(64.0f, 64.0f));
    body_npc.setOrigin(body_npc.getSize() / 2.0f);
    body_npc.setPosition(pos_x, pos_y);
    body_npc.setTexture(texture);
}

void NPC::draw(RenderTarget &target, RenderStates state) const {
    target.draw(this->body_npc, state);
}