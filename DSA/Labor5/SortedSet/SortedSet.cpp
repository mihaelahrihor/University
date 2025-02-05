#include "SortedSet.h"
#include "SortedSetIterator.h"

SortedSet::SortedSet(Relation r) {
    this->relation = r;
    this->length = 0;
    this->capacity = 5;
    this->fullLength = 0;
    this->firstEmpty = 0;
    this->nextLeft = new int[5];
    this->nextRight = new int[5];
    this->values = new TElem[5];
    this->head = -1;
}
//O(N) --avg
//Theta(N)
void SortedSet::goNextEmpty() {
    for (int parser = 0; parser < this->fullLength; parser++) {
        if (this->values[parser] == NULL_TELEM) {
            this->firstEmpty = parser;
            return;
        }
    }
    this->firstEmpty = this->fullLength;
}
//Theta(N)
void SortedSet::resizeUp() {
    if (this->fullLength == this->capacity - 1) {
        this->capacity *= 2;
        TElem *auxValues = new TElem[this->capacity];
        int *auxNextLeft = new int[this->capacity];
        int *auxNextRight = new int[this->capacity];
        for (int parser = 0; parser < this->fullLength; parser++) {
            auxValues[parser] = this->values[parser];
            auxNextLeft[parser] = this->nextLeft[parser];
            auxNextRight[parser] = this->nextRight[parser];
        }

        delete[] this->values;
        delete[] this->nextLeft;
        delete[] this->nextRight;
        this->values = auxValues;
        this->nextLeft = auxNextLeft;
        this->nextRight = auxNextRight;
    }
}
//O(H) --avg
//Theta(N) - worst
// theta(1) - best
bool SortedSet::add(TComp elem) {
    //check if the lists are empty
    this->resizeUp();
    if (this->length == 0) {
        this->values[this->firstEmpty] = elem;
        this->nextLeft[this->firstEmpty] = -1;
        this->nextRight[this->firstEmpty] = -1;
        this->head = 0;
        this->firstEmpty = 1;
        this->length++;
        this->fullLength++;
        return true;
    }

    //we look where do we need to add it

    int currentParser = this->head;
    while (true) {
        if (this->values[currentParser] == elem) {
            return false;
        }
        if (this->relation(elem, this->values[currentParser])) {
            //we go left
            if (this->nextLeft[currentParser] == -1) {
                this->nextLeft[currentParser] = this->firstEmpty;
                this->values[this->firstEmpty] = elem;
                this->nextLeft[this->firstEmpty] = -1;
                this->nextRight[this->firstEmpty] = -1;
                this->length++;
                this->fullLength++;
                this->goNextEmpty();
                return true;
            }
            currentParser = this->nextLeft[currentParser];
        } else {
            //we go right
            if (this->nextRight[currentParser] == -1) {
                this->nextRight[currentParser] = this->firstEmpty;
                this->values[this->firstEmpty] = elem;
                this->nextLeft[this->firstEmpty] = -1;
                this->nextRight[this->firstEmpty] = -1;
                this->length++;
                this->fullLength++;
                this->goNextEmpty();
                return true;
            }
            currentParser = this->nextRight[currentParser];
        }
    }
}

