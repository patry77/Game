#include "Animation.h"

Animation::Animation(Texture *texture, Vector2u image_count, float switch_time) {
    this->image_count = image_count;
    this->switch_time = switch_time;
    total_time = 0.0f;
    current_image.x = 0;

    uv_rect.width = texture->getSize().x / float(image_count.x);
    uv_rect.height = texture->getSize().y / float(image_count.y);
}

Animation::~Animation(){
}

void Animation::update(int row, float delta_time) {
    current_image.y = row;
    total_time += delta_time;

    if(total_time >= switch_time){
        total_time -= switch_time;
        current_image.x++;

        if(current_image.x >= image_count.x){
            current_image.x = 0;
        }
    }
    uv_rect.top = current_image.y * uv_rect.height;
        uv_rect.left = current_image.x * uv_rect.width;
        uv_rect.width = abs(uv_rect.width);

}


