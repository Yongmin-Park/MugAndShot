//
//  Mugshot.hpp
//  Quiz_SFML
//
//  Created by YMP on 22/01/2017.
//  Copyright © 2017 YMP. All rights reserved.
//

#ifndef Mugshot_H
#define Mugshot_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Mugshot{
public:
    string name;
    int mugId;
    string imageName;
    string str_case;
    string detail[3];
    
    void setFromLine(string fline);
};

#endif
