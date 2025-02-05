#include "GymController.h"

GymController::GymController() {
    registry = MemberRegistry::get_instance();
}

void GymController::add_member(int id, const std::string& name, const std::string& membership_type) {
    Member newMember(id, name, membership_type, true); // Assuming all added members are active
    registry->add_member(newMember);
}

void GymController::remove_member(int id) {
    registry->remove_member(id);
}

Member* GymController::get_member_details(int id) {
    return registry->get_member(id);
}

std::vector<Member> GymController::get_all_members() {
    return registry->get_members();
}

Member* GymController::find_member_by_name(const std::string& name) {
    return registry->find_member_by_name(name);
}