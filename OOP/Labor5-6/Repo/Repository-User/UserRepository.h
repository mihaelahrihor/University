//
// Created by zaxx4 on 18.05.2024.
//
#include <iostream>
#include <vector>
#include "../Domain-User/User.h"

using namespace std;
#ifndef CARSHARING_USERREPOSITORY_H
#define CARSHARING_USERREPOSITORY_H
class UserRepository{
private:
    vector<User> users_;

public:
    explicit UserRepository(const vector<User> &users);

    void addUser(User user);

    User searchUser(const string &email);

    bool authenticate(const string &email, const string &password);

    void startData();
};
#endif //CARSHARING_USERREPOSITORY_H
