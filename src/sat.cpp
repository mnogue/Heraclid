
#include "sat.h"

// CONSTRUCTOR: ------------------------------------------------------------------------------------

SAT::SAT()
{
    this->isSat = false;
}

// ISSAT: ------------------------------------------------------------------------------------------

bool SAT::IsSat()
{
	while (not this->isSat)
	{
		if (this->interpretations.empty()) return false;
		
		Interpretation currentInterpretation = this->interpretations.top();
		this->interpretations.pop();
		
		if (not currentInterpretation.UnitPropagation(this->clauses, this->varReferences)) continue;
		currentInterpretation.HeuristicPropagation(this->clauses, this->variablesInfo, this->varReferences);
		
		if (currentInterpretation.IsSat(this->clauses)) 
		{
			this->model = currentInterpretation.GetInterpretation();
			this->isSat = true;
		}
		
		if (currentInterpretation.HasHeuristicallyPropagated())
		{
			this->interpretations.push( Interpretation(currentInterpretation.GetNextWorst()) );
			this->interpretations.push( Interpretation(currentInterpretation.GetNextBest())  );
		}
	}
	
	return true;
}

// GETTERS: ----------------------------------------------------------------------------------------

vector<int> SAT::GetModel()
{
	return this->model;
}

// SETTERS: ----------------------------------------------------------------------------------------

void SAT::InsertData(const vector<Clause>& clauses, int variablesSize)
{
	this->clauses = clauses;
	
	Interpretation interpretation = Interpretation(variablesSize);
	this->interpretations.push(interpretation);
	
	this->varReferences = vector< list<int> >(variablesSize);
	this->variablesInfo.SetSize(variablesSize);
	
	int nClauses = this->clauses.size();
	for (int i = 1; i < nClauses; ++i)
	{
		int l1 = abs(this->clauses[i].l1);
		int l2 = abs(this->clauses[i].l2);
		int l3 = abs(this->clauses[i].l3);
		
		this->varReferences[l1].push_back(i);
		this->varReferences[l2].push_back(i);
		this->varReferences[l3].push_back(i);
		
		switch (this->clauses[i].l1 >= 0)
		{
			case true  : this->variablesInfo.AddNumPos(l1); this->variablesInfo.AddSum(l1); break;
			case false : this->variablesInfo.AddNumNeg(l1); this->variablesInfo.AddSum(l1); break;
		}
		
		switch (this->clauses[i].l2 >= 0)
		{
			case true  : this->variablesInfo.AddNumPos(l2); this->variablesInfo.AddSum(l2); break;
			case false : this->variablesInfo.AddNumNeg(l2); this->variablesInfo.AddSum(l2); break;
		}
		
		switch (this->clauses[i].l3 >= 0)
		{
			case true  : this->variablesInfo.AddNumPos(l3); this->variablesInfo.AddSum(l3); break;
			case false : this->variablesInfo.AddNumNeg(l3); this->variablesInfo.AddSum(l3); break;
		}
		
		this->variablesInfo.SetIndex(l1, l1);
		this->variablesInfo.SetIndex(l2, l2);
		this->variablesInfo.SetIndex(l3, l3);
	}
	
	this->variablesInfo.Sort();
}
