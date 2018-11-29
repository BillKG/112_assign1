//
// Created by Naisua on 10/11/2018.
//

#ifndef COURSE_APPROVAL_SYSTEM_COURSE_H
#define COURSE_APPROVAL_SYSTEM_COURSE_H
#include <string>

class course{
public:
    course(const std::string &courseId, const std::string &prerequisite, int semester,
           const std::string &foundPrerequisite, int foundSemester);

    course();
    
    virtual ~course();

    const std::string &getCourseId() const;

    void setCourseId(const std::string &courseId);

    const std::string &getPrerequisite() const;

    void setPrerequisite(const std::string &prerequisite);

    int getSemester() const;

    void setSemester(int semester);

    const std::string &getFoundPrerequisite() const;

    void setFoundPrerequisite(const std::string &foundPrerequisite);

    int getFoundSemester() const;

    void setFoundSemester(int foundSemester);

    void displayAllCourse(course student[], int size);




private:
    std::string courseId;
    std::string prerequisite;
    int semester;
    std::string foundPrerequisite;
    int foundSemester;
};

#endif //COURSE_APPROVAL_SYSTEM_COURSE_H
