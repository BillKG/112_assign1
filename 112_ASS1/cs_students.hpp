//
//  cs_students.hpp
//  112_ASS1
//
//  Created by Filimoni Naisua on 31/08/2017.
//  Copyright © 2017 Filimoni Naisua. All rights reserved.
//

#ifndef cs_students_hpp
#define cs_students_hpp

#include <stdio.h>
#include "students.hpp"

class cs_students:public students
{
private:
    string passedcourses;
public:
    void set_passedcourses(string);
    string get_passedcourses();
};

#endif /* cs_students_hpp */
