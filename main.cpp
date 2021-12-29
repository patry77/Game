#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Player.h"
#include "Map.h"

using namespace sf;
using namespace std;

int main() {
    RenderWindow window {VideoMode(1920,1080),"Game"};
    window.setFramerateLimit(60);

    //Gracz
    Texture player_texture;
    player_texture.loadFromFile("../body_move.png");
    Player player_test(&player_texture, Vector2u(4,4), 0.3f);
//    //Mapa
//    Texture background_texture;
//    background_texture.loadFromFile("D:/Programy/workspaceCLion/Game/background.png");
//    background_texture.setRepeated(true);
//    Sprite background_sprite(background_texture);
//    Vector2u size = background_texture.getSize();
//    background_sprite.setTexture(background_texture);
//    background_sprite.setOrigin(size.x / 2, size.y / 2);

    Map map;

    //aktualny widok mapy
    View view(Vector2f(0.0f, 0.0f), Vector2f(960,540));

    //odswiezanie do animacji
    float delta_time = 0.0f;
    Clock clock;

    while(window.isOpen()){
        delta_time = clock.restart().asSeconds();

        Event ev{};
        while(window.pollEvent(ev)){
            if(ev.type == Event::Closed){
                window.close();
                break;
            }
        }

        player_test.update(delta_time);
        window.clear();
        map.draw(window);
        //window.draw(background_sprite);
        window.draw(player_test);
        window.display();
    }

    //system ("pause");
    return 0;
}
