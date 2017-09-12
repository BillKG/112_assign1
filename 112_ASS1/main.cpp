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
void displayall(students s1[],int tot_records ); //2
void display_courses( courses c1[MAX_SIZE], int tot_records); //3
void course_lookup(string c, registration r1[], int tot_records2, students s2[], int tot_records1); //4
void displaypersonal(int numid, students s2[], int tot_records1); //4
void register_student(string id, string course, courses c1[], int ctot_records, cs_students cs1[], int cstot_records, registration r1[], int rtot_records); //5
bool prereq_check(string id, string courser,courses c1[], int ctot_records,courses csingle, cs_students cs1[], int cstot_records); //5
bool sem_check(string courser ,courses csingle,courses c1[], int ctot_records, cs_students cs1[], int cstot_records); //5
bool already_registered(string id, string courser, registration r1[], int rtot_records);//5
bool alreadydone_course(string id, string course,cs_students csptxt[],int cstot_records); //5
bool donealllevel_check(string id, string course, courses c1[], int ctot_records, cs_students cs1[], int cstot_records); //5
bool enrollmentcounter(string id,registration r1[], int rtot_records); //5
void write_registrations(string id, string course); //5
void display_registrations(registration r1[], int rtot_records); //6
void display_semsters(string id,registration r1[], int rtot_records,cs_students cs1[], int cstot_records); //7

void discard_line(ifstream &in); //for reading files
void open_coursestxt(ifstream& cstudent, courses* c1, int& tot_records);
void open_studenttxt( ifstream& rstudents,students* s2,int& tot_records);
void open_registrationtxt(ifstream& registers, registration* r1,int& tot_records2);
void open_cstxt(ifstream& csflie, cs_students * cs1,int& tot_records);




