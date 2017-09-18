//
//  Score.hpp
//  Mugshot_SFML
//
//  Created by YMP on 25/01/2017.
//  Copyright © 2017 YMP. All rights reserved.
//

#ifndef Score_hpp
#define Score_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Score{
public:
    int score;
    string datetime;
    
    void set(int score, string str_datetime);
};

#endif /* Score_hpp */
