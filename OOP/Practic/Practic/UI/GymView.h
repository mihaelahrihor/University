#ifndef GYM_VIEW_H
#define GYM_VIEW_H

#include <iostream>
#include <vector>
#include "Member.h"

class GymView {
public:
    void show_members(const std::vector<Member>& members);
    int get_member_id();
    std::string get_member_name();
    void display_message(const std::string& message);
};

#endif