all: research.o OscillatorVDP.o Visualization.o 
	g++ research.o OscillatorVDP.o Visualization.o -lboost_iostreams -lboost_system -lboost_filesystem -lgd
research.o: ../OscillatorVDP.h ../Visualization.h
	g++ -c research.cpp
OscillatorVDP.o: ../OscillatorVDP.h
	g++ -c ../OscillatorVDP.cpp
Visualization.o: ../Visualization.h
	g++ -c ../Visualization.cpp 