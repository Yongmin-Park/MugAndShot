//
//  HighscoreView.hpp
//  Mugshot_SFML
//
//  Created by YMP on 31/01/2017.
//  Copyright © 2017 YMP. All rights reserved.
//

#ifndef HighscoreView_h

#include <string>
#include <stdio.h>
#include "SFML/Graphics.hpp"
#include "Score.h"

class HighscoreView{
public:
    sf::Font font;
    sf::Text txt_title;
    sf::Text txt_scores[5];
    sf::Text txt_datetime[5];
    
    float winWidth;
    float winHeight;
    
    HighscoreView(float width, float height);
    void draw(sf::RenderWindow &window);
    void setScores(vector<Score> scores);
};


#endif /* HighscoreView_hpp */