int main()
{
    char choice;
    string course,id, courser;
    ifstream rstudents;
    
    //students txt
    students s1[MAX_SIZE];
    int stot_records=0;
    open_studenttxt(rstudents,s1,stot_records);
    
    //courses txt
    courses c1[MAX_SIZE], display;
    int ctot_records =0;
    open_coursestxt(rstudents, c1, ctot_records);
    
    //registration txt
    registration r1[MAX_SIZE];
    int rtot_records=0;
    open_registrationtxt(rstudents, r1,rtot_records);
    
    //cs students txt
    cs_students cs1[MAX_SIZE];
    int cstot_records=0;
    open_cstxt(rstudents, cs1, cstot_records);
    
    
    
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
        cout<<"\n\n\tSelect Your Option (1-7): ";cin>>choice;
        // system("cls");
        
        switch(choice)
        {
            case '1':
               cout<<"\n\n\tThanks for using course approval system\n\n\n";
                break;
            case '2':
                displayall(s1, stot_records);
                break;
            case '3':
                display_courses(c1, ctot_records);
                break;
            case '4':
               cout<<"\n\n\tEnter Course ID: ";cin>>course;
               while (course!="cs111"&& course !="cs112"&& course != "cs240"&& course !="cs241"&& course !="cs214"&& course !="cs215"&& course !="cs218"&& course !="cs310"&&course != "cs311"&&course !="cs317"&&course !="cs318"&&course !="cs324"&&course != "cs341"){
                    cout<<"\n\tIncorrect course entered.....re-enter course again: ";
                    cin>>course;
                }
                course_lookup(course, r1, rtot_records, s1, stot_records);
                break;
            case '5':
                display.courses::display_courses( c1, ctot_records);
                cout<<"\n\n\tEnter your ID: ";cin>>id;
                while (id!="s111"&& id !="s222"&& id != "s333"&& id !="s444")
                {
                    cout<<"\n\tIncorrect ID entered.....re-enter ID again: ";
                    cin>>id;
                }
                cout<<"\n\tEnter Course you would like to register to: ";cin>>courser;
                while (courser!="cs111"&& courser !="cs112"&& courser != "cs240"&& courser !="cs241"&& courser !="cs214"&& courser !="cs215"&& courser !="cs218"&& courser !="cs310"&&courser != "cs311"&&courser !="cs317"&&courser !="cs318"&&courser !="cs324"&&courser != "cs341"){
                    cout<<"\n\tIncorrect course entered.....re-enter course again: ";
                    cin>>courser;
                }
                register_student(id, courser, c1, ctot_records, cs1, cstot_records, r1, rtot_records);
                break;
            case '6':
                display_registrations(r1, rtot_records);
                break;
            case '7':
                cout<<"\n\n\tEnter your ID: ";cin>>id;
                while (id!="s111"&& id !="s222"&& id != "s333"&& id !="s444")
                {
                    cout<<"\n\tIncorrect ID entered.....re-enter ID again: ";
                    cin>>id;
                }
                display_semsters(id, r1, rtot_records, cs1, cstot_records);
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
    while (c !='\n');
}

void displayall(students s1[],int tot_records )
{
    students caller;
    caller.students::display_all(s1, tot_records);
}

void display_courses( courses c1[], int tot_records)
{
    courses caller;
    caller.courses::display_courses(c1, tot_records);
    
}

void course_lookup(string c, registration r1[], int tot_records2, students s2[], int tot_records1)
{
    registration rsingle[MAX_SIZE];
    string f_id[MAX_SIZE];
    int numid;
    bool norec= false;
    
    for(int i =0; i<tot_records2 ; i++)
    {
        if(r1[i].get_currentregis()==c)
        {
            
        }
    }
    
        cout<<"\n\tRECORD(s) OF STUDENT DOING THIS COURSE\n";
        cout<<"\n\tID"<<"\tLast Name"<<"\tFirst Name"<<"\tAGE"<<"\tPHONE";
        cout<<"\n\t-----------------------------------------------------";
    
    
    for(int i =0; i<tot_records2 ; i++)
    {
        if(r1[i].get_currentregis()==c)
        {
            rsingle[i].set_found(r1[i].get_rid());
            
            if(rsingle[i].get_found() == "s111")
            {
                numid=1;
                displaypersonal( numid,  s2,  tot_records1);
                norec= true;
                
            }
            else if(rsingle[i].get_found() == "s222")
            {
                numid=2;
                displaypersonal( numid,  s2,  tot_records1);
                norec= true;
            }
            else if(rsingle[i].get_found() == "s333")
            {
                numid=3;
                displaypersonal( numid,  s2,  tot_records1);
                norec= true;
            }
            else
            {
                numid=4;
                displaypersonal( numid,  s2,  tot_records1);
                norec= true;
            }
        }
        else
        {
            if(i==tot_records2-1 && norec==0)
            {
            cout<<"\n\t\t\t   NO RECORDS :(";
            }
        }
    }
}

void open_coursestxt(ifstream& cstudent, courses* c1, int& tot_records)
{
    cstudent.open("/Users/NAISUA/Desktop/txt_for_ass/Courses.txt");
    if(!cstudent)
    {
        cerr<<"File could not be opened4"<<endl;
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
        cerr<<"File could not be opened1"<<endl;
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
        cerr<<"File could not be opened2"<<endl;
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

void open_cstxt(ifstream& csflie, cs_students * cs1,int& tot_records)
{
    csflie.open("/Users/NAISUA/Desktop/txt_for_ass/CSstduents.txt");
    
    
    if(!csflie)
    {
        cerr<<"File could not be opened3"<<endl;
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

void register_student(string id, string courser, courses c1[], int ctot_records, cs_students cs1[], int cstot_records, registration r1[], int rtot_records)
{
    courses csingle;
    
    bool one, two, three, four, five, six;
    
    
    six=enrollmentcounter(id, r1, rtot_records);
    five=donealllevel_check( id, courser, c1, ctot_records, cs1, cstot_records);
    two=sem_check(courser, csingle, c1, ctot_records, cs1, cstot_records);
    four=prereq_check(id, courser, c1, ctot_records, csingle, cs1, cstot_records);
    one=already_registered( id,  courser,  r1,  rtot_records);
    three=alreadydone_course(id, courser, cs1, cstot_records);
    
    if (one== 0 && two== 1 && three== 0 && four== 1 && five== 1 && six== 0)
    {
        cout<<"\n\n\tREGISTRATION APPROVED!!!";
        write_registrations(id, courser);
    }
    else
    {
        cout<<"\n\n\tREGISTRATION NOT APPROVED!!!";
    }
    
    
    
}

bool prereq_check(string id, string courser,courses c1[], int ctot_records,courses csingle, cs_students cs1[], int cstot_records)
{
    bool pass = true;
    string reason3;
    
    for(int i =0; i < ctot_records; i++)
    {
        if (c1[i].get_course()==courser)
        {
            csingle.set_foundpreq(c1[i].get_prereq());
        }
    }
    for(int i = 0; i<cstot_records; i++)
        {
        if(csingle.get_foundpreq() == cs1[i].get_passedcourses() || csingle.get_foundpreq() == "NA")
            {
            if(id == cs1[i].get_idpass())
                {
                    pass= true;
                    cout<<"\n\tPREREQ PASSED :)";
                    return pass;
                }
            }
        else
            {
            if (i==cstot_records-1)
                {
                    cout<<"\n\tSTUDENT HASN'T PASSED OR DONE THE PREREQ COURSE "<<csingle.get_foundpreq()<<" THEREFORE STUDENT IS NOT ALLOWED TO REGISTER :(";
                    pass= false;
                }
            }
            
        }
return pass;
}

bool sem_check(string courser ,courses csingle,courses c1[], int ctot_records, cs_students cs1[], int cstot_records)
{
    bool semcheck = false;
    int semester = 2 | 0;
    int end;
    for(int i=0; i<ctot_records; i++)
        {
            if(courser==c1[i].get_course())
            {
                end=i;
                csingle.set_foundsem(c1[i].get_semester());
                if((semester==csingle.get_foundsem() || csingle.get_foundsem()==0)&& courser==c1[i].get_course())
                {
                    cout<<"\n\tcourse is provided in semester 2 :) ";
                    semcheck=true;
                    return semcheck;
                }
                else
                {
                    if(i==end)
                    {
                    cout<<"\n\tcourse is only provided in semester "<<csingle.get_foundsem()<<" :(";
                    semcheck=false;
                    }
                }
            
            }
        }
    return semcheck;
}

bool already_registered(string id, string courser, registration r1[], int rtot_records)
{
    bool registered = true;
    
    for(int i= 0; i< rtot_records; i++)
    {
        
        if(id==r1[i].get_rid() && courser== r1[i].get_currentregis())
        {
            cout<<"\n\tALREADY REGISTERED!!! :(";
            registered=true;
            return registered;
        }
        else
        {
            if(i==rtot_records-1)
            {
                cout<<"\n\tNOT ALREADY REGISTERED :)";
                registered= false;
            }
        }
        
    }
    
    
    return registered;
}

bool donealllevel_check(string id, string course, courses c1[], int ctot_records, cs_students cs1[], int cstot_records)
{
    bool done=true;
    char level= course[2];
    int levelcounter=0;
    
    char levelpassc[ctot_records];
    
    for(int i= 0; i<ctot_records; i++)
    {
        levelpassc[i]=c1[i].get_course()[2];
    }
    
    for(int i=0;i<cstot_records;i++)
    {
        if(level=='2')
        {
            if (id==cs1[i].get_idpass() && cs1[i].get_passedcourses()[2]=='1')
            {
                levelcounter++;
            }
        }
        
        else if(level=='3')
        {
            if (id==cs1[i].get_idpass() && cs1[i].get_passedcourses()[2]=='2')
            {
                levelcounter++;
            }
        }
        
        else
            levelcounter=0;
        
    }
    
    
    
    for(int i=0;i<cstot_records;i++)
    {
        if(level=='2')
        {
            if (levelcounter==2)
            {
                cout<<"\n\tall 100 levels compeleted :)";
                done=true;
                return done;
            }
            
            else
            {
                cout<<"\n\tall 100 levels not compeleted :(";
                done=false;
                return done;
            }
        }
        
        if(level=='3')
        {
            if (levelcounter==5)
            {
                cout<<"\n\tall 200 levels compeleted :)";
                done=true;
                return done;
            }
            
            else
            {
                cout<<"\n\tall 200 levels not compeleted :(";
                done=false;
                return done;
            }
        }
        
        else
        {
            if(levelcounter==0)
            {
                done=true;
                cout<<"\n\t100 level :)";
                return done;
            }
        }
    }
    return done;
}

bool enrollmentcounter(string id,registration r1[], int rtot_records)
{
    const int num =2;
    int wili=0;
    bool counter = true;
    ifstream rstudents;
    
    open_registrationtxt(rstudents, r1,rtot_records);
    
    for(int i =0; i<rtot_records; i++)
    {
        if (id==r1[i].get_rid())
        {
            wili=wili+1;
        }
    }
    
      if (wili==num)
        {
            cout<<"\n\tREGISTRATION LIMIT REACHED :(";
            counter = true;
            return counter;
        }
    else
        {
            cout<<"\n\tREGISTRATION FOR "<<2-wili<<" COURSE(S) CAN BE DONE :)";
            counter = false;
            return counter;
        }
    
    
    
    
    return counter;
}

bool alreadydone_course(string id, string course,cs_students csptxt[],int cstot_records)
{
    bool done= true;
    
    for(int i=0;i<cstot_records;i++)
    {
        if(id==csptxt[i].get_idpass() && course== csptxt[i].get_passedcourses())
        {
            cout<<"\n\tSTUDENT HAS ALREADY DONE THIS COURSE :(";
            done=true;
            return done;
        }
        
        else
        {
            if(i==cstot_records-1)
            {
                cout<<"\n\tCOURSE NOT DONE YET :) ";
                done= false;
            }
        }
        
    }
    
    return done;
}


void write_registrations(string id, string course)
{
    ofstream rstudent;
    
    rstudent.open("/Users/NAISUA/Desktop/txt_for_ass/Registration.txt", ofstream::out | ofstream:: app);
    
    rstudent<<"\n"<<id<<" "<<course;
    
    rstudent.close();
    
}

void display_registrations(registration r1[], int rtot_records)
{
    ifstream rstudents;
    
    open_registrationtxt(rstudents, r1,rtot_records);
    
    cout<<"\n\tREGISTRATIONS\n";
    cout<<"\n\tID"<<"    COURSES\n";
    cout<<"\t-------------\n";
    
    for(int i =0; i<rtot_records ; i++)
    {
        cout<<"\t"<<r1[i].get_rid()<<"\t"<<r1[i].get_currentregis()<<"\n";
        
    }
}


void displaypersonal(int numid, students s2[], int tot_records1)
{
    
    cout<<"\n\t"<<s2[numid-1].get_id()<<"\t"<<s2[numid-1].get_lname()<<"\t\t"<<s2[numid-1].get_fname()<<"\t\t"<<s2[numid-1].get_age()<<"\t"<<s2[numid-1].get_phone()<<"";
    
}

void display_semsters(string id,registration r1[], int rtot_records,cs_students cs1[], int cstot_records)
{
    int counterr=0;
    int countercs=0;
    const int tot_courses=13;
    
    
    for(int i=0; i<rtot_records; i++)
    {
        if(id==r1[i].get_rid())
        {
            counterr++;
        }
        
    }
    for(int i=0; i<cstot_records; i++)
    {
        if(id==cs1[i].get_idpass())
        {
            countercs++;
        }
    }
    
    cout<<"\n\tYou have "<<tot_courses-(counterr+countercs)<<" semster(s) to complete your program. GOOD LUCK :)";
    
}



