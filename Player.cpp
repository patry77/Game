#include <iostream>
#include "Player.h"

 Player::Player(Texture *texture, Vector2u image_count, float switch_time)
 : animation(texture, image_count, switch_time){
    row = 0;
    body.setOrigin(body.getSize() / 2.0f);
    body.setSize(Vector2f(64.0f, 64.0f));
    body.setPosition(960.f, 540.f);
    body.setTexture(texture);
}

void Player::draw(RenderTarget &target, RenderStates state) const{
    target.draw(this->body, state);
}

void Player::update(float delta_time) {
    Vector2f movement(0.0f, 0.0f);
    //kolizja lewo
    if(body.getPosition().x < 0)
        this->body.setPosition(0.f, body.getPosition().y);
    //kolizja gora
    if(body.getPosition().y < 0)
        body.setPosition(body.getPosition().x, 0);
    //kolizja prawo
    if(body.getPosition().x + body.getGlobalBounds().width > 1920)
        body.setPosition(1920-body.getGlobalBounds().width, body.getPosition().y);
    //kolizja dol
    if(body.getPosition().y + body.getGlobalBounds().height > 1080)
        body.setPosition(body.getPosition().x, 1080-body.getGlobalBounds().height);
    //ruszanie sie
    if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left)){
        movement.x -= walk_speed * delta_time;
    }
    if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right)){
        movement.x += walk_speed * delta_time;
    }
    if (Keyboard::isKeyPressed(Keyboard::W) || Keyboard::isKeyPressed(Keyboard::Up)){
        movement.y -= walk_speed * delta_time;
    }
    if (Keyboard::isKeyPressed(Keyboard::S) || Keyboard::isKeyPressed(Keyboard::Down)){
        movement.y += walk_speed * delta_time;
    }

    if(movement.x == 0.0f && movement.y == 0.0f){
        row = 0;
    }
    //gora-lewo
    else if(movement.x < 0.0f && movement.y < 0.0f ){
        row = 1;
        animation.update(row, delta_time);
    }
    //gora-prawo
    else if(movement.x > 0.0f && movement.y < 0.0f ){
        row = 2;
        animation.update(row, delta_time);
    }
    //dol-lewo
    else if(movement.x < 0.0f && movement.y > 0.0f ){
        row = 1;
        animation.update(row, delta_time);
    }
    //dol-prawo
    else if(movement.x > 0.0f && movement.y > 0.0f ){
        row = 2;
        animation.update(row, delta_time);
    }
    //lewo
    else if(movement.x < 0.0f && movement.y == 0.0f ){
        row = 1;
        animation.update(row, delta_time);
    }
    //prawo
    else if(movement.x > 0.0f && movement.y == 0.0f ){
        row = 2;
        animation.update(row, delta_time);
    }
    //dol
    else if(movement.x == 0.0f && movement.y > 0.0f ){
        row = 0;
        animation.update(row, delta_time);
    }
    //gora
    else if(movement.x == 0.0f && movement.y < 0.0f ){
        row = 3;
        animation.update(row, delta_time);
    }

    body.setTextureRect(animation.uv_rect);
    body.move(movement);
}
