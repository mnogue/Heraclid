
#include "../interpretation.h"

void Interpretation::HeuristicPropagation(vector<Clause>& clauses, VariablesInfo& variablesInfo, vector< list<int> >& varReferences)
{
	this->variableChanged = 0;
	this->hasHeuristicallyPropagated = true;
	int nClauses = clauses.size();
	
	for (int i = 1; i < nClauses; ++i)
	{
		if (not clauses[i].IsComplete(this->variables) and not clauses[i].EvalClause(this->variables))
		{
			if      (this->variables[abs(clauses[i].l1)] == 0) this->variableChanged = clauses[i].l1;
			else if (this->variables[abs(clauses[i].l2)] == 0) this->variableChanged = clauses[i].l2;
			else if (this->variables[abs(clauses[i].l3)] == 0) this->variableChanged = clauses[i].l3;
			if (this->variableChanged != 0) return;
		}
	}
	
	this->hasHeuristicallyPropagated = false;
}

bool Interpretation::UnitPropagation(vector<Clause>& clauses, vector< list<int> >& varReferences)
{
	int nClauses = clauses.size();
	for (int i = 1; i < nClauses; ++i)
	{
		// check contradictions:
		bool isComplete = clauses[i].IsComplete(this->variables);
		bool clauseSat  = clauses[i].EvalClause(this->variables);
		if (isComplete and not clauseSat) return false;
		
		if (not clauseSat)
		{
			int index = clauses[i].UnitPropagate(this->variables);
			if (index != 0) i = 1;
		}
	}
	
	return true;
}

bool Interpretation::IsSat(vector<Clause>& clauses)
{
	int nClauses = clauses.size();
	for (int i = 1; i < nClauses; ++i)
	{
		if (not clauses[i].EvalClause(this->variables)) return false;
	}
	
	return true;
}

bool Interpretation::HasHeuristicallyPropagated()
{
	return this->hasHeuristicallyPropagated;
}

vector<int> Interpretation::GetNextBest()
{
	this->variables[abs(this->variableChanged)] = this->Sign(this->variableChanged);
	return this->variables;
}

vector<int> Interpretation::GetNextWorst()
{
	this->variables[abs(this->variableChanged)] = this->Sign(this->variableChanged) * -1;
	return this->variables;
}
