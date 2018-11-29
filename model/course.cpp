//
// Created by Naisua on 10/11/2018.
//

#include <iostream>
#include "course.h"

//default constructor
course::course() {}

course::course(const std::string &courseId,
                const std::string &prerequisite,
                int semester,
                const std::string &foundPrerequisite,
                int foundSemester) : courseId(courseId), prerequisite(prerequisite), semester(semester), foundPrerequisite(foundPrerequisite), foundSemester(foundSemester) {

    //implement constructor here :)

}

course::~course() {

}

const std::string &course::getCourseId() const {
    return courseId;
}

void course::setCourseId(const std::string &courseId) {
    course::courseId = courseId;
}

const std::string &course::getPrerequisite() const {
    return prerequisite;
}

void course::setPrerequisite(const std::string &prerequisite) {
    course::prerequisite = prerequisite;
}

int course::getSemester() const {
    return semester;
}

void course::setSemester(int semester) {
    course::semester = semester;
}

const std::string &course::getFoundPrerequisite() const {
    return foundPrerequisite;
}

void course::setFoundPrerequisite(const std::string &foundPrerequisite) {
    course::foundPrerequisite = foundPrerequisite;
}

int course::getFoundSemester() const {
    return foundSemester;
}

void course::setFoundSemester(int foundSemester) {
    course::foundSemester = foundSemester;
}

void course::displayAllCourse(course *student, int size) {
    std::cout<<"\n\tCOURSES AT USP\n";
    std::cout<<"\n\tCourse"<<"\tPrereq"<<"    Semester\n";
    std::cout<<"\t--------------------------\n";

    for(int i =0; i<size ; i++)
    {
        std::cout<<"\t"<<student[i].getCourseId()<<"\t"<<student[i].getPrerequisite()<<"\t\t"<<student[i].getSemester()<<"\n";

    }
}


