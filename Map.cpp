#include "Map.h"

Map::Map() : tileHeight(64), tileWidth(64) {
    tileSheet.loadFromFile("../background.jpg");
    tile.setTexture(tileSheet);
    initIntRect();
}

void Map::draw(sf::RenderWindow &window) {
    const int mapRows = 30;
    const int mapColumns = 20;

    /*
    The codes with their corresponding tiles
        - 0	=	pink path
        - 1	=	stone wall
        - 2	=	wooden box
        - 3	=	grass
    */

    int map[mapColumns][mapRows] =
            {
                    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, // row 1
                    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, // row 2
                    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, // row 3
                    { 1, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 1 }, // row 4
                    { 1, 0, 0, 2, 3, 3, 3, 3, 2, 0, 0, 2, 3, 3, 3, 3, 2, 0, 0, 1 }, // row 5
                    { 1, 0, 0, 2, 3, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 3, 2, 0, 0, 1 }, // row 6
                    { 1, 0, 0, 2, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 3, 2, 0, 0, 1 }, // row 7
                    { 1, 0, 0, 2, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 3, 2, 0, 0, 1 }, // row 8
                    { 1, 0, 0, 2, 2, 2, 0, 0, 2, 2, 2, 2, 0, 0, 2, 2, 2, 0, 0, 1 }, // row 9
                    { 1, 0, 0, 0, 0, 0, 0, 0, 2, 3, 3, 2, 0, 0, 0, 0, 0, 0, 0, 1 }, // row 10
                    { 1, 0, 0, 0, 0, 0, 0, 0, 2, 3, 3, 2, 0, 0, 0, 0, 0, 0, 0, 1 }, // row 11
                    { 1, 0, 0, 2, 2, 2, 0, 0, 2, 2, 2, 2, 0, 0, 2, 2, 2, 0, 0, 1 }, // row 12
                    { 1, 0, 0, 2, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 3, 2, 0, 0, 1 }, // row 13
                    { 1, 0, 0, 2, 3, 2, 0, 0, 0, 0, 0, 0, 0, 0, 2, 3, 2, 0, 0, 1 }, // row 14
                    { 1, 0, 0, 2, 3, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 3, 2, 0, 0, 1 }, // row 15
                    { 1, 0, 0, 2, 3, 3, 3, 3, 2, 0, 0, 2, 3, 3, 3, 3, 2, 0, 0, 1 }, // row 16
                    { 1, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 1 }, // row 17
                    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, // row 18
                    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }, // row 19
                    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, // row 20
            };

    sf::IntRect placeHolder;

    for (int row = 0; row < mapRows; row++)
    {
        for (int column = 0; column < mapColumns; column++)
        {
            switch (map[row][column])
            {
                case 0:
                    placeHolder = pinkPath;
                    break;
                case 1:
                    placeHolder = stoneWall;
                    break;
                case 2:
                    placeHolder = woodenBox;
                    break;
                case 3:
                    placeHolder = grass;
                    break;
            }

            tile.setTextureRect(placeHolder);

            tile.setPosition((row * tileWidth), (column * tileHeight));

            window.draw(tile);
        }
    }
}

void Map::initIntRect() {
    grass.left = 0;
    grass.top = 0;
    grass.width = tileWidth;
    grass.height = tileHeight;

    pinkPath.left = 64;
    pinkPath.top = 0;
    pinkPath.width = tileWidth;
    pinkPath.height = tileHeight;

    stoneWall.left = 0;
    stoneWall.top = 64;
    stoneWall.width = tileWidth;
    stoneWall.height = tileHeight;

    woodenBox.left = 64;
    woodenBox.top = 64;
    woodenBox.width = tileWidth;
    woodenBox.height = tileHeight;
}
