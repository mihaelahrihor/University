#ifndef MEMBER_REGISTRY_H
#define MEMBER_REGISTRY_H

#include "Member.h"
#include <vector>

class MemberRegistry {
private:
    std::vector<Member> members;
    static MemberRegistry* instance;

    MemberRegistry();

public:
    static MemberRegistry* get_instance();
    void add_member(const Member& member);
    void remove_member(int member_id);
    Member* get_member(int member_id);
    std::vector<Member> get_members();
    Member* find_member_by_name(const std::string& member_name);
};

#endif