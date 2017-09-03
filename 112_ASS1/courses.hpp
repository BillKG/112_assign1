//
//  courses.hpp
//  112_ASS1
//
//  Created by Filimoni Naisua on 31/08/2017.
//  Copyright © 2017 Filimoni Naisua. All rights reserved.
//

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
public:
    void set_course(string);
    void set_prereq(string);
    void set_semester(int);
    
    string get_course();
    string get_prereq();
    int get_semester();
    
    void display_courses(courses student[], int size);

    
};

#endif /* courses_hpp */
