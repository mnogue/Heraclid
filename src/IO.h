
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>

#include "clause.h"
#include "sat.h"

using namespace std;

#ifndef IO_H
#define IO_H

class IO
{
    private: 
        
        static void DisplayMessage(string msg);

		static void DisplayFlag(bool flag);
        
    public: 
        
        static void Input(SAT& sat, int argc, char *argv[]);
        
        static void Output(SAT& sat, bool issat);
};

#endif;