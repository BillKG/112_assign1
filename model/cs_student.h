//
// Created by Naisua on 10/11/2018.
//

#ifndef COURSE_APPROVAL_SYSTEM_CS_STUDENT_H
#define COURSE_APPROVAL_SYSTEM_CS_STUDENT_H

#include <string>
#include "student.h"

class cs_student: public student
{
public:
    cs_student();

    cs_student(const std::string &idPassedStudent, const std::string &passedCourse);

    const std::string &getIdPassedStudent() const;

    void setIdPassedStudent(const std::string &idPassedStudent);

    const std::string &getPassedCourse() const;

    void setPassedCourse(const std::string &passedCourse);

    virtual ~cs_student();

private:
    std::string idPassedStudent;
    std::string passedCourse;

};

#endif //COURSE_APPROVAL_SYSTEM_CS_STUDENT_H
