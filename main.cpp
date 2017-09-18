
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <ctime>

#include "SFML/Graphics.hpp"
#include "ResourcePath.hpp"
#include "Menu.h"
#include "MainMenu.h"
#include "Mugshot.h"
#include "Case.h"
#include "QuizView.h"
#include "ResultView.h"
#include "Score.h"
#include "HighscoreView.h"

using namespace std;

bool sortScore(const Score & s1, const Score & s2)
{
    if (s1.score != s2.score) return s1.score > s2.score;
    return s1.datetime < s2.datetime;
}

int myrandom_main (int i) { return std::rand()%i;}

int main(){
    //lvl ctrl vars
    int lvlcnt = 0;
    int cnt_correct = 0;
    bool showDetail = false;
    int pressNumMain = 999;
    bool isReplay = false;
    bool showHighscore = false;
    int pressNumResult = 888;
    bool isFileWrote = false;
    
    Score tmp_score;
    vector<Score> scores;
    
    time_t time_now = time(0);
    char* time_info;
    string str_time;
    
    sf::RenderWindow window(sf::VideoMode(1000, 600), "Mug & shot");
    sf::RectangleShape blankBg = sf::RectangleShape(sf::Vector2f(window.getSize().x, window.getSize().y));
    blankBg.setPosition(0, 0);
    
    //Menu mainMenu(window.getSize().x, window.getSize().y);
    MainMenu mainMenu(window.getSize().x, window.getSize().y);
    vector<Mugshot> mugs(10);
    vector<Case> cases(15);
    
    //mug file reading
    string line_mug;
    string dummy;
    
    ifstream f_mugs(resourcePath() + "idMugCases.txt");
    for(int i = 0;i<10;i++){
        //cin >> mugs.at(i).mugId;
        mugs.at(i).mugId = i+1;
        getline(f_mugs, dummy);
        getline(f_mugs, mugs.at(i).name);
        mugs.at(i).imageName = string(to_string(mugs.at(i).mugId) + "." + mugs.at(i).name + ".jpg");
        getline(f_mugs, mugs.at(i).str_case);
        printf("name: %s\n", mugs.at(i).name.c_str());
        cout << mugs.at(i).imageName + ", ";
        cout << mugs.at(i).str_case + "\n";
    }
    f_mugs.close();
    
    ifstream f_details(resourcePath() + "mugDetails.txt");
    for(int i = 0;i<10;i++){
        getline(f_details, dummy);
        getline(f_details, mugs.at(i).detail[0]);
        getline(f_details, mugs.at(i).detail[1]);
        getline(f_details, mugs.at(i).detail[2]);
        getline(f_details, dummy);
        cout << "d0: " + mugs.at(i).detail[0] + "\n";
        cout << "d1: " + mugs.at(i).detail[1] + "\n";
        cout << "d2: " + mugs.at(i).detail[2] + "\n";
    }
    f_details.close();
    
    ifstream f_cases(resourcePath() + "allCases.txt");
    for(int i = 0;i<15;i++){
        cases.at(i).caseId = i+1;
        getline(f_cases, dummy);
        getline(f_cases, cases.at(i).str_case);
        cout<<to_string(cases.at(i).caseId) + ": "  + cases.at(i).str_case + "\n";
    }
    f_cases.close();
    
    
    
    //ran shuffle
    auto engine = std::default_random_engine{};
    shuffle(begin(mugs), end(mugs), engine);
    srand(unsigned(time(NULL)));
    random_shuffle(mugs.begin(), mugs.end(), myrandom_main);
    
    //ten temps
    QuizView quiz_tmp0(window.getSize().x, window.getSize().y);
    random_shuffle(mugs.begin(), mugs.end(), myrandom_main);
    QuizView quiz_tmp1(window.getSize().x, window.getSize().y);
    random_shuffle(mugs.begin(), mugs.end(), myrandom_main);
    QuizView quiz_tmp2(window.getSize().x, window.getSize().y);
    random_shuffle(mugs.begin(), mugs.end(), myrandom_main);
    QuizView quiz_tmp3(window.getSize().x, window.getSize().y);
    random_shuffle(mugs.begin(), mugs.end(), myrandom_main);
    QuizView quiz_tmp4(window.getSize().x, window.getSize().y);
    random_shuffle(mugs.begin(), mugs.end(), myrandom_main);
    QuizView quiz_tmp5(window.getSize().x, window.getSize().y);
    random_shuffle(mugs.begin(), mugs.end(), myrandom_main);
    QuizView quiz_tmp6(window.getSize().x, window.getSize().y);
    random_shuffle(mugs.begin(), mugs.end(), myrandom_main);
    QuizView quiz_tmp7(window.getSize().x, window.getSize().y);
    random_shuffle(mugs.begin(), mugs.end(), myrandom_main);
    QuizView quiz_tmp8(window.getSize().x, window.getSize().y);
    random_shuffle(mugs.begin(), mugs.end(), myrandom_main);
    QuizView quiz_tmp9(window.getSize().x, window.getSize().y);
    vector<QuizView> quizV;
    random_shuffle(mugs.begin(), mugs.end(), myrandom_main);
    
    //ten time
    for(int i = 0;i<10;i++){
        random_shuffle(cases.begin(), cases.end(), myrandom_main);
        switch (i){
            case 0:
                quiz_tmp0.setMugCases(mugs.at(i), cases);
                quizV.push_back(quiz_tmp0);
                break;
            case 1:
                quiz_tmp1.setMugCases(mugs.at(i), cases);
                quizV.push_back(quiz_tmp1);
                break;
            case 2:
                quiz_tmp2.setMugCases(mugs.at(i), cases);
                quizV.push_back(quiz_tmp2);
                break;
            case 3:
                quiz_tmp3.setMugCases(mugs.at(i), cases);
                quizV.push_back(quiz_tmp3);
                break;
            case 4:
                quiz_tmp4.setMugCases(mugs.at(i), cases);
                quizV.push_back(quiz_tmp4);
                break;
            case 5:
                quiz_tmp5.setMugCases(mugs.at(i), cases);
                quizV.push_back(quiz_tmp5);
                break;
            case 6:
                quiz_tmp6.setMugCases(mugs.at(i), cases);
                quizV.push_back(quiz_tmp6);
                break;
            case 7:
                quiz_tmp7.setMugCases(mugs.at(i), cases);
                quizV.push_back(quiz_tmp7);
                break;
            case 8:
                quiz_tmp8.setMugCases(mugs.at(i), cases);
                quizV.push_back(quiz_tmp8);
                break;
            case 9:
                quiz_tmp9.setMugCases(mugs.at(i), cases);
                quizV.push_back(quiz_tmp9);
                break;
        }
        quizV.at(i).setLvl(i+1);
    }
    
    //result view init
    ResultView resultView(window.getSize().x, window.getSize().y);
    
    //readfile result.txt
    string str_score;
    string tmp_time;
    fstream f_highscore1("result.txt");
    while(getline(f_highscore1, str_score)){
        if(str_score == "" || str_score == "\n"){//ad hoc
        }
        else{
            cout<< "\n getline score: " + str_score + "\n";
            tmp_score.score = stoi(str_score);
            getline(f_highscore1, tmp_time);
            cout<< "\n getline time: " + tmp_time + "\n";
            tmp_score.datetime = tmp_time;
            scores.push_back(tmp_score);
        }
    }
    f_highscore1.close();
    sort(scores.begin(), scores.end(), sortScore);
    //read end
    
    //HighScore view init
    HighscoreView highscoreV(window.getSize().x, window.getSize().y);
    if(scores.size() != 0){
        highscoreV.setScores(scores);
    }
    
    
//
    while (window.isOpen()){//main loop
        
        sf::Event event;
        
        if(isReplay == true){
            lvlcnt = 1;
            cnt_correct = 0;
            random_shuffle(mugs.begin(), mugs.end(), myrandom_main);
            random_shuffle(cases.begin(), cases.end(), myrandom_main);
            for(int i = 0;i<10;i++){
                quizV.at(i).setMugCases(mugs.at(i), cases);
            }
            random_shuffle(quizV.begin(), quizV.end(), myrandom_main);
            isReplay = false;
            isFileWrote = false;
        }
        fstream f_highscore3("result.txt");
        while (window.pollEvent(event)){
            switch (event.type){
                case sf::Event::KeyReleased:
                    if(lvlcnt == 0){
                        switch (event.key.code){
                            case sf::Keyboard::Up:
                                mainMenu.MoveUp();
                                break;

                            case sf::Keyboard::Down:
                                mainMenu.MoveDown();
                                break;
                                
                            case sf::Keyboard::Return:
                                switch (mainMenu.GetPressedItem()){
                                    case 0:
                                        std::cout << "Play.\n" << std::endl;
                                        lvlcnt++;
                                        break;
                                    case 1:
                                        std::cout << "Show Highscore\n" << std::endl;
                                        scores.clear();
                                        while(getline(f_highscore3, str_score)){
                                            if(str_score == ""){//ad hoc
                                            }
                                            else{
                                                cout<< "\n getline score: " + str_score + "\n";
                                                tmp_score.score = stoi(str_score);
                                                getline(f_highscore3, tmp_time);
                                                cout<< "\n getline time: " + tmp_time + "\n";
                                                tmp_score.datetime = tmp_time;
                                                scores.push_back(tmp_score);
                                            }
                                        }
                                        f_highscore3.close();
                                        sort(scores.begin(), scores.end(), sortScore);
                                        if(scores.size() != 0){
                                            highscoreV.setScores(scores);
                                        }
                                        showHighscore = true;
                                        break;
                                    case 2:
                                        window.close();
                                        break;
                                }
                                break;
                        }
                    }
                    else if(1<=lvlcnt && lvlcnt <= 10 && showDetail == false){
                        switch(event.key.code){
                            case sf::Keyboard::Num1:
                                //                            quizV.pressNum(1);
                                cout<<"1 pressed\n";
                                pressNumMain = 1;
                                break;
                            case sf::Keyboard::Num2:
                                //                            quizV.pressNum(2);
                                cout<<"2 pressed\n";
                                pressNumMain = 2;
                                break;
                            case sf::Keyboard::Num3:
                                //                            quizV.pressNum(3);
                                cout<<"3 pressed\n";
                                pressNumMain = 3;
//                              quizV.at(lvlcnt).pressNum(3);
                                break;
                            case sf::Keyboard::A:
                                cout<<"A pressed\n";
                                break;
                        }
                        showDetail = true;
                    }
                    else if(showDetail == true){
                        cout<<"show?";
                        if(quizV.at(lvlcnt-1).correct){
                            cnt_correct += 1;
                        }
                        
                        cout<<"\n\n Current point: " + to_string(cnt_correct);
                        switch(event.key.code){
                            case sf::Keyboard::Return:
                                cout<<"enter pressed";
                                showDetail = false;
                                lvlcnt+=1;
                                break;
                        }
                    }
                    else if(10 < lvlcnt){
                        fstream f_highscore4("result.txt");
                        switch(event.key.code){
                            case sf::Keyboard::Num1:
                                cout<< "\n 1. Replay pressed\n";
                                isReplay = true;
                                break;
                            case sf::Keyboard::Num2:
                                cout<< "\n 2. Highscore pressed\n";
                                scores.clear();
                                while(getline(f_highscore4, str_score)){
                                    if(str_score == ""){//ad hoc
                                    }
                                    else{
                                        cout<< "\n getline score: " + str_score + "\n";
                                        tmp_score.score = stoi(str_score);
                                        getline(f_highscore4, tmp_time);
                                        cout<< "\n getline time: " + tmp_time + "\n";
                                        tmp_score.datetime = tmp_time;
                                        scores.push_back(tmp_score);
                                    }
                                }
                                f_highscore4.close();
                                sort(scores.begin(), scores.end(), sortScore);
                                if(scores.size() != 0){
                                    highscoreV.setScores(scores);
                                }
                                showHighscore = true;
                                pressNumResult = 2;
                                break;
                            case sf::Keyboard::Num3:
                                cout<< "\n 3. Exit\n";
                                window.close();
                                break;
                        }
                    }
                    if(11 == lvlcnt && isFileWrote == false){//file
                        
                        
                        time_info = ctime(&time_now);
                        tmp_score.score = cnt_correct;
                        string tmpStrTime(time_info);
                        tmp_score.datetime = tmpStrTime;
                
                        scores.push_back(tmp_score);
                        
                        //sort
                        sort(scores.begin(), scores.end(), sortScore);
                        
//                        resultView.setTime(to_string(*time_info));
                        fstream f_highscore2("result.txt");/////highscore File
                        
                        for(int i = 0;i < scores.size();i++){
                            f_highscore2 << scores.at(i).score;
                            f_highscore2 << "\n";
                            f_highscore2 << scores.at(i).datetime;
                            f_highscore2 << "\n";
                            printf("\nsize : %lu", scores.size());
                        }
                        f_highscore2.close();
                        
                        isFileWrote = true;
                    }
                    break;
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }
        
        window.clear();
        
        window.draw(blankBg);
        
        if(showHighscore == true){
            highscoreV.draw(window);
        }
        else if(lvlcnt == 0){
            mainMenu.draw(window);
        }
        else if(1<=lvlcnt && lvlcnt <= 10){
            if(showDetail == true){
                quizV.at(lvlcnt-1).drawDetail(window, pressNumMain);
                quizV.at(lvlcnt-1).drawPoint(1, window);
            }
            else{
                //cout<<quizV.at(lvlcnt-1).lvl;
                quizV.at(lvlcnt-1).txt_level.setString(to_string(lvlcnt));
                quizV.at(lvlcnt-1).draw(window);
            }
        }
        else if(10 < lvlcnt){
            resultView.setView(cnt_correct);
            resultView.draw(window);
        }
        
        
        window.display();
    }
}
