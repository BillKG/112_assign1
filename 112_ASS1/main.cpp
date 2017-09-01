//
//  main.cpp
//  112_ASS1
//
//  Created by Filimoni Naisua on 31/08/2017.
//  Copyright © 2017 Filimoni Naisua. All rights reserved.
//

#include "students.hpp"
#include "courses.hpp"


const int MAX_SIZE = 100;

void intro();
//void discard_line(ifstream &in);


int main()
{
    students student[MAX_SIZE],caller;
    courses course[MAX_SIZE];
    ifstream rstudents;
    char choice;
    int tot_records=0;
   
   
    
    //reading student.txt
    rstudents.open("/Users/NAISUA/Desktop/txt_for_ass/Student.txt");
    
    if(!rstudents)
    {
        cerr<<"File could not be opened"<<endl;
        system("PAUSE");
        exit(1);
    }

    else
    {
        caller.students::discard_line(rstudents);
        
        int age;
        string id,lname,fname,phone;
        
        tot_records=0;
        
        while(rstudents>>id>>lname>>fname>>age>>phone)
        {
            student[tot_records].set_id(id);
            student[tot_records].set_lname(lname);
            student[tot_records].set_fname(fname);
            student[tot_records].set_age(age);
            student[tot_records].set_phone(phone);
            tot_records++;
            
            cout<<"\t"<<student[tot_records].get_id()<<"\t"<<student[tot_records].get_lname()<<"\t"<<student[tot_records].get_fname()<<"\t"<<student[tot_records].get_age()<<"\t"<<student[tot_records].get_phone()<<"\n";
            cout<<"\n\n"<<tot_records;
        }
        
        rstudents.close();
    }

    
    
    
    intro();
    // system("cls");
    cout<<"\n\n\n\tMAIN MENU";
    cout<<"\n\n\t01. EXIT";
    cout<<"\n\n\t02. Display all students at USP";
    cout<<"\n\n\t02. Display all Courses offered at USP";
    cout<<"\n\n\t03. Display details of students";
    cout<<"\n\n\t04. Register a student into a course";
    cout<<"\n\n\t05. Display all registration";
    cout<<"\n\n\t06. Display number of semesters a student will take to complete all CS courses";
    cout<<"\n\n\tSelect Your Option (1-6) ";
    cin>>choice;

    if (choice==02 ||choice== 2)
    {
        caller.students::display_all(student, tot_records);
    }
    
    
    
    
    
    
    system ("PAUSE");
    return 0;
}

void intro()
{
    cout<<"\n\n\n\tCOURSE";
    cout<<"\n\tAPPROVAL SYSTEM";
    cout<<"\n\tFOR USP CS STUDENTS";
}


