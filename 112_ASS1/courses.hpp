//***************************************************************
//NAME : FILIMONI NAISUA
//ID : S11124711
//Copyright © 2017 Filimoni Naisua. All rights reserved.
//***************************************************************

#ifndef courses_hpp
#define courses_hpp

#include <stdio.h>
#include <string>

using namespace std;

class courses
{
private:
    string course;
    string prereq;
    int semester;
    string foundpreq;
    int foundsem;
    
public:
    
    void set_foundpreq(string);
    void set_course(string);
    void set_prereq(string);
    void set_semester(int);
    void set_foundsem(int);
    
    string get_foundpreq();
    string get_course();
    string get_prereq();
    int get_semester();
    int get_foundsem();
    
    void display_courses(courses student[], int size);

    
};

#endif /* courses_hpp */
