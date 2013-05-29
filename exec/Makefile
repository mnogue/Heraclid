
####################################################################################################
# MAKEFILE FOR SAT-SOLVER.                                                                         #
# Designed and developed by Martí-Joan Nogué Coll                                                  #
# CATSOFT-STUDIOS(c) 2012                                                                          #
####################################################################################################

## VARIABLES #######################################################################################

EXEC1 := sat1.x
EXEC2 := sat2.x
EXEC3 := sat3.x
EXEC4 := sat4.x

SRC  := ../src/

V1 := ../src/v1/
V2 := ../src/v2/
V3 := ../src/v3/
V4 := ../src/v4/

## CALLERS #########################################################################################

all: buildversion1 buildversion2 buildversion3 buildversion4 cleandoto

version1: buildversion1 cleandoto
	
version2: buildversion2 cleandoto
	
version3: buildversion3 cleandoto
	
version4: buildversion4 cleandoto
	

####################################################################################################
## BUILD CPP #######################################################################################
	
buildversion1: clause.o io.o varinfo.o sat.o main.o interpretation.o version1.o
	g++ -O3 -o $(EXEC1) clause.o io.o varinfo.o sat.o interpretation.o version1.o main.o

buildversion2: clause.o io.o varinfo.o sat.o main.o interpretation.o version2.o
	g++ -O3 -o $(EXEC2) clause.o io.o varinfo.o sat.o interpretation.o version2.o main.o

buildversion3: clause.o io.o varinfo.o sat.o main.o interpretation.o version3.o
	g++ -O3 -o $(EXEC3) clause.o io.o varinfo.o sat.o interpretation.o version3.o main.o

buildversion4: clause.o io.o varinfo.o sat.o main.o interpretation.o version4.o
	g++ -O3 -o $(EXEC4) clause.o io.o varinfo.o sat.o interpretation.o version4.o main.o

## FILE DEPENEDENCES ###############################################################################

main.o: $(SRC)main.cpp
	g++ -O3 -c $(SRC)main.cpp

sat.o: $(SRC)sat.cpp
	g++ -O3 -c $(SRC)sat.cpp

interpretation.o: $(SRC)interpretation.cpp
	g++ -O3 -c $(SRC)interpretation.cpp

io.o: $(SRC)io.cpp
	g++ -O3 -c $(SRC)io.cpp

varinfo.o: $(SRC)varinfo.cpp
	g++ -O3 -c $(SRC)varinfo.cpp

clause.o: $(SRC)clause.cpp
	g++ -O3 -c $(SRC)clause.cpp

version1.o: $(V1)version1.cpp
	g++ -O3 -c $(V1)version1.cpp

version2.o: $(V2)version2.cpp
	g++ -O3 -c $(V2)version2.cpp

version3.o: $(V3)version3.cpp
	g++ -O3 -c $(V3)version3.cpp

version4.o: $(V4)version4.cpp
	g++ -O3 -c $(V4)version4.cpp

## CLEANERS ########################################################################################

clean:
	rm -rf *.exe *.x *.o *.model
	
cleandoto:
	rm -rf *.o *.model
