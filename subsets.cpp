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
