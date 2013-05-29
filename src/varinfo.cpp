
#include "varinfo.h"

VariablesInfo::VariablesInfo() { }

// SORT METHOD: ------------------------------------------------------------------------------------

void VariablesInfo::Sort()
{
	sort (this->variablesInfo.begin()+1, this->variablesInfo.end(), VarInfoComparator());
}

int VariablesInfo::Max(vector<int>& variables)
{
	VarInfo max = this->variablesInfo[0];
	int nVariables = this->variablesInfo.size();
	
	for (int i = 1; i < nVariables; ++i)
	{
		if (variables[i] == 0) max = std::min(this->variablesInfo[i], max, VarInfoComparator());
		
	}
	
	return max.index;
}

// GETTERS: ----------------------------------------------------------------------------------------

int VariablesInfo::GetNumPos(int i)  { return this->variablesInfo[i].numPositives; }
int VariablesInfo::GetNumNeg(int i)  { return this->variablesInfo[i].numNegatives; }
int VariablesInfo::GetSum(int i)     { return this->variablesInfo[i].sum;          }
int VariablesInfo::GetIndex(int i)   { return this->variablesInfo[i].index;        }
int VariablesInfo::GetDiffAbs(int i) { return abs(this->variablesInfo[i].numPositives - this->variablesInfo[i].numNegatives); }

// SETTERS: ----------------------------------------------------------------------------------------

void VariablesInfo::SetNumPos(int i, int v) { this->variablesInfo[i].numPositives = v; }
void VariablesInfo::SetNumNeg(int i, int v) { this->variablesInfo[i].numNegatives = v; }
void VariablesInfo::SetSum(int i,    int v) { this->variablesInfo[i].sum          = v; }
void VariablesInfo::SetIndex(int i,  int v) { this->variablesInfo[i].index        = v; }

void VariablesInfo::SetSize(int size) { this->variablesInfo = vector<VarInfo>(size, VarInfo()); }

void VariablesInfo::AddNumPos(int i) { this->variablesInfo[i].numPositives += 1; }
void VariablesInfo::AddNumNeg(int i) { this->variablesInfo[i].numNegatives += 1; }
void VariablesInfo::AddSum(int i)    { this->variablesInfo[i].sum += 1;          }