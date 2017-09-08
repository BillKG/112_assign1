//
//  students.hpp
//  112_ASS1
//
//  Created by Filimoni Naisua on 31/08/2017.
//  Copyright © 2017 Filimoni Naisua. All rights reserved.
//

#ifndef students_hpp
#define students_hpp

#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;

//const int MAX_SIZE1 = 100;

class students
{
private:
    string id;
    string lname;
    string fname;
    int age;
    string phone;
    
public:
    void set_id(string);
    void set_lname(string);
    void set_fname(string);
    void set_age(int);
    void set_phone(string);
    
    string get_id();
    string get_lname();
    string get_fname();
    int get_age();
    string get_phone();
    
    void display_all(students* student, int& size);
    
};

#endif /* students_hpp */
