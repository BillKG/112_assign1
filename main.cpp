//***************************************************************
//NAME : FILIMONI NAISUA
//ID : S11124711
//Copyright © 2018 Filimoni Naisua. All rights reserved.
//***************************************************************

#include <iostream>
#include "model/course.h"
#include "model/cs_student.h"
#include "model/registration.h"
#include "model/student.h"
#include <fstream>


const int MAX_SIZE = 100;

//***************************************************************
//    	function declaration
//***************************************************************
void intro();
void displayAllStudents(student *s1, int tot_records);
void display_courses( course c1[MAX_SIZE], int tot_records);
void course_lookup(const std::string &c, registration r1[], int tot_records2, student s2[], int tot_records1);
void displayStudentInfo(int numid, student *s2, int tot_records1);
void register_student(const std::string &id, std::string courseId, course c1[], int ctot_records, cs_student cs1[], int cstot_records, registration r1[], int rtot_records);
bool prerequisiteCheck(const std::string &id, std::string courser, course *c1, int ctot_records, course csingle, cs_student *cs1, int cstot_records);
bool sem_check(const std::string &courser ,course csingle,course c1[], int ctot_records, cs_student cs1[], int cstot_records);
bool already_registered(const std::string &id, std::string courser, registration r1[], int rtot_records);
bool checkCourseCompletion(const std::string &id, std::string course, cs_student *csptxt, int cstot_records);
bool checkLevel(const std::string &id, std::string courseId, course *c1, int ctot_records, cs_student *cs1, int cstot_records);
bool checkEnrolledCourses(const std::string &id, registration *r1, int rtot_records);
void write_registrations(const std::string &id, std::string course);
void display_registrations(registration r1[], int rtot_records);
void displaySemester(const std::string &id, registration *r1, int rtot_records, cs_student *cs1, int cstot_records);
void discard_line(std::ifstream &in);
void readCourseFile(std::ifstream &cstudent, course *c1, int &tot_records);
void readStudentFile(std::ifstream& rstudents,student* s2,int& tot_records);
void readRegistrationFile(std::ifstream &registers, registration *r1, int &tot_records2);
void readCsStudentFile(std::ifstream &csflie, cs_student *cs1, int &tot_records);



