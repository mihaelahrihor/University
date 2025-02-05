//
// Created by zaxx4 on 18.05.2024.
//
#include <iostream>
#include <string>
using namespace std;
#ifndef CARSHARING_USER_H
#define CARSHARING_USER_H

class User{

protected:
    string password_;
    string email_;
    
public:
    explicit User(const std::string &email, const std::string &password);

    virtual const std::string &getEmail() const;

    virtual void setEmail(const std::string &email);

    virtual const std::string &getPassword() const;

    virtual void setPassword(const std::string &password);

    virtual bool authenticate(const std::string &email, const std::string &password);

};
#endif //CARSHARING_USER_H
