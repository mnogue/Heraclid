
#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <cmath>
#include <stdlib.h>
#include <time.h>

#include "clause.h"
#include "interpretation.h"
#include "varinfo.h"

using namespace std;

#ifndef SAT_H
#define SAT_H

////////////////////////////////////////////////////////////////////////////////////////////////////
// SAT CLASS: --------------------------------------------------------------------------------------

class SAT
{
    private: 
		
        // PRIVATE VARIABLES: ----------------------------------------------------------------------
        
        vector<int>           model;
		vector<Clause>        clauses;
		stack<Interpretation> interpretations;
		vector< list<int> >   varReferences;
		
        bool isSat;

		VariablesInfo variablesInfo;
		
    public:
		
        SAT();
        
        // SAT-SOLVER: -----------------------------------------------------------------------------
        
        bool IsSat();
        
        // GETTERS: --------------------------------------------------------------------------------
		
		vector<int> GetModel();
        
        // SETTERS: --------------------------------------------------------------------------------
        
        void InsertData(const vector<Clause>& clauses, int variablesSize);
};

#endif;