//***************************************************************
//  DRIVER
//****************************************************************
int main()
{
    char choice;
    std::string courseId,id, courser;
    std::ifstream rstudents;

    //students txt
    student s1[MAX_SIZE];
    int stot_records=0;


    //courses txt
    course c1[MAX_SIZE], display;
    int ctot_records =0;


    //registration txt
    registration r1[MAX_SIZE];
    int rtot_records=0;


    //cs students txt
    cs_student cs1[MAX_SIZE];
    int cstot_records=0;

    readStudentFile(rstudents,s1,stot_records);
    readCourseFile(rstudents, c1, ctot_records);
    readRegistrationFile(rstudents, r1, rtot_records);
    readCsStudentFile(rstudents, cs1, cstot_records);

    intro();

    do
    {
        // system("cls");
        std::cout<<"\n\n\n\tMAIN MENU";
        std::cout<<"\n\n\t1. EXIT";
        std::cout<<"\n\n\t2. Display all students at USP";
        std::cout<<"\n\n\t3. Display all Courses offered at USP";
        std::cout<<"\n\n\t4. Display details of students";
        std::cout<<"\n\n\t5. Register a student into a course";
        std::cout<<"\n\n\t6. Display all registration";
        std::cout<<"\n\n\t7. Display number of semesters a student will take to complete all CS courses";
        std::cout<<"\n\n\tSelect Your Option (1-7): ";std::cin>>choice;
        while (choice!='1'&& choice !='2'&& choice !='3'&& choice !='4'&& choice !='5'&& choice !='6'&& choice !='7')
        {
            std::cout<<"\tIncorrect choice entered.....re-enter choice again: ";
            std::cin>>choice;
        }
        // system("cls");

        switch(choice)
        {
            case '1':
                std::cout<<"\n\n\tThanks for using course approval system\n\n\n";
                break;
            case '2':
                displayAllStudents(s1, stot_records);
                break;
            case '3':
                display_courses(c1, ctot_records);
                break;
            case '4':
                std::cout<<"\n\n\tEnter Course ID: ";std::cin>>courseId;
                while (courseId!="cs111"&& courseId !="cs112"&& courseId != "cs240"&& courseId !="cs241"&& courseId !="cs214"&& courseId !="cs215"&& courseId !="cs218"&& courseId !="cs310"&&courseId != "cs311"&&courseId !="cs317"&&courseId !="cs318"&&courseId !="cs324"&&courseId != "cs341"){
                    std::cout<<"\tIncorrect course entered.....re-enter course again: "; //validation
                    std::cin>>courseId;
                }
                course_lookup(courseId, r1, rtot_records, s1, stot_records);
                break;
            case '5':
                display.course::displayAllCourse( c1, ctot_records);
                std::cout<<"\n\n\tEnter your ID: ";std::cin>>id;
                while (id!="s111"&& id !="s222"&& id != "s333"&& id !="s444")
                {
                    std::cout<<"\tIncorrect ID entered.....re-enter ID again: ";
                    std::cin>>id;
                }
                std::cout<<"\n\tEnter Course you would like to register to: ";std::cin>>courser;
                while (courser!="cs111"&& courser !="cs112"&& courser != "cs240"&& courser !="cs241"&& courser !="cs214"&& courser !="cs215"&& courser !="cs218"&& courser !="cs310"&&courser != "cs311"&&courser !="cs317"&&courser !="cs318"&&courser !="cs324"&&courser != "cs341"){
                    std::cout<<"\tIncorrect course entered.....re-enter course again: ";
                    std::cin>>courser;
                }
                register_student(id, courser, c1, ctot_records, cs1, cstot_records, r1, rtot_records);
                break;
            case '6':
                display_registrations(r1, rtot_records);
                break;
            case '7':
                std::cout<<"\n\n\tEnter your ID: ";std::cin>>id;
                while (id!="s111"&& id !="s222"&& id != "s333"&& id !="s444")
                {
                    std::cout<<"\tIncorrect ID entered.....re-enter ID again: ";
                    std::cin>>id;
                }
                displaySemester(id, r1, rtot_records, cs1, cstot_records);
                break;
            default :std::cout<<"\a";
        }
        std::cin.ignore();
        std::cin.get();
    }while(choice!='1');
    return 0;
}

//display intro
void intro()
{
    std::cout<<"\n\n\n\tCOURSE";
    std::cout<<"\n\tAPPROVAL SYSTEM";
    std:: cout<<"\n\tFOR USP CS STUDENTS";
}

//removing spaces while reading text files
void discard_line(std::ifstream &in)
{
    char c;

    do
        in.get(c);
    while (c !='\n');
}

//display all students
void displayAllStudents(student *s1, int tot_records)
{
    student caller;
    caller.student::display_all(s1, tot_records);
}

//display all courses
void display_courses(course c1[], int tot_records)
{
    course caller;
    caller.course::displayAllCourse(c1, tot_records);

}

//display student registered to course
void course_lookup(const std::string &c, registration r1[], int tot_records2, student s2[], int tot_records1)
{
    registration rsingle[MAX_SIZE];
    std::string f_id[MAX_SIZE];
    int numid;
    bool norec= false;

    for(int i =0; i<tot_records2 ; i++)
    {
        if(r1[i].getCurrentRegistrations()==c)
        {

        }
    }

    std::cout<<"\n\tRECORD(s) OF STUDENT DOING THIS COURSE\n";
    std::cout<<"\n\tID"<<"\tLast Name"<<"\tFirst Name"<<"\tAGE"<<"\tPHONE";
    std::cout<<"\n\t-----------------------------------------------------";


    for(int i =0; i<tot_records2 ; i++)
    {
        if(r1[i].getCurrentRegistrations()==c)
        {
            rsingle[i].setFoundId(r1[i].getRegisteredStudentId());

            if(rsingle[i].getRegisteredStudentId() == "s111")
            {
                numid=1;
                displayStudentInfo(numid, s2, tot_records1);
                norec= true;

            }
            else if(rsingle[i].getRegisteredStudentId() == "s222")
            {
                numid=2;
                displayStudentInfo(numid, s2, tot_records1);
                norec= true;
            }
            else if(rsingle[i].getRegisteredStudentId() == "s333")
            {
                numid=3;
                displayStudentInfo(numid, s2, tot_records1);
                norec= true;
            }
            else
            {
                numid=4;
                displayStudentInfo(numid, s2, tot_records1);
                norec= true;
            }
        }
        else
        {
            if(i==tot_records2-1 && norec==0)
            {
                std::cout<<"\n\t\t\t   NO RECORDS :(";
            }
        }
    }
}

