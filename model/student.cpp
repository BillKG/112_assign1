//
// Created by Naisua on 10/11/2018.
//

#include <iostream>
#include "student.h"

student::student() {}

student::student(const std::string &id, const std::string &lName, const std::string &fName, int age,
                 const std::string &phone) : id(id), lName(lName), fName(fName), age(age), phone(phone) {}


student::~student() {

}

const std::string &student::getId() const {
    return id;
}

void student::setId(const std::string &id) {
    student::id = id;
}

const std::string &student::getLName() const {
    return lName;
}

void student::setLName(const std::string &lName) {
    student::lName = lName;
}

const std::string &student::getFName() const {
    return fName;
}

void student::setFName(const std::string &fName) {
    student::fName = fName;
}

int student::getAge() const {
    return age;
}

void student::setAge(int age) {
    student::age = age;
}

const std::string &student::getPhone() const {
    return phone;
}

void student::setPhone(const std::string &phone) {
    student::phone = phone;
}

void student::display_all(student *student, int &size) {
    std::cout<<"\n\tSTUDENTS AT USP\n";
    std::cout<<"\n\tID"<<"\tLast Name"<<"\tFirst Name"<<"\tAGE"<<"\tPHONE\n";
    std::cout<<"\t-----------------------------------------------------";
    for(int i =0; i<size ; i++){
        std::cout<<"\n\t"<<student[i].getId()<<"\t"<<student[i].getLName()<<"\t\t"<<student[i].getFName()<<"\t\t"<<student[i].getAge()<<"\t"<<student[i].getPhone()<<"";
    }
    std::cout<<std::endl;
}
