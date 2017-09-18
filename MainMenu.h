//
//  MainMenu.hpp
//  Quiz_SFML
//
//  Created by YMP on 18/01/2017.
//  Copyright © 2017 YMP. All rights reserved.
//

#ifndef MainMenu_hpp
#define MainMenu_hpp
#define MAX_NUMBER_OF_ITEMS 3


#include <stdio.h>
#include "SFML/Graphics.hpp"

class MainMenu{
public:
    MainMenu(float width, float height);
    ~MainMenu();
    
    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex; }
    
    void showPlay();
    void showHighscore();
    
private:
    int selectedItemIndex;
    sf::Font font;
    sf::Text txt_title;
    sf::Text menu[MAX_NUMBER_OF_ITEMS];
    sf::Text txt_Play;
    sf::Text txt_Highscore;
    sf::Text txt_Exit;
};


#endif /* MainMenu_hpp */
