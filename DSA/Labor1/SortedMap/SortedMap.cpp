#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
using namespace std;

//14.  SortedMap – repräsentiert mithilfe eines dynamischen Arrays von Paaren der Form
//(key, value) und sortiert mithilfe einer Relation auf den Schlüsseln(key)


SortedMap::SortedMap(Relation r) {
	//TODO - Implementation
    this->nrPairs=0;
    this->rel=r;
    this->capacity=1;
    this->elements= new TElem [this->capacity];//alocarea memoriei pt array dinamic
}
//Theta(1)-nu depinde de dimensiune, si nu exista structuri repetitive

void SortedMap::resize() {
    int index;
    auto * newElems = new TElem[this->capacity * 2];
    for (index = 0; index < this->nrPairs; index++) {
        newElems[index] = this->elements[index];
    }
    delete[] this->elements;
    this->elements = newElems;
    this->capacity *= 2;
}
//Theta(nrPairs)


TValue SortedMap::add(TKey k, TValue v) {
    //TODO - Implementation
    TValue returned= NULL_TVALUE;
    int index;

    //check if it is full
    if(this->capacity == this->nrPairs){
        this->resize();
    }


    bool found = false;//local variable
    index = 0;//local variable

    //cauta cheia k in elementele existente
    while (!found && index < this->nrPairs && this->rel(elements[index].first,k)){

        //se verifica daca exista un elem cu aceeasi cheie
        if (this->elements[index].first==k){
            found= true;
            returned = this->elements[index].second;
            this->elements[index].second=v;//se actualizeaza valoarea
        }
        else
            index++;
    }

    //daca cheia nu exista, se insereaza o noua cheie mutand elem. spre dreapta
    if (!found){
        if (this->nrPairs > 0){
            for(int i= this->nrPairs;i>index;i--)
                this->elements[i]= this->elements[i-1];
        }
        this->elements[index].first=k;
        this->elements[index].second=v;
        this->nrPairs++;

    }
    return returned;
}
//Best case: Theta(1)(cheia exista pe prima poz.), worst case: Theta(nrPairs)-> General complexitat: Theta(nrPairs)(cand cheia de inserat este mai mare decat toate cheile)

TValue SortedMap::search(TKey k) const {
	//TODO - Implementation

    TValue returned= NULL_TVALUE;
    bool found= false;
    int index=0;

    //se executa cat timp cheia nu a fost gasita
    while(!found && index< this->nrPairs  && this->rel(this->elements[index].first,k)){

        //verif. daca cheia cautata coincide cu k
        if(this->elements[index].first==k){
            found= true;
            returned= this->elements[index].second;
        } else
            index++;

    }


	return returned;
}
//Best case: Theta(1)-[elementul cautat e pe prima poz]
//Worst case: Theta(nrpairs)-[elementul cautat este pe ultima poz sau nu exista]

TValue SortedMap::remove(TKey k) {

    int index = 0;
    bool found = false;
    TValue returned = NULL_TVALUE;
    while (index<this->nrPairs && !found && this->rel(this->elements[index].first, k)) {
        if (this->elements[index].first == k) {
            returned = this->elements[index].second;
            found = true;
        }else
            index++;
    }

    //daca cheia a fost gasita, va fi stearsa
    if (found) {
        for (int i = index; i < this->nrPairs - 1; i++) //mutarea elementelor de la dreapta spre stanga(supracriere)
            this->elements[i] = this->elements[i+1];
        this->nrPairs--;
    }
    return returned;
}
//Best case: Theta(nrPairs) [depinde direct de nr total de perechi din map]
// worst case: Theta(nrPairs) -> General complexity: Theta(nrPairs)


int SortedMap::size() const {
    return this->nrPairs;
}
//Theta(1)


bool SortedMap::isEmpty() const {
    if (this->nrPairs == 0) {
        return true;
    }
    return false;
}
//Theta(1)


SMIterator SortedMap::iterator() const {
	return SMIterator(*this);
}

SortedMap::~SortedMap() {
	//TODO - Implementation
    delete[] this->elements;
}
//Theta(1)
