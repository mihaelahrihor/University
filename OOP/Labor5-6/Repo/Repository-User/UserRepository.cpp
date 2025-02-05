//
// Created by zaxx4 on 18.05.2024.
//

#include "UserRepository.h"
#include <exception>

UserRepository::UserRepository(const vector<User> &users) : users_(users) {}

void UserRepository::addUser(User user) {
    users_.push_back(user);
}

User UserRepository::searchUser(const string &email) {
    for (int i = 0; i < users_.size(); i++)
        if (email == users_[i].getEmail())
            return users_[i];
    throw std::runtime_error("User not found: " + email);
}

bool UserRepository::authenticate(const string &email, const string &password) {
    try {
        User user = searchUser(email);
        if (user.authenticate(email, password)) {
            return true;
        }
        else {
            return false;
        }
    } catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
        return false;
    }

}

void UserRepository::startData() {

}

