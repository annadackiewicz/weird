//============================================================================
// Name        : interesting.cpp
// Author      : Anna Dackiewicz
// Description : Interesting implementations of normal problems.
//============================================================================

#include "subsets.h"

#include <iostream>


int main() {
	cout << "Interesting implementations" << endl; // prints Interesting implementations

	set<char> theSet;
	theSet.insert('a');
	theSet.insert('b');
	theSet.insert('c');

	vector<set<char> > generated =  generateSubsets(theSet);
	cout << generated.size() << endl;

	return 0;
}
