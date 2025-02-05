#include "SortedSetIterator.h"
#include <exception>

using namespace std;
//O(H)- avg
//Theta(H)- worst
//Theta(1)-best
void SortedSetIterator::pushLeft(int nodeIndex) {
    int currentParser = nodeIndex;
    while(currentParser != -1){
        this->current.value = this->multime.values[currentParser];
        this->current.left = this->multime.nextLeft[currentParser];
        this->current.right = this->multime.nextRight[currentParser];
        this->current.currentIndex = currentParser;
        this->stack.push(this->multime.values[currentParser] , this->multime.nextLeft[currentParser] , this->multime.nextRight[currentParser]);
        currentParser = this->multime.nextLeft[currentParser];
    }
    this->stack.pop();
}

//O(H)- avg
//Theta(H)- worst
//Theta(1)-best
SortedSetIterator::SortedSetIterator(const SortedSet &m) : multime(m) {
    this->stack = Stack();
    this->current = TreeNode();
    this->current.value = NULL_TELEM;
    this->first();
}

//O(H)- avg
//Theta(H)- worst
//Theta(1)-best
void SortedSetIterator::first() {
    while(!this->stack.isEmpty()){
        this->stack.pop();
    }
    this->pushLeft(this->multime.head);
}

//O(H)- avg
//Theta(H)- worst
//Theta(1)-best
void SortedSetIterator::next() {
    if(valid()){
        //check if there is anything on the right
       if(this->current.right!= -1){
           this->current.currentIndex = this->current.right;
           this->current.value = this->multime.values[this->current.currentIndex];
           this->current.right = this->multime.nextRight[this->current.currentIndex];
           this->current.left = this->multime.nextLeft[this->current.currentIndex];
           this->pushLeft(this->current.currentIndex);
           return;
       }
       else{
           this->current = this->stack.pop();
           return;
       }
    }
    else{
        throw exception();
    }
}


TElem SortedSetIterator::getCurrent() {
    if(this->valid()){
        return this->current.value;
    }
    else{
        throw exception();
    }
}

bool SortedSetIterator::valid() const {
    if(this->current.value == NULL_TELEM && this->stack.isEmpty()) {
        return false;
    }
    return true;
}

