
#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <cmath>
#include <stdlib.h>
#include <time.h>

#include "clause.h"
#include "varinfo.h"

using namespace std;

#ifndef INTER_H
#define INTER_H

class Interpretation
{
    private: 

		// PRIVATE VARIABLES: ----------------------------------------------------------------------
        
		vector<int> variables;
		
		int variableChanged;
		bool hasHeuristicallyPropagated;
		
		// PRIVATE FUNCTIONS: ----------------------------------------------------------------------
		
		int Sign(int a);

    public:
		
        Interpretation(int size);
		Interpretation(vector<int> variables);

		void HeuristicPropagation(vector<Clause>& clauses, VariablesInfo& variablesInfo, vector< list<int> >& varReferences);
		
		bool UnitPropagation(vector<Clause>& clauses, vector< list<int> >& varReferences);
		
		bool IsSat(vector<Clause>& clauses);
		
		bool HasHeuristicallyPropagated();
		
		vector<int> GetNextWorst();
		vector<int> GetNextBest();
        
        // GETTERS: --------------------------------------------------------------------------------
        
		vector<int> GetInterpretation();
};

#endif;