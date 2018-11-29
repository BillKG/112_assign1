//
// Created by Naisua on 10/11/2018.
//

#include "registration.h"

registration::registration() {}

registration::registration(const std::string &registeredStudentId, const std::string &currentRegistrations,
                           const std::string &foundId) : registeredStudentId(registeredStudentId),
                                                         currentRegistrations(currentRegistrations), foundId(foundId) {}

registration::~registration() {

}

const std::string &registration::getRegisteredStudentId() const {
    return registeredStudentId;
}

void registration::setRegisteredStudentId(const std::string &registeredStudentId) {
    registration::registeredStudentId = registeredStudentId;
}

const std::string &registration::getCurrentRegistrations() const {
    return currentRegistrations;
}

void registration::setCurrentRegistrations(const std::string &currentRegistrations) {
    registration::currentRegistrations = currentRegistrations;
}

const std::string &registration::getFoundId() const {
    return foundId;
}

void registration::setFoundId(const std::string &foundId) {
    registration::foundId = foundId;
}
