#ifndef GYM_CONTROLLER_H
#define GYM_CONTROLLER_H

#include "../Repository/MemberRegistery.h"

class GymController {
private:
    MemberRegistry* registry;

public:
    GymController();

    void add_member(int id, const std::string& name, const std::string& membership_type);
    void remove_member(int id);
    Member* get_member_details(int id);
    std::vector<Member> get_all_members();
    Member* find_member_by_name(const std::string& name);
};

#endif