#pragma once
#include "SortedMap.h"

//DO NOT CHANGE THIS PART
class SMIterator{
	friend class SortedMap;
private:
	const SortedMap& map;
	SMIterator(const SortedMap& mapionar);
    int current; // pozitia elementului curent din map

public:
	void first();
	void next();
	bool valid() const;
    TElem getCurrent() const;
//    void moveForward(int steps);
//    void moveback(int steps);
};