//read course text file
void readCourseFile(std::ifstream &cstudent, course *c1, int &tot_records)
{
    cstudent.open("/Users/NAISUA/Desktop/txt_for_ass/Courses.txt");
    if(!cstudent)
    {
        std::cerr<<"File could not be opened4"<<std::endl;
        system("PAUSE");
        exit(1);
    }

    else
    {
        discard_line(cstudent);

        int semester ;
        std::string course,prereq;

        tot_records=0;

        while(cstudent>>course>>prereq>>semester)
        {
            c1[tot_records].setCourseId(course);
            c1[tot_records].setPrerequisite(prereq);
            c1[tot_records].setSemester(semester);
            tot_records++;
        }

        cstudent.close();
    }
}

//read student text file
void readStudentFile(std::ifstream& rstudents,student* s2,int& tot_records)
{
    rstudents.open("/Users/NAISUA/Desktop/txt_for_ass/Student.txt");

    if(!rstudents)
    {
        std::cerr<<"File could not be opened1"<<std::endl;
        system("PAUSE");
        exit(1);
    }

    else
    {
        discard_line(rstudents);

        int age;
        std::string id,lname,fname,phone;

        tot_records=0;

        while(rstudents>>id>>lname>>fname>>age>>phone)
        {
            s2[tot_records].setId(id);
            s2[tot_records].setLName(lname);
            s2[tot_records].setFName(fname);
            s2[tot_records].setAge(age);
            s2[tot_records].setPhone(phone);
            tot_records++;
        }

        rstudents.close();
    }

}

//read registration text file
void readRegistrationFile(std::ifstream &registers, registration *r1, int &tot_records2)
{

    registers.open("/Users/NAISUA/Desktop/txt_for_ass/Registration.txt");


    if(!registers)
    {
        std::cerr<<"File could not be opened2"<<std::endl;
        system("PAUSE");
        exit(1);
    }

    else
    {
        discard_line(registers);

        std::string id1,c1;

        tot_records2=0;

        while(registers>>id1>>c1)
        {
            r1[tot_records2].setRegisteredStudentId(id1);
            r1[tot_records2].setCurrentRegistrations(c1);
            tot_records2++;
        }
        registers.close();
    }

}

//read CS students text file
void readCsStudentFile(std::ifstream &csflie, cs_student *cs1, int &tot_records)
{
    csflie.open("/Users/NAISUA/Desktop/txt_for_ass/CSstduents.txt");


    if(!csflie)
    {
        std::cerr<<"File could not be opened3"<<std::endl;
        system("PAUSE");
        exit(1);
    }

    else
    {
        discard_line(csflie);

        std::string cid,ccourse;

        tot_records=0;

        while(csflie>>cid>>ccourse)
        {
            cs1[tot_records].setIdPassedStudent(cid);
            cs1[tot_records].setPassedCourse(ccourse);
            tot_records++;
        }
        csflie.close();
    }
}

