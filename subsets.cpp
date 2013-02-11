#include "subsets.h"

vector<set<char> > generateSubsets (set<char> theSet) {
	vector<set<char> > theReturn;
	// Adding an empty set.
	set<char> empty_set;
	theReturn.push_back(empty_set);
	for (set<char>::iterator it = theSet.begin(); it != theSet.end();
			++it) {
		set<char> one_element_set;
		one_element_set.insert(*(it));
		theReturn.push_back(one_element_set);
	}
	for (int it = 1; it < theReturn.size(); ++it) {
		set<char>::iterator it_set = theSet.find(*(theReturn[it].rbegin()));
		++it_set;

		while (it_set != theSet.end()) {
			set<char> added = theReturn[it];
			added.insert(*it_set);

			theReturn.push_back(added);
			++it_set;
		}
	}
	return theReturn;
}

vector<set<char> > generateSubsetsRecursion(set<char> theSet,
		set<char> alreadyGenerated) {
	vector<set<char> > theReturn;
	set<char>::iterator iter = theSet.begin();
	if (!alreadyGenerated.empty()) {
		iter = theSet.find(*(alreadyGenerated.rbegin()));
		++iter;
	} else {
		set<char> empty;
		theReturn.push_back(empty);
	}
	if (iter == theSet.end()) {
		return theReturn;
	}
	for (; iter != theSet.end(); ++iter) {
		set<char> newlyGenerated = alreadyGenerated;
		newlyGenerated.insert(*iter);
		theReturn.push_back(newlyGenerated);
		vector<set<char> > lowerNewlyGenerated =
				generateSubsetsRecursion(theSet, newlyGenerated);
		for (vector<set<char> >::iterator it = lowerNewlyGenerated.begin();
				it != lowerNewlyGenerated.end(); ++it) {
			theReturn.push_back(*it);
		}
	}
	return theReturn;
}
