//
//  courses.cpp
//  112_ASS1
//
//  Created by Filimoni Naisua on 31/08/2017.
//  Copyright © 2017 Filimoni Naisua. All rights reserved.
//
#include <iostream>
#include "courses.hpp"

using namespace std;

void courses::set_course(string course)
{
    this -> course = course;
}
void courses::set_prereq(string prereq)
{
    this -> prereq = prereq;
}
void courses::set_semester(int semester)
{
    this -> semester= semester;
}

string courses::get_course()
{
    return course;
}

string courses::get_prereq()
{
    return prereq;
}

int courses::get_semester()
{
    return semester;
}

void courses::display_courses(courses student[], int size)
{
    cout<<"\n\tCOURSES AT USP\n";
    cout<<"\n\tCourse"<<"\tPrereq"<<"\tSemester\n";
    
    for(int i =0; i<size ; i++)
    {
        cout<<"\t"<<student[i].get_course()<<"\t"<<student[i].get_prereq()<<"\t\t"<<student[i].get_semester()<<"\n";
        
    }
    
}

