#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Map.h"

using namespace sf;
using namespace std;

static const float VIEW_HEIGHT = 1000;

void resize_view(const RenderWindow &window, View &view){
    float proporcja = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(VIEW_HEIGHT * proporcja, VIEW_HEIGHT);
}

int main() {
    RenderWindow window {VideoMode(VIEW_HEIGHT,VIEW_HEIGHT),"Game"};
    window.setFramerateLimit(60);

    //Gracz
    Texture player_texture;
    player_texture.loadFromFile("D:/Programy/workspaceCLion/Game/body_move.png");
    Player player_test(&player_texture, Vector2u(4,4), 0.3f);

    //kamera - widok, zeby dobrze scalował obiekty przy zmianie rozmiaru okna i kamera przesuwala sie z postacia
    View view(Vector2f(0.0f, 0.0f), Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));

    //mapa
    Map map;

    //odswiezanie do animacji
    float delta_time = 0.0f;
    Clock clock;

    while(window.isOpen()){
        delta_time = clock.restart().asSeconds();

        Event ev{};
        while(window.pollEvent(ev)){
            switch(ev.type){
                case Event::Closed:
                    window.close();
                    break;
                case Event::Resized:
                    resize_view(window, view);
                    break;
            }
        }

        player_test.update(delta_time);
        view.setCenter(player_test.get_position());
        window.clear();
        window.setView(view);
        map.draw(window);
        window.draw(player_test);
        window.display();
    }

    //system ("pause");
    return 0;
}
