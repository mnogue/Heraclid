
#include "interpretation.h"

// CONSTRUCTOR: ------------------------------------------------------------------------------------

Interpretation::Interpretation(int size)
{
	this->variables = vector<int>(size);
	this->variables[0] = 0;
	this->variableChanged = 0;
	this->hasHeuristicallyPropagated = true;
}

Interpretation::Interpretation(vector<int> variables)
{
	this->variables = variables;
	this->variableChanged = 0;
	this->hasHeuristicallyPropagated = true;
}

// PRIVATE FUNCTIONS: ------------------------------------------------------------------------------

int Interpretation::Sign(int a)
{
	return (a >= 0 ? 1 : -1);
}

// GETTERS: ----------------------------------------------------------------------------------------

vector<int> Interpretation::GetInterpretation() { return this->variables; }
