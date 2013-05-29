
#include "../interpretation.h"

void Interpretation::HeuristicPropagation(vector<Clause>& clauses, VariablesInfo& variablesInfo, vector< list<int> >& varReferences)
{
    this->variableChanged = 0;
	this->hasHeuristicallyPropagated = true;
	
	int nVariables = this->variables.size();
	int nClauses = clauses.size();
	
	VariablesInfo dynVariablesInfo;
	dynVariablesInfo.SetSize(nVariables);

	for (int i = 1; i < nClauses; ++i)
	{
		bool clauseSat = clauses[i].EvalClause(this->variables);
		if (clauseSat) continue;
		
		int l1 = abs(clauses[i].l1);
		int l2 = abs(clauses[i].l2);
		int l3 = abs(clauses[i].l3);
		
		switch (clauses[i].l1 >= 0)
		{
			case true  : dynVariablesInfo.AddNumPos(l1); dynVariablesInfo.AddSum(l1); break;
			case false : dynVariablesInfo.AddNumNeg(l1); dynVariablesInfo.AddSum(l1); break;
		}
		
		switch (clauses[i].l2 >= 0)
		{
			case true  : dynVariablesInfo.AddNumPos(l2); dynVariablesInfo.AddSum(l2); break;
			case false : dynVariablesInfo.AddNumNeg(l2); dynVariablesInfo.AddSum(l2); break;
		}
		
		switch (clauses[i].l3 >= 0)
		{
			case true  : dynVariablesInfo.AddNumPos(l3); dynVariablesInfo.AddSum(l3); break;
			case false : dynVariablesInfo.AddNumNeg(l3); dynVariablesInfo.AddSum(l3); break;
		}
		
		dynVariablesInfo.SetIndex(l1, l1);
		dynVariablesInfo.SetIndex(l2, l2);
		dynVariablesInfo.SetIndex(l3, l3);
	}
	
	this->variableChanged = dynVariablesInfo.Max(this->variables);

	if (this->variableChanged == -1) this->hasHeuristicallyPropagated = false;
}

bool Interpretation::UnitPropagation(vector<Clause>& clauses, vector< list<int> >& varReferences)
{
	list<int>::iterator it;
	stack<int> propagatedIndexes;
	propagatedIndexes.push(abs(this->variables[0]));
	vector<bool> alreadyPropagated(this->variables.size(), false);
	
	while (not propagatedIndexes.empty())
	{
		int propagatedIndex = propagatedIndexes.top();
		propagatedIndexes.pop();
		
		for (it = varReferences[propagatedIndex].begin(); it != varReferences[propagatedIndex].end(); it++)
		{
			bool isComplete = clauses[*it].IsComplete(this->variables);
			bool clauseSat  = clauses[*it].EvalClause(this->variables);
			if (isComplete and not clauseSat) return false;

			int index = clauses[*it].UnitPropagate(this->variables);
			
			if (index != 0 and not alreadyPropagated[index])
			{
				propagatedIndexes.push(index);
				alreadyPropagated[index] = true;
			}
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
	this->variables[0] = abs(this->variableChanged);
	return this->variables;
}

vector<int> Interpretation::GetNextWorst()
{
	this->variables[abs(this->variableChanged)] = this->Sign(this->variableChanged) * -1;
	this->variables[0] = abs(this->variableChanged);
	return this->variables;
}
