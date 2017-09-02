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
void displayall();
//void discard_line(ifstream &in);


int main()
{
    char choice;
    
    intro();
    do
    {
        // system("cls");
        cout<<"\n\n\n\tMAIN MENU";
        cout<<"\n\n\t1. EXIT";
        cout<<"\n\n\t2. Display all students at USP";
        cout<<"\n\n\t2. Display all Courses offered at USP";
        cout<<"\n\n\t3. Display details of students";
        cout<<"\n\n\t4. Register a student into a course";
        cout<<"\n\n\t5. Display all registration";
        cout<<"\n\n\t6. Display number of semesters a student will take to complete all CS courses";
        cout<<"\n\n\tSelect Your Option (1-6) ";cin>>choice;
        // system("cls");
        switch(choice)
        {
            case '1':
               cout<<"\n\n\tThanks for using course approval system\n\n\n";
                break;
            case '2':
               displayall();
                break;
            case '3':
               
                break;
            case '4':
                
                break;
            case '5':
               
            case '6':
               
                break;
            case '7':
               
                break;
            case '8':
                break;
            default :cout<<"\a";
        }
        cin.ignore();
        cin.get();
    }while(choice!='1');
    return 0;
}












































void intro()
{
    cout<<"\n\n\n\tCOURSE";
    cout<<"\n\tAPPROVAL SYSTEM";
    cout<<"\n\tFOR USP CS STUDENTS";
}

void displayall()
{
    students student[MAX_SIZE],caller;
    ifstream rstudents;
    int tot_records=0;
    
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
        }
        
        rstudents.close();
    }
    
    caller.students::display_all(student, tot_records);
}


