RUN := ./run

aquoicasert: Ensemble.o /Tests/Test01/TestUnitaireEnsemble.o
	g++ -o Ensemble Ensemble.o ./Tests/Test01/TestUnitaireEnsemble.o

exe: TEnsemble.o Ensemble.o
	g++ -o exe TEnsemble.o Ensemble.o
	
TEnsemble: TEnsemble.cpp
	g++ -c TEnsemble TEnsemble.cpp
Ensemble: Ensemble.cpp
	g++ -c -DMAP Ensemble Ensemble.cpp

TestsDomJudge : 
	cd Tests/Test02
	$(RUN)
	
Test: Ensemble.cpp
	g++ -DMAP -o Ensemble Ensemble.cpp
