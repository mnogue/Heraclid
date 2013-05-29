#include "IO.h"

// MESSAGES: ---------------------------------------------------------------------------------------

void IO::DisplayMessage(string msg)
{
    cout << " > " << msg << endl << endl;
}

void IO::DisplayFlag(bool flag)
{
	string msg = (flag ? " SATISFACTIBLE " : "UNSATISFACTIBLE");
	cout << " +------+               +------+" << endl;
	cout << " |    +-------------------+    |" << endl;
	cout << " +----|  "  << msg <<  "  |----+" << endl;
	cout << "      +-------------------+" << endl;
	cout << endl;
}

// INPUT: ------------------------------------------------------------------------------------------

void IO::Input(SAT& sat, int argc, char *argv[])
{
    cout << endl;
    
    if (argc < 2)
    {
        IO::DisplayMessage("ERROR: No input");
        exit(-1);
    }
    
    FILE *file;
    char reader;
    
    file   = fopen(argv[1], "r");
    reader = getc(file);
    
    while (reader == 'c') 
    {
        while (reader != '\n') reader = getc(file);
        reader = getc(file); 
    }
    
    int varsSize;
    int clausesSize;
    
    fscanf(file, " cnf %d %d", &varsSize, &clausesSize);
    
	clausesSize++;
	varsSize++;
	vector<Clause> clauses = vector<Clause>(clausesSize, Clause());
    
    for (int i = 1; i <= clausesSize; ++i)
    {
        int l1, l2, l3, foo;
        fscanf(file, "%d %d %d %d\n", &l1, &l2, &l3, &foo);
        
		clauses[i].l1 = l1;
		clauses[i].l2 = l2;
		clauses[i].l3 = l3;
    }
	
	sat.InsertData(clauses, varsSize);
}

// OUTPUT: -----------------------------------------------------------------------------------------

void IO::Output(SAT& sat, bool issat)
{
    switch (issat)
    {
		case true  : IO::DisplayFlag(true);  break;
		case false : IO::DisplayFlag(false); break;
    }
    
    if (issat)
    {
        ofstream modelFile;
        modelFile.open ("sat.model");
    	
		vector<int> model = sat.GetModel();
		
        for (int i = 1; i < model.size(); ++i)
        {
            modelFile << "  [" << i << "]\t=>\t";
            switch (model[i])
            {
                case  1 : modelFile << "I" << endl; break;
                case -1 : modelFile << "X" << endl; break;
                default : modelFile << "-" << endl; break;
            }
        }
    
        modelFile.close();
    }
}