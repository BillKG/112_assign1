//
//  main.cpp
//  112_ASS1
//
//  Created by Filimoni Naisua on 31/08/2017.
//  Copyright © 2017 Filimoni Naisua. All rights reserved.
//

#include "students.hpp"
#include "courses.hpp"
#include "registration.hpp"
#include "cs_students.hpp"


const int MAX_SIZE = 100;

void intro();
void discard_line(ifstream &in);
void displayall();
void display_courses();
void course_lookup(string c);

void open_coursestxt(ifstream& cstudent, courses* c1, int& tot_records);
void open_studenttxt( ifstream& rstudents,students* s2,int& tot_records);
void open_registrationtxt(ifstream& registers, registration* r1,int& tot_records);
void open_registrationtxt(ifstream& csflie, cs_students * cs1,int& tot_records);
//void readandset_stu(students &s2,int MAX_SIZE,string &gcourse);


int main()
{
    students caller;
    char choice;
    string course;
    
    intro();
    do
    {
        // system("cls");
        cout<<"\n\n\n\tMAIN MENU";
        cout<<"\n\n\t1. EXIT";
        cout<<"\n\n\t2. Display all students at USP";
        cout<<"\n\n\t3. Display all Courses offered at USP";
        cout<<"\n\n\t4. Display details of students";
        cout<<"\n\n\t5. Register a student into a course";
        cout<<"\n\n\t6. Display all registration";
        cout<<"\n\n\t7. Display number of semesters a student will take to complete all CS courses";
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
                display_courses();
                break;
            case '4':
                cout<<"\n\n\tEnter Course ID: "; cin>>course;
                course_lookup(course);
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

void discard_line(ifstream &in)
{
    char c;
    
    do
   	    in.get(c);
    while (c!='\n');
}

void displayall()
{
    students s1[MAX_SIZE],caller;
    ifstream rstudents;
    int tot_records=0;
    
    open_studenttxt(rstudents,s1,tot_records);
    caller.students::display_all(s1, tot_records);
}

void display_courses()
{
    courses c1[MAX_SIZE],caller;
    ifstream cstudent;
    int tot_records =0;
    
    open_coursestxt(cstudent, c1, tot_records);
    caller.courses::display_courses(c1, tot_records);
    
}

void course_lookup(string c)
{
    registration r1[MAX_SIZE];
    students s2[MAX_SIZE];
    ifstream registers, rstudents;
    int tot_records2;
    int tot_records1;
    
    open_studenttxt(rstudents,s2, tot_records1);
    open_registrationtxt(registers, r1,tot_records2);
    
    for(int i =0; i<tot_records2 ; i++)
    {
        if(r1[i].get_currentregis()==c)
        {
            r1[i].set_found(r1[i].get_rid());
            
            for(int i =0; i<tot_records1; i++)
            {
                if(r1[i].get_found()==s2[i].get_id())
                {
                    cout<<"\n\tRECORD(s) OF STUDENT DOING THIS COURSE\n";
                    cout<<"\n\tID"<<"\tLast Name"<<"\tFirst Name"<<"\tAGE"<<"\tPHONE";
                    cout<<"\n\t-----------------------------------------------------";
                    cout<<"\n\t"<<s2[i].get_id()<<"\t"<<s2[i].get_lname()<<"\t\t"<<s2[i].get_fname()<<"\t\t"<<s2[i].get_age()<<"\t"<<s2[i].get_phone()<<"\n"; //working but needs to fix if there are no students doing the course or if course enetered has no students registered under it.
                }
            }
        }
      
    }
}

void open_coursestxt(ifstream& cstudent, courses* c1, int& tot_records)
{
    cstudent.open("/Users/NAISUA/Desktop/txt_for_ass/Courses.txt");
    if(!cstudent)
    {
        cerr<<"File could not be opened"<<endl;
        system("PAUSE");
        exit(1);
    }
    
    else
    {
        discard_line(cstudent);
        
        int semester ;
        string course,prereq;
        
        tot_records=0;
        
        while(cstudent>>course>>prereq>>semester)
        {
            c1[tot_records].set_course(course);
            c1[tot_records].set_prereq(prereq);
            c1[tot_records].set_semester(semester);
            tot_records++;
        }
        
        cstudent.close();
    }
}

void open_studenttxt( ifstream& rstudents,students* s2,int& tot_records)
{
    rstudents.open("/Users/NAISUA/Desktop/txt_for_ass/Student.txt");
    
    if(!rstudents)
    {
        cerr<<"File could not be opened"<<endl;
        system("PAUSE");
        exit(1);
    }
    
    else
    {
        discard_line(rstudents);
        
        int age;
        string id,lname,fname,phone;
        
        tot_records=0;
        
        while(rstudents>>id>>lname>>fname>>age>>phone)
        {
            s2[tot_records].set_id(id);
            s2[tot_records].set_lname(lname);
            s2[tot_records].set_fname(fname);
            s2[tot_records].set_age(age);
            s2[tot_records].set_phone(phone);
            tot_records++;
        }
        
        rstudents.close();
    }

}

void open_registrationtxt(ifstream& registers, registration* r1,int& tot_records2)
{
    
    registers.open("/Users/NAISUA/Desktop/txt_for_ass/Registration.txt");
    
    
    if(!registers)
    {
        cerr<<"File could not be opened"<<endl;
        system("PAUSE");
        exit(1);
    }
    
    else
    {
        discard_line(registers);
        
        string id1,c1;
        
        tot_records2=0;
        
        while(registers>>id1>>c1)
        {
            r1[tot_records2].set_rid(id1);
            r1[tot_records2].set_currentregis(c1);
            tot_records2++;
        }
        registers.close();
    }

}

void open_registrationtxt(ifstream& csflie, cs_students * cs1,int& tot_records)
{
    csflie.open("/Users/NAISUA/Desktop/txt_for_ass/CSstudents.txt");
    
    
    if(!csflie)
    {
        cerr<<"File could not be opened"<<endl;
        system("PAUSE");
        exit(1);
    }
    
    else
    {
        discard_line(csflie);
        
        string cid,ccourse;
        
        tot_records=0;
        
        while(csflie>>cid>>ccourse)
        {
            cs1[tot_records].set_idpass(cid);
            cs1[tot_records].set_passedcourses(ccourse);
            tot_records++;
        }
        csflie.close();
    }
}

