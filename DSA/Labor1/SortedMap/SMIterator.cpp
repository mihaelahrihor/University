#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>

using namespace std;

SMIterator::SMIterator(const SortedMap& m) : map(m){
	//TODO - Implementation
    this->current=0;
}
//Theta(1)

void SMIterator::first(){
	//TODO - Implementation
    this->current=0;
}
//Theta(1)

void SMIterator::next(){
	//TODO - Implementation
    if(this->current== this->map.nrPairs){
        throw exception();
    } else{
        this->current++;
    }

}
//Theta(1)

bool SMIterator::valid() const{
	//TODO - Implementation

    return current>=0 && current<map.nrPairs;
}
//Theta(1)

TElem SMIterator::getCurrent() const{
	//TODO - Implementation
    if(this->current == this->map.nrPairs){
        throw exception();
    }
    return this->map.elements[this->current];
}
//Theta(1);

//void SMIterator::moveForward(int steps) {
//    for (int i = 0; i < steps; i++) {
//        if (!valid()) {
//            throw exception();
//        }
//        current++;
//    }
//}

//Theta(steps)

//void SMIterator::moveback(int steps) {
//    for (int i = 0; i < steps; i++) {
//        if (!valid()) {
//            throw exception();
//        }
//        current--;
//    }
//
//}
