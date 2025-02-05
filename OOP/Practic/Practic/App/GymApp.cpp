#include "GymApp.h"
using namespace std;

void GymApp::run()  {
    char choice;
    do {
        std::cout << "Welcome to the Gym Management System" << std::endl;
        std::cout << "1. Add a member" << std::endl;
        std::cout << "2. Remove a member" << std::endl;
        std::cout << "3. View member details" << std::endl;
        std::cout << "4. List all members" << std::endl;
        std::cout << "5. Find member by name" << std::endl;
        std::cout << "6. Process membership payment" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1': {
                int id;
                std::string name, membership_type;
                std::cout << "Enter Member ID: ";
                std::cin >> id;
                std::cout << "Enter Member Name: ";
                std::cin.ignore(); // Ignore the newline character in the input buffer
                std::getline(std::cin, name);
                std::cout << "Enter Membership Type: ";
                std::cin >> membership_type;
                controller.add_member(id, name, membership_type);
                break;
            }
            case '2': {
                int id;
                std::cout << "Enter Member ID to remove: ";
                std::cin >> id;
                controller.remove_member(id);
                break;
            }
            case '3': {
                int id;
                std::cout << "Enter Member ID to view details: ";
                std::cin >> id;
                Member* member = controller.get_member_details(id);
                if (member != nullptr) {
                    std::cout << "Member Details - ID: " << member->getId() << ", Name: " << member->getName() << ", Membership Type: " << member->getMembershipType() << std::endl;
                } else {
                    std::cout << "Member not found." << std::endl;
                }
                break;
            }
            case '4': {
                std::vector<Member> members = controller.get_all_members();
                view.show_members(members);
                break;
            }
            case '5': {
                std::string name;
                std::cout << "Enter Member Name to find: ";
                std::cin.ignore(); // Ignore the newline character in the input buffer
                std::getline(std::cin, name);
                Member* member = controller.find_member_by_name(name);
                if (member != nullptr) {
                    std::cout << "Member Found - ID: " << member->getId() << ", Name: " << member->getName() << ", Membership Type: " << member->getMembershipType() << std::endl;
                } else {
                    std::cout << "Member not found." << std::endl;
                }
                break;
            }
            case '6': {
                // Process membership payment logic can be added here
                std::cout << "Membership payment processed." << std::endl;
                break;
            }
            case '7':
                std::cout << "Exiting Gym Management System..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != '7');
}