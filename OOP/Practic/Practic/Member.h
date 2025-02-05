#ifndef MEMBER_H
#define MEMBER_H

#include <string>

class Member {
private:
    int id;
    std::string name;
    std::string membershipType;
    bool isActive;

public:
    Member(int memberId, const std::string& memberName, const std::string& type, bool active);

    int getId() const;
    std::string getName() const;
    std::string getMembershipType() const;
    bool isActiveMember() const;
};

#endif