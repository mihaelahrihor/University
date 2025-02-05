#ifndef DSM_H
#define DSM_H

#include <vector>
#include <string>
#include <stdexcept>

class DSM {
private:

    // vector de siruri de caractere
    // stocheaza numele elementelor din matricea de adiacenta
    std::vector<std::string> element_names;

    // vector bidimensional, matricea de adiacenta
    std::vector<std::vector<float>> adjacency_matrix;

public:

    // acest constructor creeaza un obiect DSM cu un numar specificat de elemente, fara a specifica numele fiecarui element si intializeaza matricea de adiacenta
    // nu exista legaturi intre elemente la inceput
    DSM(int element_count);

    // acest constructor creeaza un obiect DSM cu un vector dat de nume de elemente si creeaza o matrice de adiacenta baza pe acest vector de nume
    // nu exista legaturi intre elemente la inceput
    DSM(std::vector<std::string> element_names);

    // destructor, elibereaza resursele utilizate de obiectele de tip DSM
    ~DSM();

    // constructor care face o copie a unui obiect DSM existent
    DSM(const DSM& other);

    // returneaza dimensiunea matricii
    int size() const;

    // primeste un index și returneaza numele elementului corespunzator
    std::string get_name(int index) const;

    // primeste un index si un nume, apoi actualizează numele elementului corespunzător din vector
    void set_element_name(int index, const std::string& name);

    // primeste doua nume de elemente si un pondere și adauga o conexiune intre aceste doua elemente in matricea de adiacenta
    void add_link(const std::string& from_element, const std::string& to_element, float weight);

    // primeste doua nume de elemente si elimina conexiunea dintre acestea din matrice
    void delete_link(const std::string& from_element, const std::string& to_element);

    // primeste doua elemente si verifica daca exista o conexiune intre ele
    bool have_link(const std::string& from_element, const std::string& to_element) const;

    // primeste doua elemente si returneaza conexiunea dintre acestea
    float link_weight(const std::string& from_element, const std::string& to_element) const;

    // returneaza numarul de legături care duc catre un element dat ca parametru
    int count_to_links(const std::string& element_name) const;

    // returneaza numarul de legaturi care pornesc de la un element dat ca parametru
    int count_from_links(const std::string& element_name) const;

    // returneaza numarul total de legaturi
    int count_all_links() const;

    // metoda pentru afisarea numelor elementelor
    void print_element_names() const;

    // metoda pentru afisarea matricei de adiacenta
    void print_matrix() const;
};

#endif