//register student
void register_student(const std::string &id, std::string courser, course c1[], int ctot_records, cs_student cs1[], int cstot_records, registration r1[], int rtot_records)
{
    course csingle;

    bool one, two, three, four, five, six;


    six= checkEnrolledCourses(id, r1, rtot_records);
    five= checkLevel(id, courser, c1, ctot_records, cs1, cstot_records);
    two=sem_check(courser, csingle, c1, ctot_records, cs1, cstot_records);
    four= prerequisiteCheck(id, courser, c1, ctot_records, csingle, cs1, cstot_records);
    one=already_registered( id,  courser,  r1,  rtot_records);
    three= checkCourseCompletion(id, courser, cs1, cstot_records);

    if (one== 0 && two== 1 && three== 0 && four== 1 && five== 1 && six== 0)
    {
        std::cout<<"\n\n\tREGISTRATION APPROVED!!!";
        write_registrations(id, courser);
    }
    else
    {
        std::cout<<"\n\n\tREGISTRATION NOT APPROVED!!!";
    }



}

//check if prerequisite is done
bool prerequisiteCheck(const std::string &id, std::string courser, course *c1, int ctot_records, course csingle,
                       cs_student *cs1, int cstot_records)
{
    bool pass = true;
    std::string reason3;

    for(int i =0; i < ctot_records; i++)
    {
        if (c1[i].getCourseId()==courser)
        {
            csingle.setFoundPrerequisite(c1[i].getPrerequisite());
        }
    }
    for(int i = 0; i<cstot_records; i++)
    {
        if(csingle.getFoundPrerequisite() == cs1[i].getPassedCourse() || csingle.getFoundPrerequisite() == "NA")
        {
            if(id == cs1[i].getIdPassedStudent())
            {
                pass= true;
                std::cout<<"\n\tPREREQ PASSED :)";
                return pass;
            }
        }
        else
        {
            if (i==cstot_records-1)
            {
                std::cout<<"\n\tSTUDENT HASN'T PASSED OR DONE THE PREREQ COURSE "<<csingle.getFoundPrerequisite()<<" THEREFORE STUDENT IS NOT ALLOWED TO REGISTER :(";
                pass= false;
            }
        }

    }
    return pass;
}

//check semester
bool sem_check(const std::string &courser ,course csingle,course c1[], int ctot_records, cs_student cs1[], int cstot_records)
{
    bool semcheck = false;
    int semester = 2 | 0;
    int end;
    for(int i=0; i<ctot_records; i++)
    {
        if(courser==c1[i].getCourseId())
        {
            end=i;
            csingle.setFoundSemester(c1[i].getSemester());
            if((semester==csingle.getFoundSemester() || csingle.getFoundSemester()==0)&& courser==c1[i].getCourseId())
            {
                std::cout<<"\n\tcourse is provided in semester 2 :) ";
                semcheck=true;
                return semcheck;
            }
            else
            {
                if(i==end)
                {
                    std::cout<<"\n\tcourse is only provided in semester "<<csingle.getFoundSemester()<<" :(";
                    semcheck=false;
                }
            }

        }
    }
    return semcheck;
}

//check if already registered
bool already_registered(const std::string &id, std::string courser, registration r1[], int rtot_records)
{
    bool registered = true;

    for(int i= 0; i< rtot_records; i++)
    {

        if(id==r1[i].getRegisteredStudentId() && courser== r1[i].getCurrentRegistrations())
        {
            std::cout<<"\n\tALREADY REGISTERED!!! :(";
            registered=true;
            return registered;
        }
        else
        {
            if(i==rtot_records-1)
            {
                std::cout<<"\n\tNOT ALREADY REGISTERED :)";
                registered= false;
            }
        }

    }


    return registered;
}

//check if all previous lvl courses are done
bool checkLevel(const std::string &id, std::string courseId, course *c1, int ctot_records, cs_student *cs1, int cstot_records)
{
    bool done=true;
    char level= courseId[2];
    int levelcounter=0;

    char levelpassc[ctot_records];

    for(int i= 0; i<ctot_records; i++)
    {
        levelpassc[i]=c1[i].getCourseId()[2];
    }

    for(int i=0;i<cstot_records;i++)
    {
        if(level=='2')
        {
            if (id==cs1[i].getIdPassedStudent() && cs1[i].getPassedCourse()[2]=='1')
            {
                levelcounter++;
            }
        }

        else if(level=='3')
        {
            if (id==cs1[i].getIdPassedStudent() && cs1[i].getPassedCourse()[2]=='2')
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
                std::cout<<"\n\tall 100 levels compeleted :)";
                done=true;
                return done;
            }

            else
            {
                std::cout<<"\n\tall 100 levels not compeleted :(";
                done=false;
                return done;
            }
        }

        if(level=='3')
        {
            if (levelcounter==5)
            {
                std::cout<<"\n\tall 200 levels compeleted :)";
                done=true;
                return done;
            }

            else
            {
                std::cout<<"\n\tall 200 levels not compeleted :(";
                done=false;
                return done;
            }
        }

        else
        {
            if(levelcounter==0)
            {
                done=true;
                std::cout<<"\n\t100 level :)";
                return done;
            }
        }
    }
    return done;
}

