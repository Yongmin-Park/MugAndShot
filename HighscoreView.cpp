//
//  HighscoreView.cpp
//  Mugshot_SFML
//
//  Created by YMP on 31/01/2017.
//  Copyright © 2017 YMP. All rights reserved.
//

#include <vector>
#include <string>

#include "HighscoreView.h"
#include "SFML/Graphics.hpp"
#include "ResourcePath.hpp"
#include "Score.h"

using namespace std;

HighscoreView:: HighscoreView(float width, float height){
    if (!font.loadFromFile(resourcePath() + "SFNSDisplay-Ultralight.otf")){
        // handle error
        printf("font loading failed");
    }

    winWidth = width;
    winHeight = height;
}

void HighscoreView::setScores(vector<Score> scores){
    txt_title.setFont(font);
    txt_title.setFillColor(sf::Color::Black);
    txt_title.setString("High Scores");
    txt_title.setCharacterSize(70);
    txt_title.setPosition(10, 10);
    int bound;
    if (scores.size() < 5) {
        bound = scores.size();
    }
    else{
        bound = 5;
    }
    for(int i = 0;i < bound;i++){
        txt_scores[i].setFont(font);
        txt_scores[i].setFillColor(sf::Color::Black);
        txt_scores[i].setString(to_string(i+1) + "- Score: " + to_string(scores.at(i).score) + " at " + scores.at(i).datetime);
        txt_scores[i].setPosition(winWidth/2, winHeight/(5+1) * i+1 + 70);
    }
}

void HighscoreView::draw(sf::RenderWindow &window){
    window.draw(txt_title);
    for(int i = 0; i < 5; i++){
        window.draw(txt_scores[i]);
    }
}
