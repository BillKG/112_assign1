//
// Created by Naisua on 10/11/2018.
//

#include "cs_student.h"

cs_student::cs_student() {}

cs_student::cs_student(const std::string &idPassedStudent, const std::string &passedCourse) : idPassedStudent(
        idPassedStudent), passedCourse(passedCourse) {}

cs_student::~cs_student() {

}

const std::string &cs_student::getIdPassedStudent() const {
    return idPassedStudent;
}

void cs_student::setIdPassedStudent(const std::string &idPassedStudent) {
    cs_student::idPassedStudent = idPassedStudent;
}

const std::string &cs_student::getPassedCourse() const {
    return passedCourse;
}

void cs_student::setPassedCourse(const std::string &passedCourse) {
    cs_student::passedCourse = passedCourse;
}
