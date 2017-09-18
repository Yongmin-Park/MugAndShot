//
//  ResultView.cpp
//  Mugshot_SFML
//
//  Created by YMP on 24/01/2017.
//  Copyright © 2017 YMP. All rights reserved.
//
#include <string>

#include "ResultView.h"
#include "ResourcePath.hpp"

using namespace std;

ResultView:: ResultView(float width, float height){
    if (!font.loadFromFile(resourcePath() + "SFNSDisplay-Ultralight.otf")){
        // handle error
        printf("font loading failed");
    }
    
    winWidth = width;
    winHeight = height;
}

void ResultView::setView(int resultNum){
    totalPoint = resultNum;
    
    txt_result.setFont(font);
    txt_result.setFillColor(sf::Color::Black);
    txt_result.setPosition(50, 50);
    txt_result.setString("Total Score: " + to_string(totalPoint));
    txt_result.setCharacterSize(70);
    
    //1.
    txt_Replay.setFont(font);
    txt_Replay.setFillColor(sf::Color::Black);
    txt_Replay.setString("1. Replay");
    txt_Replay.setPosition(winWidth/2, winHeight/(3+1) * 1);
    
    //2.
    txt_Highscore.setFont(font);
    txt_Highscore.setFillColor(sf::Color::Black);
    txt_Highscore.setString("2. Highscore");
    txt_Highscore.setPosition(winWidth/2, winHeight/(3+1) * 2);
    
    //3.
    txt_Exit.setFont(font);
    txt_Exit.setFillColor(sf::Color::Black);
    txt_Exit.setString("3. Exit");
    txt_Exit.setPosition(winWidth/2, winHeight/(3+1) * 3);
}

//void ResultView::setTime(string str_time){
//    txt_time.setFont(font);
//    txt_time.setFillColor(sf::Color::Black);
//    txt_time.setString("Time/Date: " + str_time);
//    txt_time.setPosition(50, winHeight * 0.8);
//    txt_time.setCharacterSize(40);
//}

void ResultView::draw(sf::RenderWindow &window){
    window.draw(txt_result);
    window.draw(txt_Replay);
    window.draw(txt_Highscore);
    window.draw(txt_Exit);
//    window.draw(txt_time);
}


