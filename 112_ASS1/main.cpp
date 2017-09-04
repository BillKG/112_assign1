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


const int MAX_SIZE = 100;

void intro();
void discard_line(ifstream &in);
//void displayall();
//void display_courses();
//void course_lookup();
void read_all(char choice);


int main()
{
    students caller;
    char choice;
    
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
                read_all(choice);
                break;
            case '3':
                read_all(choice);
                break;
            case '4':
                read_all(choice);
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

/*
void displayall()
{
    students s1[MAX_SIZE],caller;
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
        discard_line(rstudents);
        
        int age;
        string id,lname,fname,phone;
        
        tot_records=0;
        
        while(rstudents>>id>>lname>>fname>>age>>phone)
        {
            s1[tot_records].set_id(id);
            s1[tot_records].set_lname(lname);
            s1[tot_records].set_fname(fname);
            s1[tot_records].set_age(age);
            s1[tot_records].set_phone(phone);
            tot_records++;
        }
        
        rstudents.close();
    }
    
    caller.students::display_all(s1, tot_records);
}

void display_courses()
{
    courses c1[MAX_SIZE],caller;
    ifstream cstudent;
    int tot_records =0;
    
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
    
    caller.courses::display_courses(c1, tot_records);
    
}


void course_lookup()
{
    registration r1[MAX_SIZE];
    students s2[MAX_SIZE];
    ifstream registerstudents;
    int tot_records;
    
    registerstudents.open("/Users/NAISUA/Desktop/txt_for_ass/Registration.txt");
    
    
    if(!registerstudents)
    {
        cerr<<"File could not be opened"<<endl;
        system("PAUSE");
        exit(1);
    }
    
    else
    {
        discard_line(registerstudents);
        
        string id1,c1;
        
        tot_records=0;
        
        while(registerstudents>>id1>>c1)
        {
            r1[tot_records].set_rid(id1);
            r1[tot_records].set_currentregis(c1);
            tot_records++;
        }
        
        
        
        registerstudents.close();
    }

    for(int i =0; i<tot_records ; i++)
    {
        cout<<"\t"<<r1[i].get_rid()<<"\t"<<r1[i].get_currentregis()<<"\t\t\n";
        
 }
}
 */


void read_all(char choice)
{
    int tot_records=0;
    
    //for #2
    students s1[MAX_SIZE],caller;
    ifstream rstudents;
    
    //for #3
    courses c1[MAX_SIZE],caller2;
    ifstream cstudent;
    
    //for #4
    registration r1[MAX_SIZE];
    students s2[MAX_SIZE];
    ifstream registerstudents;

    
    
    if(choice=='2')
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
                s1[tot_records].set_id(id);
                s1[tot_records].set_lname(lname);
                s1[tot_records].set_fname(fname);
                s1[tot_records].set_age(age);
                s1[tot_records].set_phone(phone);
                tot_records++;
            }
        
            rstudents.close();
        }
         caller.students::display_all(s1, tot_records);
    
    }
    
    else if(choice =='3')
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
             caller2.courses::display_courses(c1, tot_records);
    }
    
    else if(choice=='4')
    {
        registerstudents.open("/Users/NAISUA/Desktop/txt_for_ass/Registration.txt");
        
        
        if(!registerstudents)
        {
            cerr<<"File could not be opened"<<endl;
            system("PAUSE");
            exit(1);
        }
        
        else
        {
            discard_line(registerstudents);
            
            string id1,c1;
            
            tot_records=0;
            
            while(registerstudents>>id1>>c1)
            {
                r1[tot_records].set_rid(id1);
                r1[tot_records].set_currentregis(c1);
                tot_records++;
            }
            
            
            
            registerstudents.close();
        }
        
        for(int i =0; i<tot_records ; i++)
        {
            cout<<"\t"<<r1[i].get_rid()<<"\t"<<r1[i].get_currentregis()<<"\t\t\n";
           
            
        }
        caller.students::display_all(s1, tot_records);

        
    }
        
        
}






