//
// Created by zaxx4 on 18.05.2024.
//

#include "User.h"

User::User(const string &email, const string &password) : email_(email), password_(password) {}

const string &User::getEmail() const {
    return email_;
}

void User::setEmail(const string &email) {
    User::email_ = email;
}

const string &User::getPassword() const {
    return password_;
}

void User::setPassword(const string &password) {
    User::password_ = password;
}

bool User::authenticate(const string &email, const string &password) {
    return this->email_ == email && this->password_ == password;
}