//O(log(N)) - avg
//Theta(N) - worst
//Theta(1) - best
bool SortedSet::remove(TComp elem) {
    if (this->head == -1) {
        return false;
    }

    int currentParser = this->head;
    int previousParser = this->head;
    //check if root
    if(this->values[this->head] == elem){
        //the root has no children

        if(this->nextLeft[this->head] == -1 && this->nextRight[this->head] == -1){
            this->values[this->head] = NULL_TELEM;
            this->head = -1;
            this->firstEmpty = 0;
            this->length--;
            return true;
        }

        //root has one child

        //on the right
        if(this->nextLeft[this->head] == -1 && this->nextRight[this->head] != -1){
            this->values[this->head] = NULL_TELEM;
            this->firstEmpty = this->head;
            this->head = this->nextRight[this->head];
            this->length--;
            return true;
        }

        //on the left
        if(this->nextLeft[this->head] != -1 && this->nextRight[this->head] == -1){
            this->values[this->head] = NULL_TELEM;
            this->firstEmpty = this->head;
            this->head = this->nextLeft[this->head];
            this->length--;
            return true;
        }

        //root has 2 children

        //we go one right
        currentParser = this->nextRight[this->head];
        previousParser = this->head;

        //and then max left
        while(this->nextLeft[currentParser] != -1){
            previousParser = currentParser;
            currentParser = this->nextLeft[currentParser];
        }

        //found the element and we need to check

        //switch elements
        TElem auxELements = this->values[this->head];
        this->values[this->head] = this->values[currentParser];
        this->values[currentParser] = auxELements;

        //verify:

        //no children

        if(this->nextLeft[currentParser] == -1 && this->nextRight[currentParser] == -1){
            this->values[currentParser] = NULL_TELEM;
            this->firstEmpty = currentParser;
            this->nextLeft[previousParser] = -1;
            this->length--;
            return true;
        }

        //has one child

        //can be only on the right

        if(this->nextRight[currentParser] != -1){
            this->values[currentParser] = NULL_TELEM;
            this->firstEmpty = currentParser;
            this->nextLeft[previousParser] = this->nextRight[currentParser];
            this->length--;
            return true;
        }


    }
    currentParser = this->head;
    previousParser = this->head;

    while (currentParser != -1) {

        if (this->relation(elem, this->values[currentParser])) {
            //we go left
            previousParser = currentParser;
            currentParser = this->nextLeft[currentParser];
            if (this->values[currentParser] == elem) {
                //the element has no children
                if (this->nextRight[currentParser] == -1 && this->nextLeft[currentParser] == -1) {

                    this->values[currentParser] = NULL_TELEM;
                    this->length--;
                    this->firstEmpty = currentParser;
                    this->nextLeft[previousParser] = -1;
                    return true;
                }

                //the element has one child

                //child on the right
                if (this->nextLeft[currentParser] == -1 && this->nextRight[currentParser] != -1) {
                    this->values[currentParser] = NULL_TELEM;
                    this->length--;
                    this->firstEmpty = currentParser;
                    this->nextLeft[previousParser] = this->nextRight[currentParser];
                    return true;
                }
                //child on the left
                if (this->nextRight[currentParser] == -1 && this->nextLeft[currentParser] != -1) {
                    this->values[currentParser] = NULL_TELEM;
                    this->length--;
                    this->firstEmpty = currentParser;
                    this->nextLeft[previousParser] = this->nextLeft[currentParser];
                    return true;
                }

                //has 2 children
                //we go one step right and then full left
                int newpreviousParser = currentParser;
                int newCurrentParser = this->nextRight[currentParser];
                while (this->nextLeft[currentParser] != -1) {
                    newpreviousParser = newCurrentParser;
                    newCurrentParser = this->nextLeft[newCurrentParser];
                }
                //found the element at newCurrentParser

                //we switch the elements
                TElem auxElement = this->values[currentParser];
                this->values[currentParser] = this->values[newCurrentParser];
                this->values[newCurrentParser] = auxElement;

                //check if the element we switched has no children
                //there is no left child because we already go max left
                if (this->nextRight[newCurrentParser] == -1) {
                    this->values[newCurrentParser] = NULL_TELEM;
                    this->nextLeft[newpreviousParser] = -1;
                    this->length--;
                    this->firstEmpty = newCurrentParser;
                    return true;
                }

                //there is a child on the right
                this->values[newCurrentParser] = NULL_TELEM;
                this->nextLeft[newpreviousParser] = this->nextRight[currentParser];
                this->length--;
                this->firstEmpty = newCurrentParser;
                return true;
            }
        } else {
            //we go right
            previousParser = currentParser;
            currentParser = this->nextRight[currentParser];
            if (this->values[currentParser] == elem) {
                //found element

                //the element has no children
                if (this->nextLeft[currentParser] == -1 && this->nextRight[currentParser] == -1) {
                    this->values[currentParser] = NULL_TELEM;
                    this->nextRight[previousParser] = -1;
                    this->length--;
                    this->firstEmpty = currentParser;
                    return true;
                }

                //there is only one child

                //on the left
                if (this->nextLeft[currentParser] != -1 && this->nextRight[currentParser] == -1) {
                    this->values[currentParser] = NULL_TELEM;
                    this->nextRight[previousParser] = this->nextLeft[currentParser];
                    this->length--;
                    this->firstEmpty = currentParser;
                    return true;
                }

                //on the right
                if (this->nextLeft[currentParser] == -1 && this->nextRight[currentParser] != -1) {
                    this->values[currentParser] = NULL_TELEM;
                    this->nextRight[previousParser] = this->nextRight[currentParser];
                    this->length--;
                    this->firstEmpty = currentParser;
                    return true;
                }

                //there are 2 children

                //we go one right and then max left

                int newpreviousParser = currentParser;
                int newCurrentParser = this->nextRight[currentParser];

                while (this->nextLeft[currentParser] != -1) {
                    newpreviousParser = newCurrentParser;
                    newCurrentParser = this->nextLeft[newCurrentParser];
                }

                //we switch the elements
                TElem auxElement = this->values[currentParser];
                this->values[currentParser] = this->values[newCurrentParser];
                this->values[newCurrentParser] = auxElement;

                //the element found has

                //check if the element we switched has no children
                //there is no left child because we already go max left
                if (this->nextRight[newCurrentParser] == -1) {
                    this->values[newCurrentParser] = NULL_TELEM;
                    this->nextLeft[newpreviousParser] = -1;
                    this->length--;
                    this->firstEmpty = newCurrentParser;
                    return true;
                }

                //there is a child on the right
                this->values[newCurrentParser] = NULL_TELEM;
                this->nextLeft[newpreviousParser] = this->nextRight[currentParser];
                this->length--;
                this->firstEmpty = newCurrentParser;
                return true;
            }
        }
    }
    return false;
}

