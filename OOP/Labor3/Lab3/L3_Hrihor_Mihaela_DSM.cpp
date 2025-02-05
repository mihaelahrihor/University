#include <iostream>
#include"L3_Hrihor_Mihaela_DSM.h"

DSM::DSM(int element_count) : element_names(element_count), adjacency_matrix(element_count, std::vector<float>(element_count, 0.0f)) {}

DSM::DSM(std::vector<std::string> element_names) : element_names(element_names), adjacency_matrix(element_names.size(), std::vector<float>(element_names.size(), 0.0f)) {}

DSM::~DSM() {}

DSM::DSM(const DSM &other) : element_names(other.element_names), adjacency_matrix(other.adjacency_matrix) {}

int DSM::size() const {
    return element_names.size();
}

std::string DSM::get_name(int index) const {
    if (index < 0 || index >= size()){
        throw std::out_of_range("Index out of range");
    }
    return element_names[index];
}

void DSM::set_element_name(int index, const std::string& name) {
    if (index < 0 || index >= size()){
        throw std::out_of_range("Index out of range");
    }
    element_names[index] = name;
}

void DSM::add_link(const std::string &from_element, const std::string &to_element, float weight) {
    int from_index = -1, to_index = -1;
    for (int i=0; i<size(); i++){
        if (element_names[i] == from_element){
            from_index = i;
        }
        if (element_names[i] == to_element){
            to_index = i;
        }
    }
    if (from_index == -1 || to_index == -1){
        throw std::invalid_argument("Unknown element name");
    }
    adjacency_matrix[from_index][to_index] = weight;
}

void DSM::delete_link(const std::string &from_element, const std::string &to_element) {
    add_link(from_element, to_element, 0.0f);
}

bool DSM::have_link(const std::string &from_element, const std::string &to_element) const {
    int from_index = -1, to_index = -1;
    for (int i=0; i<size(); i++){
        if (element_names[i] == from_element){
            from_index = i;
        }
        if (element_names[i] == to_element){
            to_index = i;
        }
    }
    if (from_index == -1 || to_index == -1){
        throw std::invalid_argument("Unknown element name");
    }
    return adjacency_matrix[from_index][to_index] != 0.0f;
}

float DSM::link_weight(const std::string &from_element, const std::string &to_element) const {
    int from_index = -1, to_index = -1;
    for (int i=0; i<size(); i++){
        if (element_names[i] == from_element){
            from_index = i;
        }
        if (element_names[i] == to_element){
            to_index = i;
        }
    }
    if (from_index == -1 || to_index == -1){
        throw std::invalid_argument("Unknown element name");
    }
    return adjacency_matrix[from_index][to_index];
}

int DSM::count_to_links(const std::string &element_name) const {
    int index = -1;
    for (int i=0; i<size(); i++){
        if (element_names[i] == element_name){
            index = i;
            break;
        }
    }
    if (index == -1){
        throw std::invalid_argument("Unknown element name");
    }
    int count = 0;
    for (int i=0; i<size(); i++){
        if (adjacency_matrix[i][index] != 0.0f){
            count++;
        }
    }
    return count;
}

int DSM::count_from_links(const std::string &element_name) const {
    int index = -1;
    for (int i = 0; i < size(); ++i) {
        if (element_names[i] == element_name) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        throw std::invalid_argument("Unknown element name");
    }
    int count = 0;
    for (int i = 0; i < size(); ++i) {
        if (adjacency_matrix[index][i] != 0.0f) {
            ++count;
        }
    }
    return count;
}

int DSM::count_all_links() const {
    int count = 0;
    for (int i=0; i<size(); i++){
        for (int j=0; j<size(); j++){
            if (adjacency_matrix[i][j] != 0.0f){
                count++;
            }
        }
    }
    return count;
}

void DSM::print_element_names() const {
    std::cout << "Element names:" << std::endl;
    for (const auto& element_name: element_names){
        std::cout << element_name << std::endl;
    }
}

void DSM::print_matrix() const {
    std::cout << "Adjacency matrix:" << std::endl;
    for (int i=0; i<size(); i++){
        for (int j=0; j<size(); j++){
            std::cout << adjacency_matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}