//
//  registration.cpp
//  112_ASS1
//
//  Created by Filimoni Naisua on 31/08/2017.
//  Copyright © 2017 Filimoni Naisua. All rights reserved.
//

#include "registration.hpp"
#include <fstream>
#include "students.hpp"

void registration::set_currentregis(string currentregis)
{
    this-> currentregis= currentregis;
}
string registration::get_currentregis()
{
    return currentregis;
}

void registration::set_rid(string rid)
{
    this->rid=rid;
}
string registration::get_rid()
{
    return rid;
}

void registration::set_found(string found)
{
    this -> found = found;
}
string registration::get_found()
{
    return found;
}
