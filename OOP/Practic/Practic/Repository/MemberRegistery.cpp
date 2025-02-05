#include "MemberRegistery.h"
#include <algorithm>

MemberRegistry* MemberRegistry::instance = nullptr;

MemberRegistry::MemberRegistry() {}

MemberRegistry* MemberRegistry::get_instance() {
    if (!instance) {
        instance = new MemberRegistry();
    }
    return instance;
}

void MemberRegistry::add_member(const Member& member) {
    members.push_back(member);
}

void MemberRegistry::remove_member(int member_id) {
    members.erase(std::remove_if(members.begin(), members.end(), [member_id](const Member& m) {
        return m.getId() == member_id;
    }), members.end());
}

Member* MemberRegistry::get_member(int member_id) {
    for (auto& member : members) {
        if (member.getId() == member_id) {
            return &member;
        }
    }
    return nullptr;
}

std::vector<Member> MemberRegistry::get_members() {
    return members;
}

Member* MemberRegistry::find_member_by_name(const std::string& member_name) {
    for (auto& member : members) {
        if (member.getName() == member_name) {
            return &member;
        }
    }
    return nullptr;
}