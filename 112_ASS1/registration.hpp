//***************************************************************
//NAME : FILIMONI NAISUA
//ID : S11124711
//Copyright © 2017 Filimoni Naisua. All rights reserved.
//***************************************************************

#ifndef registration_hpp
#define registration_hpp

#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>

using namespace std;

class registration
{
private:
    string rid;
    string currentregis;
    string found;
public:
    
    void set_rid(string);
    string get_rid();
    
    void set_currentregis(string);
    string get_currentregis();
    
    void set_found(string);
    string get_found();
};

#endif /* registration_hpp */