//O(H) - avg
//Theta(N) - worst
//Theta(1) - best
bool SortedSet::search(TComp elem) const {
    int currentParser = this->head;
    if (this->length == 0) {
        return false;
    }
    int counter = 0;
    while (currentParser != -1) {
        if (this->values[currentParser] == elem) {
            return true;
        }
        if (counter > this->length) {
            return false;
        }
        if (this->relation(elem, this->values[currentParser])) {
            //we go left
            currentParser = this->nextLeft[currentParser];
        } else {
            //we go right
            currentParser = this->nextRight[currentParser];
        }
        counter++;

    }
    return false;
}

//Theta(1)
int SortedSet::size() const {
    return this->length;
}

//Theta(1)
bool SortedSet::isEmpty() const {
    if (this->length == 0) {
        return true;
    }
    return false;
}

//Theta(1)
SortedSetIterator SortedSet::iterator() const {
    return SortedSetIterator(*this);
}

//Theta(1)
SortedSet::~SortedSet() {
    delete[] this->values;
    delete[] this->nextRight;
    delete[] this->nextLeft;
}


////functie suplimentara
//
//bool SortedSet::operator==(const SortedSet& other) const {
//    if (this->size() != other.size()) {
//        return false;
//    }
//
//    SortedSetIterator it1 = this->iterator();
//    SortedSetIterator it2 = other.iterator();
//
//    it1.first();
//    it2.first();
//
//    while (it1.valid() && it2.valid()) {
//        if (it1.getCurrent() != it2.getCurrent()) {
//            return false;
//        }
//        it1.next();
//        it2.next();
//    }
//
//    return !it1.valid() && !it2.valid();
//}