//
//  ResultView.hpp
//  Mugshot_SFML
//
//  Created by YMP on 24/01/2017.
//  Copyright © 2017 YMP. All rights reserved.
//

#ifndef ResultView_hpp
#define ResultView_hpp

#include <stdio.h>
#include <string>
#include <ctime>

#include "SFML/Graphics.hpp"

using namespace std;

class ResultView{
public:
    ResultView(float width, float height);
    
    float winWidth;
    float winHeight;
    int totalPoint;
    int pressedNum;
    
    void draw(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    int GetPressedItem() { return selectedItemIndex; }
    
    void setView(int resultNum);
    void setTime(string str_time);
    
    int selectedItemIndex;
    sf::Font font;
    sf::Text txt_result;
    sf::Text menu[3];
    sf::Text txt_Replay;
    sf::Text txt_Highscore;
    sf::Text txt_Exit;
    sf::Text txt_time;
};


#endif /* ResultView_hpp */
