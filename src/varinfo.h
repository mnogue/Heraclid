
#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <cmath>
#include <algorithm>
#include <stdlib.h>

using namespace std;

#ifndef VINFO_H
#define VINFO_H

////////////////////////////////////////////////////////////////////////////////////////////////////
// SAT CLASS: --------------------------------------------------------------------------------------

class VariablesInfo
{
    private: 
		
        // STRUCTS: --------------------------------------------------------------------------------
        
		struct VarInfo
		{
			int numPositives;
			int numNegatives;
			int sum;
			int index;
			
			VarInfo()
			{
				this->numPositives =  0;
				this->numNegatives =  0;
				this->sum          =  0;
				this->index        = -1;
			}
		};
		
		struct VarInfoComparator
		{ 
			bool operator()(const VarInfo& a, const VarInfo& b) 
			{
				if (a.sum > b.sum) return true;
				if (a.sum < b.sum) return false;
				int pa = abs(a.numPositives - (a.sum/2));
				int pb = abs(b.numPositives - (b.sum/2));
				return pa > pb;
			}
		};
		
		vector<VarInfo> variablesInfo;
		
    public:
		
		// CONSTRUCTOR: ----------------------------------------------------------------------------
		
		VariablesInfo();
		
		// SORT METHOD: ----------------------------------------------------------------------------
		
		void Sort();                                                        /** used in version3 **/
		int  Max(vector<int>& variables);                                   /** used in version4 **/
		
		// GETTERS: --------------------------------------------------------------------------------
		
		int GetNumPos(int i);
		int GetNumNeg(int i);
		int GetSum(int i);
		int GetIndex(int i);
		int GetDiffAbs(int i);
		
		// SETTERS: --------------------------------------------------------------------------------
		
		void SetNumPos(int i, int v);
		void SetNumNeg(int i, int v);
		void SetSum(int i,    int v);
		void SetIndex(int i,  int v);
		
		void SetSize(int size);
		
		void AddNumPos(int i);
		void AddNumNeg(int i);
		void AddSum(int i);
};

#endif;