#include "Member.h"

Member::Member(int memberId, const std::string& memberName, const std::string& type, bool active)
        : id(memberId), name(memberName), membershipType(type), isActive(active) {}

int Member::getId() const {
    return id;
}

std::string Member::getName() const {
    return name;
}

std::string Member::getMembershipType() const {
    return membershipType;
}

bool Member::isActiveMember() const {
    return isActive;
}