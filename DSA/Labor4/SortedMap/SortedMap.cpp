#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
#include <iostream>
using namespace std;


SortedMap::SortedMap(Relation r) {
	//TODO - Implementation
    this->r = r;
    this->mSize = 0;
    this->cap = 10;
    this->T = new Node*[cap];
    for (int i = 0; i < cap; i++) {
        this->T[i] = nullptr;
    }
}
//Theta(n)


int SortedMap::hashFunction(TKey key) const {
    return abs(key) % cap;
}
//Theta(1)

TValue SortedMap::add(TKey c, TValue v) {
	//TODO - Implementation
    if (mSize + 1 >= cap * 0.7) {
        resizeUp();
    }

    int index = hashFunction(c);

    //se creeaza nod nou
    Node* newNode = new Node;
    newNode->key = c;
    newNode->value = v;
    newNode->next = nullptr;

    //Adaugarea in Hash.T
    if (T[index] == nullptr) {
        T[index] = newNode;
        mSize++;
        return NULL_TVALUE;
    } else {

        //Tratarea coliziunilor

        Node* current = T[index];
        Node* prev = nullptr;
        while (current != nullptr && !r(current->key, c)) {
            prev = current;
            current = current->next;
        }

        //Actualizarea valorii daca cheia exista deja

        if (current->key == c) {
            TValue old_value = current->value;
            current->value = v;
            return old_value;
        }

        //Inserarea noului nod in lista inlantuita
        if (prev == nullptr) {
            newNode->next = T[index];
            T[index] = newNode;
            mSize++;
            return NULL_TVALUE;
        } else {
            prev->next = newNode;
            newNode->next = current;
            mSize++;
            return NULL_TVALUE;
        }
    }
    mSize++;
}
//Best case:Theta(1)
//Worst case: O(n)
//Average case: Theta(n)
//Complexitate generala: O(n)

TValue SortedMap::search(TKey c) const {
	//TODO - Implementation
    int index = hashFunction(c);
    Node* current = T[index];
    while (current != nullptr) {
        if (current->key == c) {
            return current->value;
        }
        current = current->next;
    }


    return NULL_TVALUE;
}
//Best case: Theta(1)
//Worst case: O(n)
//Average case: Theta(n)
//General complexity: O(n)

TValue SortedMap::remove(TKey c) {
	//TODO - Implementation
    int index = hashFunction(c);
    Node* current = T[index];
    Node* prev = nullptr;

    while (current != nullptr) {
        if (current->key == c) {
            TValue value = current->value;

            //daca nodul curent este primul din lista
            if (prev == nullptr) {
                T[index] = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            mSize--;
            return value;
        }
        prev = current;
        current = current->next;
    }
    return NULL_TVALUE;
}

//Best case: Theta(1)
//Worst case: O(n)
//Average case: theta(n)
//General complexity: O(n)

int SortedMap::size() const {
	//TODO - Implementation
    return mSize;
}
//Theta (1)

bool SortedMap::isEmpty() const {
	//TODO - Implementation
    return mSize == 0;
}
//Theta(1)

SMIterator SortedMap::iterator() const {
	return SMIterator(*this);
}
//Theta(1)

SortedMap::~SortedMap() {
	//TODO - Implementation
    for (int i = 0; i < cap; ++i) {
        Node* current = T[i];
        while (current != nullptr) {
            Node* nodeToDelete = current;
            current = current->next;
            delete nodeToDelete;
        }
    }
    delete[] T;
}
//Theta(n)

void SortedMap::resizeUp() {
    int newCapacity = cap * 2;
    Node** newHashTable = new Node*[newCapacity];
    for (int i = 0; i < newCapacity; ++i) {
        newHashTable[i] = nullptr;
    }

    for (int i = 0; i < cap; ++i) {
        Node* current = T[i];
        while (current != nullptr) {
            Node* next = current->next;
            int newIndex = hashFunction(current->key) % newCapacity;
            current->next = newHashTable[newIndex];
            newHashTable[newIndex] = current;
            current = next;
        }
    }

    delete[] T;
    T = newHashTable;
    cap = newCapacity;
}


SortedMap SortedMap::filterByKeys(TKey a, TKey b) const {

    SortedMap newMap(this->r);

    for (int i = 0; i < this->cap; ++i) {
        Node* current = this->T[i];
        while (current != nullptr) {
            if (current->key >= a && current->key <= b) {
                newMap.add(current->key, current->value);
            }
            current = current->next;
        }
    }

    return newMap;
}


//Specificatii:

//pre-order:
//-existenta unui Sorted map valid
//-a si b trebuie sa fie valide

//in-order:
//va returna o noua instanta map, care va contine doar elem cu cheile cuprinse intre a si b

//Pseudocod:
//for(int i=0;i,this->cap;i++){
//Node->current= this<-T[i]
// while(current != nullptr){
//if(current<-key >= a && current<-key <=b){
//  newMap.add(current<-key, current<-value);}
//current=current<-next;}}
//return newMap;}
