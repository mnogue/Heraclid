#include "clause.h"

Clause::Clause()
{
	this->l1 = 0;
	this->l2 = 0;
	this->l3 = 0;
}

bool Clause::IsComplete(const vector<int>& variables)
{
	if (variables[abs(this->l1)] == 0) return false;
	if (variables[abs(this->l2)] == 0) return false;
	if (variables[abs(this->l3)] == 0) return false;
	return true;
}

bool Clause::EvalClause(const vector<int>& variables)
{
	int value1 = variables[abs(this->l1)];
    int value2 = variables[abs(this->l2)];
    int value3 = variables[abs(this->l3)];
    value1 *= (l1 >= 0 ? 1 : -1);
    value2 *= (l2 >= 0 ? 1 : -1);
    value3 *= (l3 >= 0 ? 1 : -1);
    if (value1 > 0) return true;
    if (value2 > 0) return true;
    if (value3 > 0) return true;
    return false;
}

int Clause::UnitPropagate(vector<int>& variables)
{
	// no need to propagate if evali(Clause) = sat
	if (this->EvalClause(variables)) return 0;
	
	int zeroCounter = 0;
	int variablePropagated = -1;
	if (variables[abs(this->l1)] == 0) { ++zeroCounter; variablePropagated = this->l1; }
	if (variables[abs(this->l2)] == 0) { ++zeroCounter; variablePropagated = this->l2; }
	if (variables[abs(this->l3)] == 0) { ++zeroCounter; variablePropagated = this->l3; }
	
	if (zeroCounter == 1)
	{
		variables[abs(variablePropagated)] = (variablePropagated >= 0 ? 1 : -1);
		return abs(variablePropagated);
	}
	
	return 0;
}

int Clause::CountUndefined(const vector<int>& variables)
{
	int zeroCounter = 0;
	int variablePropagated = -1;
	if (variables[abs(this->l1)] == 0) { ++zeroCounter; variablePropagated = this->l1; }
	if (variables[abs(this->l2)] == 0) { ++zeroCounter; variablePropagated = this->l2; }
	if (variables[abs(this->l3)] == 0) { ++zeroCounter; variablePropagated = this->l3; }
	
	return zeroCounter;
}

