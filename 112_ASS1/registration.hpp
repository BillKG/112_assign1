//
//  registration.hpp
//  112_ASS1
//
//  Created by Filimoni Naisua on 31/08/2017.
//  Copyright © 2017 Filimoni Naisua. All rights reserved.
//

#ifndef registration_hpp
#define registration_hpp

#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;

class registration
{
private:
    string rid;
    string currentregis;
public:
    void set_rid(string);
    string get_rid();
    void set_currentregis(string);
    string get_currentregis();
};

#endif /* registration_hpp */
