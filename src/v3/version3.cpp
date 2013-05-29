
#include "../interpretation.h"

void Interpretation::HeuristicPropagation(vector<Clause>& clauses, VariablesInfo& variablesInfo, vector< list<int> >& varReferences)
{
	this->variableChanged = 0;
	this->hasHeuristicallyPropagated = true;
	
	int nVariables = this->variables.size();
	for (int i = 1; i < nVariables; ++i)
	{
		int currentVariable = variablesInfo.GetIndex(i);
		if (this->variables[currentVariable] == 0)
		{
			int numPos = variablesInfo.GetNumPos(i);
			int numNeg = variablesInfo.GetNumNeg(i);
			this->variableChanged = currentVariable * (numPos >= numNeg ? 1 : -1);
			return;
		}
	}
	
	this->hasHeuristicallyPropagated = false;
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
