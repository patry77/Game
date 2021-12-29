#pragma once
#ifndef GAME_MAP_H
#define GAME_MAP_H
#include <SFML/Graphics.hpp>

class Map {
public:
    Map();
    void draw(sf::RenderWindow &window);

private:
    void initIntRect();

private:
    const int tileWidth;
    const int tileHeight;

    sf::Texture tileSheet;
    sf::Sprite tile;

    sf::IntRect pinkPath;
    sf::IntRect woodenBox;
    sf::IntRect grass;
    sf::IntRect stoneWall;
};


#endif //GAME_MAP_H
