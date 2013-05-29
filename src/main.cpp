#include <iostream>
#include "sat.h"
#include "IO.h"

using namespace std;

int main(int argc, char *argv[])
{
    SAT sat = SAT();
    IO::Input(sat, argc, argv);
    bool issat = sat.IsSat();
    IO::Output(sat, issat);
}