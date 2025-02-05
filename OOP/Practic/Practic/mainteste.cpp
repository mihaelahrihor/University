#include "Member.h"
#include "../Repository/MemberRegistery.h"
#include "../Controller/GymController.h"
#include <iostream>
#include <cassert>

int main() {
    MemberRegistry* registry = MemberRegistry::get_instance();

    Member member1(1, "Alice", "Premium", true);
    Member member2(2, "Bob", "Basic", false);

    registry->add_member(member1);
    registry->add_member(member2);

    Member* foundMember = registry->find_member_by_name("Alice");
    if (foundMember) {
        std::cout << "Found member: " << foundMember->getName() << std::endl;
    } else {
        std::cout << "Member not found." << std::endl;
    }

    MemberRegistry* registry = MemberRegistry::get_instance();


    assert(registry != nullptr);


    GymController controller;


    controller.add_member(1, "Alice Smith", "Regular");
    assert(controller.get_all_members().size() == 1);


    controller.remove_member(1);
    assert(controller.get_all_members().empty());

    std::cout << "All tests passed successfully!" << std::endl;

    return 0;
}