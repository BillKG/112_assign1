//***************************************************************
//NAME : FILIMONI NAISUA
//ID : S11124711
//Copyright © 2017 Filimoni Naisua. All rights reserved.
//***************************************************************

#ifndef cs_students_hpp
#define cs_students_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class cs_students
{
private:
    string idpass;
    string passedcourses;
public:
    
    void set_idpass(string);
    string get_idpass();
    void set_passedcourses(string);
    string get_passedcourses();
};

#endif /* cs_students_hpp */
