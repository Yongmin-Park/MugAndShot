//
//  MainMenu.cpp
//  Quiz_SFML
//
//  Created by YMP on 18/01/2017.
//  Copyright © 2017 YMP. All rights reserved.
//

#include "MainMenu.h"
#include "SFML/Graphics.hpp"
#include "ResourcePath.hpp"

MainMenu::MainMenu(float width, float height){
    if (!font.loadFromFile(resourcePath() + "SFNSDisplay-Ultralight.otf")){
        // handle error
        printf("font loading failed");
    }
    
    txt_title.setFont(font);
    txt_title.setFillColor(sf::Color::Black);
    txt_title.setString("Mug & Shot");
    txt_title.setPosition(sf::Vector2f(25, 20));
    txt_title.setCharacterSize(70);
    
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Red);
    menu[0].setString("Play");
    menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));
    
    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::Black);
    menu[1].setString("High Scores");
    menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));
    
    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::Black);
    menu[2].setString("Exit");
    menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
    
    selectedItemIndex = 0;
}

MainMenu::~MainMenu(){
}

void MainMenu::draw(sf::RenderWindow &window){
    window.draw(txt_title);
    for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++){
        window.draw(menu[i]);
    }
}

void MainMenu::MoveUp()
{
    if (selectedItemIndex - 1 >= 0)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::Black);
        selectedItemIndex--;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void MainMenu::MoveDown()
{
    if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
        menu[selectedItemIndex].setFillColor(sf::Color::Black);
        selectedItemIndex++;
        menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}
