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
#include "students.hpp"

class registration:public students
{
private:
    string currentregis;
public:
    void set_currentregis(string);
    string get_currentregis();
};

#endif /* registration_hpp */
