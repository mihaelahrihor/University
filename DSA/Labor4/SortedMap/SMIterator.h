#pragma once
#include "SortedMap.h"

//DO NOT CHANGE THIS PART
class SMIterator{
	friend class SortedMap;
private:
	const SortedMap& map;
	SMIterator(const SortedMap& mapionar);

	//TODO - Representation

    std::pair<TKey, TValue>* sortedElements;
    int currentIndex;
    int arrSize;

public:
	void first();
	void next();
	bool valid() const;
    TElem getCurrent() const;
    void mergeSort();
    void mergeSortRecursion(TElem* sortedElements, int left, int right);
    void merge(TElem* sortedElements, int left, int mid, int right);};


