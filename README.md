
## HERACLID: DPLL SAT-Solver

This code was created for a university assignment and may not be sold nor used for any lucrative purposes. We do not take any responsibilities of the injuries it may cause.

# Information

Heraclid is a modular DPLL 3-Clause sat solver that recieves a set of clauses in DIMEMAS form and answers whether if the formula is satisfactible or not. If so, it also gives a model.

# Installation

Head to `exec` folder and execute the following make command:

	make all
	
Or if you prefer to compile individual versions of the sat solver execute:

	make version1

or

	make version2

or

	make version3
	
or

	make version4

Each version goes one step futher from the previous version. The following lines describe what every 
single version of the sat solver does:

* **Version 1**: Most basic SAT-Solver: Assigns a random value to a single literal and tries to unit propagate by searching through the whole set of clauses.
* **Version 2**: Randomly chooses each literal value, but this time uses a vector that contains in which clauses appears each variable. This data structure speeds up the unit propagation operation.
* **Version 3**: Literals are not chosen randomly anymore. Instead a static heuristic method is used.
* **Version 4**: A dynamic heuristic is used to select the value of a certain variable when a decisional point is found.

To remove all generated files, execute:

	make clean

Usage
-----

Once you have compiled the program, execute it with `./sat{NUMBER}.x path_to_clauses`.
For instance, if you want to check the satisfactibility of `unsat150a` with the 4th version, execute:

	./sat4.x jp/unsat150a
