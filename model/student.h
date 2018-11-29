//
// Created by Naisua on 10/11/2018.
//

#ifndef COURSE_APPROVAL_SYSTEM_STUDENT_H
#define COURSE_APPROVAL_SYSTEM_STUDENT_H

#include <string>

class student
{
public:

    student();

    student(const std::string &id, const std::string &lName, const std::string &fName, int age,
            const std::string &phone);

    virtual ~student();

    const std::string &getId() const;

    void setId(const std::string &id);

    int getAge() const;

    void setAge(int age);

    const std::string &getPhone() const;

    void setPhone(const std::string &phone);

    void display_all(student* student, int& size);

    const std::string &getLName() const;

    void setLName(const std::string &lName);

    const std::string &getFName() const;

    void setFName(const std::string &fName);



private:
    std::string id;
    std::string lName;
    std::string fName;
    int age;
    std::string phone;

};

#endif //COURSE_APPROVAL_SYSTEM_STUDENT_H
