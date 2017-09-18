//
//  QuizView.hpp
//  Quiz_SFML
//
//  Created by YMP on 23/01/2017.
//  Copyright © 2017 YMP. All rights reserved.
//


#include <stdio.h>
#include <string>
#include <vector>
#include <random>

#include "SFML/Graphics.hpp"
#include "ResourcePath.hpp"
#include "Mugshot.h"
#include "Case.h"

using namespace std;

class QuizView{
public:
    
    int lvl = 100;
    int answerId;
    bool correct;
    int pressedNum = 1000;
    float winWidth;
    float winHeight;
    float gap_detail = 10;
    
    sf::Text txt_level;
    sf::Text txt_name;
    sf::Text txt_cases[3];
    sf::Text txt_detail[3];
    sf::Text txt_result;
    sf::Font font;
    sf::Texture mugImage;
    sf::Sprite mugSprite;
    sf::Text txt_correct;
    sf::Text txt_point;
    
    Mugshot givenMug;
    vector<Case> givenCases;
    vector<Case> quizCases;
    
    string name;
    string cases[3];
    string detail;
    string result;
    
    QuizView(float width, float height);
    
    void getPressedNum();
    bool isCorrect(int chosen);
    void draw(sf::RenderWindow &window);
    void setLvl(int level);
    void setMug(Mugshot mug);
    void setCaselist(vector<Case> cases);
    void setDetail();
    void pressNum(int num);
    void setMugCases(Mugshot mug, vector<Case> cases);
    void drawDetail(sf::RenderWindow &window, int num);
    void drawPoint(int point, sf::RenderWindow &window);
    
    //int GetPressedItem() (return selectedItemIndex);
    
};

