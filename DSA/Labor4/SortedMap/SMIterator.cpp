#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>

using namespace std;

SMIterator::SMIterator(const SortedMap& m) : map(m){
	//TODO - Implementation
    sortedElements = new std::pair<TKey, TValue>[m.mSize];
    arrSize = 0;

    for (int i = 0; i < map.cap; ++i) {
        Node* current = map.T[i];
        while (current != nullptr) {
            sortedElements[arrSize++] = {current->key, current->value};
            current = current->next;
        }
    }

    if (map.size() == 0) {
        currentIndex = -1;
    } else {
        mergeSort();
        currentIndex = 0;
    }
}
//Theta(n)

void SMIterator::first(){
	//TODO - Implementation
    if (map.size() == 0) {
        currentIndex = -1;
    } else {
        currentIndex = 0;
    }
}
//Theta(1)

void SMIterator::next(){
	//TODO - Implementation
    if (!valid()) {
        throw std::exception();
    }
    currentIndex++;
    if (currentIndex >= arrSize) {
        currentIndex = -1;
    }
}
//Theta(1)

bool SMIterator::valid() const{
	//TODO - Implementation
    return currentIndex != -1;

}
//theta(1)

TElem SMIterator::getCurrent() const{
	//TODO - Implementation
    if (!valid()) {
        throw std::exception();
    }
    return sortedElements[currentIndex];
}
//Theta(1)

void SMIterator::mergeSort() {  //Initializeaza procesul
    mergeSortRecursion(sortedElements, 0, map.mSize - 1);
}
//Theta(1)

void SMIterator::mergeSortRecursion(TElem* sortedElements, int left, int right) { //Imparte probl in subprobeleme
    if (left < right) {
        int mid = (right + left) / 2;
        mergeSortRecursion(sortedElements, left, mid);
        mergeSortRecursion(sortedElements, mid + 1, right);
        merge(sortedElements, left, mid, right);
    }
}
//Theta(1)

void SMIterator::merge(TElem* sortedElements, int left, int mid, int right) { //combina subsecv.
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    //crearea 2 array temporare
    TElem* leftArray = new TElem[leftSize];
    TElem* rightArray = new TElem[rightSize];

    //copierea elem
    for (int i = 0; i < leftSize; i++)
        leftArray[i] = sortedElements[left + i];
    for (int j = 0; j < rightSize; j++)
        rightArray[j] = sortedElements[mid + 1 + j];

    //interclasarea
    int i = 0, j = 0, k = left;
    while (i < leftSize && j < rightSize) {
        if (map.r(leftArray[i].first, rightArray[j].first))
            sortedElements[k++] = leftArray[i++];
        else
            sortedElements[k++] = rightArray[j++];
    }

    while (i < leftSize)
        sortedElements[k++] = leftArray[i++];

    while (j < rightSize)
        sortedElements[k++] = rightArray[j++];

    delete[] leftArray;
    delete[] rightArray;
}


