//***************************************************************
//NAME : FILIMONI NAISUA
//ID : S11124711
//Copyright © 2017 Filimoni Naisua. All rights reserved.
//***************************************************************

#include "cs_students.hpp"

void cs_students::set_passedcourses(string passedcourses)
{
    this -> passedcourses= passedcourses;
    
}
string cs_students::get_passedcourses()
{
    return passedcourses;
}

void cs_students::set_idpass(string idpass)
{
    this -> idpass=idpass;
}

string cs_students::get_idpass()
{
    return idpass;
}
