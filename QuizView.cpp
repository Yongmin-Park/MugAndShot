//
//  QuizView.cpp
//  Quiz_SFML
//
//  Created by YMP on 23/01/2017.
//  Copyright © 2017 YMP. All rights reserved.
//

#include <string>
#include <algorithm>
#include <random>

#include "QuizView.h"
#include "SFML/Graphics.hpp"
#include "ResourcePath.hpp"
#include "Random.h"

using namespace std;

int myrandom (int i) { return std::rand()%i;}

QuizView:: QuizView(float width, float height){
    if (!font.loadFromFile(resourcePath() + "SFNSDisplay-Ultralight.otf")){
        // handle error
        printf("font loading failed");
    }
    
    winWidth = width;
    winHeight = height;
}

void QuizView::setMug(Mugshot mug){
    givenMug = mug;
}

void QuizView::setCaselist(vector<Case> cases){
}

void QuizView::setMugCases(Mugshot mug, vector<Case> cases){
    random_shuffle(givenCases.begin(), givenCases.end(), myrandom);
    
    givenMug = mug;
    givenCases = cases;
    
    if(!mugImage.loadFromFile(resourcePath() + givenMug.imageName)){
    }
    
    mugSprite.setTexture(mugImage);
    
    txt_name.setFont(font);
    txt_name.setFillColor(sf::Color::Black);
    txt_name.setString(givenMug.name);
    txt_name.setPosition(20, winHeight/2 + 70);
    txt_name.setCharacterSize(30);
    
    txt_level.setFont(font);
    txt_level.setFillColor(sf::Color::Black);
    txt_level.setString("Q1. " + to_string(this->lvl));
    txt_level.setPosition(10, 10);
    txt_level.setCharacterSize(23);
    
    mugSprite.setPosition(20, 50);
    
    //pick the answer case
    for(int i = 0;i<givenCases.size();i++){
        printf("\nmug: %d ?? case: %d\n", givenMug.mugId, givenCases.at(i).caseId);
        if(givenMug.mugId == givenCases.at(i).caseId){
            quizCases.push_back(givenCases.at(i));//push answer
            cout<<"\n caselist:1::" + to_string(quizCases.at(0).caseId) + quizCases.at(0).str_case;
            givenCases.erase(givenCases.begin()+i);
        }
    }
    cout<<"\n CorrCaseId::" + to_string(quizCases.at(0).caseId);
    
    quizCases.push_back(givenCases.at(1));
    quizCases.push_back(givenCases.at(2));
    
    random_shuffle(quizCases.begin(), quizCases.end(), myrandom);
    
    for(int i = 0;i<3;i++){
        txt_cases[i].setFont(font);
        txt_cases[i].setFillColor(sf::Color::Black);
        replace(quizCases.at(i).str_case.begin(), quizCases.at(i).str_case.end(), '*', '\n');//replace
        txt_cases[i].setString(to_string(i+1) + ". " + quizCases.at(i).str_case);
        txt_cases[i].setPosition(sf::Vector2f(winWidth/2, winHeight / (3 + 1) * i+1 +50));
        txt_cases[i].setCharacterSize(25);
    }
}

void QuizView::draw(sf::RenderWindow &window){
    txt_level.setString("Q1. " + to_string(this->lvl));
    window.draw(txt_level);
    window.draw(txt_name);
    for(int i = 0;i < 3;i++){
        window.draw(txt_cases[i]);
    }
    window.draw(mugSprite);
}

void QuizView::setLvl(int level){
    lvl = level;
}

void QuizView::drawDetail(sf::RenderWindow &window, int num){
    txt_level.setString(to_string(lvl) + ": Result & Case Details");
    
    for(int i = 0;i<3;i++){
        txt_detail[i].setFont(font);
        txt_detail[i].setFillColor(sf::Color::Black);
        txt_detail[i].setString(givenMug.detail[i]);
    }

    txt_detail[0].setPosition(winWidth*0.25, 10);
    txt_detail[0].setCharacterSize(23);
    
    txt_detail[1].setPosition(winWidth*0.25, 10 + gap_detail*4);
    txt_detail[1].setCharacterSize(20);
    
    txt_detail[2].setPosition(winWidth*0.25, 10 + gap_detail*5 + 30);
    txt_detail[2].setCharacterSize(12);
    
    txt_correct.setFont(font);
    txt_correct.setFillColor(sf::Color::Black);
    pressedNum = num;
    //printf("pressed: %d\n", pressedNum);
    cout<<"chosen: " + quizCases.at(pressedNum-1).str_case +"\n";
    if(quizCases.at(pressedNum-1).caseId == givenMug.mugId){
        correct = true;
    }
    else{
        correct = false;
    }
    
    if(correct == true){
        txt_correct.setString("Correct Answer.");
    }
    else{
        txt_correct.setString("Wrong Answer.");
    }
    txt_correct.setPosition(10, winHeight - 70 - 30);
    txt_correct.setCharacterSize(70);
    
    
    //draw
    window.draw(txt_level);
    for(int i = 0;i<3;i++){
        window.draw(txt_detail[i]);
    }
    window.draw(txt_correct);
    window.draw(mugSprite);
}

void QuizView::drawPoint(int point, sf::RenderWindow &window){
    txt_point.setFont(font);
    txt_point.setFillColor(sf::Color::Black);
    txt_point.setCharacterSize(50);
    txt_point.setPosition(winWidth/2, winHeight - 50);
    txt_point.setString("Press Enter to the Next");
    
    window.draw(txt_point);
}

void QuizView::pressNum(int num){
    pressedNum = num;
    
    quizCases.clear();
}

bool QuizView::isCorrect(int chosen){
    
    
}


