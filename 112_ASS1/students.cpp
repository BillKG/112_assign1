//
//  students.cpp
//  112_ASS1
//
//  Created by Filimoni Naisua on 31/08/2017.
//  Copyright © 2017 Filimoni Naisua. All rights reserved.
//

#include "students.hpp"

void students::set_lname(string lname)
{
    this-> lname=lname;
}
void students::set_fname(string fname)
{
    this-> fname=fname;
}
void students::set_age(int age)
{
    this -> age=age;
}
void students::set_phone(string phone)
{
    this -> phone=phone;
}

string students::get_lname()
{
    return lname;
}
string students::get_fname()
{
    return fname;
}
int students::get_age()
{
    return age;
}
string students::get_phone()
{
    return phone;
}

