#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h>

using namespace std;

#ifndef CLAUSE_H
#define CLAUSE_H

class Clause
{
    public:
		
		// VARIABLES: ------------------------------------------------------------------------------
		
		int l1;
		int l2;
		int l3;
		
		// CONSTRUCTOR: ----------------------------------------------------------------------------
		
        Clause();
        
        // GETTERS: --------------------------------------------------------------------------------
        
		bool IsComplete(const vector<int>& variables);

		bool EvalClause(const vector<int>& variables);
		
		int UnitPropagate(vector<int>& variables);
		
		int CountUndefined(const vector<int>& variables);
};

#endif;