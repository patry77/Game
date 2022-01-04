#pragma once
#ifndef GAME_MENU_H
#define GAME_MENU_H
#include <SFML/Graphics.hpp>
#define MAX_NUMBER_OF_ITEM 3

class Menu {
public:
    Menu(float width, float height);
    ~Menu();

    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem(){return selectedItemIndex;}
private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text menu[MAX_NUMBER_OF_ITEM];
};


#endif //GAME_MENU_H

