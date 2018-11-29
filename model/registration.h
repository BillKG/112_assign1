//
// Created by Naisua on 10/11/2018.
//

#ifndef COURSE_APPROVAL_SYSTEM_REGISTRATION_H
#define COURSE_APPROVAL_SYSTEM_REGISTRATION_H
#include <string>

class registration
{
public:
    registration();

    registration(const std::string &registeredStudentId, const std::string &currentRegistrations,
                 const std::string &foundId);

    const std::string &getRegisteredStudentId() const;

    void setRegisteredStudentId(const std::string &registeredStudentId);

    const std::string &getCurrentRegistrations() const;

    void setCurrentRegistrations(const std::string &currentRegistrations);

    const std::string &getFoundId() const;

    void setFoundId(const std::string &foundId);

    virtual ~registration();

private:
    std::string registeredStudentId;
    std::string currentRegistrations;
    std::string foundId;
};

#endif //COURSE_APPROVAL_SYSTEM_REGISTRATION_H