//check the number of courses a student is registered too
bool checkEnrolledCourses(const std::string &id, registration *r1, int rtot_records)
{
    const int num =2;
    int wili=0;
    bool counter = true;
    std::ifstream rstudents;

    readRegistrationFile(rstudents, r1, rtot_records);

    for(int i =0; i<rtot_records; i++)
    {
        if (id==r1[i].getRegisteredStudentId())
        {
            wili=wili+1;
        }
    }

    if (wili==num)
    {
        std::cout<<"\n\tREGISTRATION LIMIT REACHED :(";
        counter = true;
        return counter;
    }
    else
    {
        std::cout<<"\n\tREGISTRATION FOR "<<2-wili<<" COURSE(S) CAN BE DONE :)";
        counter = false;
        return counter;
    }




    return counter;
}

//check if course is already done
bool checkCourseCompletion(const std::string &id, std::string course, cs_student *csptxt, int cstot_records)
{
    bool done= true;

    for(int i=0;i<cstot_records;i++)
    {
        if(id==csptxt[i].getIdPassedStudent() && course== csptxt[i].getPassedCourse())
        {
            std::cout<<"\n\tSTUDENT HAS ALREADY DONE THIS COURSE :(";
            done=true;
            return done;
        }

        else
        {
            if(i==cstot_records-1)
            {
                std::cout<<"\n\tCOURSE NOT DONE YET :) ";
                done= false;
            }
        }

    }

    return done;
}

//updates registration txt file
void write_registrations(const std::string &id, std::string course)
{
    std::ofstream rstudent;

    rstudent.open("/Users/NAISUA/Desktop/txt_for_ass/Registration.txt", std::ofstream::out | std::ofstream:: app);

    rstudent<<"\n"<<id<<" "<<course;

    rstudent.close();

}

//displays registration
void display_registrations(registration r1[], int rtot_records)
{
    std::ifstream rstudents;

    readRegistrationFile(rstudents, r1, rtot_records);

    std::cout<<"\n\tREGISTRATIONS\n";
    std::cout<<"\n\tID"<<"    COURSES\n";
    std::cout<<"\t-------------\n";

    for(int i =0; i<rtot_records ; i++)
    {
        std::cout<<"\t"<<r1[i].getRegisteredStudentId()<<"\t"<<r1[i].getCurrentRegistrations()<<"\n";

    }
}

//displays personal info for option 4
void displayStudentInfo(int numid, student *s2, int tot_records1)
{

    std::cout<<"\n\t"<<s2[numid-1].getId()<<"\t"<<s2[numid-1].getLName()<<"\t\t"<<s2[numid-1].getFName()<<"\t\t"<<s2[numid-1].getAge()<<"\t"<<s2[numid-1].getPhone()<<"";

}

//display semesters left for course completion
void displaySemester(const std::string &id, registration *r1, int rtot_records, cs_student *cs1, int cstot_records)
{
    int counterr=0;
    int countercs=0;
    const int tot_courses=13;


    for(int i=0; i<rtot_records; i++)
    {
        if(id==r1[i].getRegisteredStudentId())
        {
            counterr++;
        }

    }
    for(int i=0; i<cstot_records; i++)
    {
        if(id==cs1[i].getIdPassedStudent())
        {
            countercs++;
        }
    }

    std::cout<<"\n\tYou have "<<tot_courses-(counterr+countercs)<<" semster(s) to complete your program. GOOD LUCK :)";

}
