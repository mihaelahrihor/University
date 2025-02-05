#include "GymView.h"

void GymView::show_members(const std::vector<Member>& members) {
    std::cout << "Members List:" << std::endl;
    for (const auto& member : members) {
        std::cout << "ID: " << member.getId() << " | Name: " << member.getName() << " | Membership Type: " << member.getMembershipType() << std::endl;
    }
}

int GymView::get_member_id() {
    int id;
    std::cout << "Enter Member ID: ";
    std::cin >> id;
    return id;
}

std::string GymView::get_member_name() {
    std::string name;
    std::cout << "Enter Member Name: ";
    std::cin.ignore();
    std::getline(std::cin, name);
    return name;
}

void GymView::display_message(const std::string& message) {
    std::cout << message << std::endl;
}