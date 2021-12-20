#include "Player.h"

 Player::Player(Texture *texture, Vector2u image_count, float switch_time)
 : animation(texture, image_count, switch_time){
    row = 0;
    face_right = true;
    body.setSize(Vector2f(64.0f, 64.0f));
    body.setPosition(960.f, 540.f);
    body.setTexture(texture);
}

void Player::draw(RenderTarget &target, RenderStates state) const{
    target.draw(this->body, state);
}

void Player::update(float delta_time) {
    Vector2f movement(0.0f, 0.0f);

    if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left)){
        row=0;
    }
    if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right)){
        row=1;
    }
    if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up)){
        row=2;
    }
    if (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down)){
        movement.y += walk_speed * delta_time;
    }

    animation.update(row, delta_time);
    body.setTextureRect(animation.uv_rect);
    body.move(movement);
}
