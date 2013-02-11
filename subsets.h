//============================================================================
// Name        : subsets.h
// Author      : Anna Dackiewicz
// Description : Generating all subsets of a given set.
//============================================================================

#include <set>
#include <vector>

using namespace std;

// Generating subsets iterating through already generated subsets adding another
// element from the given set (theSet).
vector<set<char> > generateSubsets (set<char> theSet);
