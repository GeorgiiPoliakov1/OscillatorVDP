all: main.o OscillatorVDP.o Visualization.o 
	g++ main.o OscillatorVDP.o Visualization.o -lboost_iostreams -lboost_system -lboost_filesystem -lgd
main.o: OscillatorVDP.h Visualization.h
	g++ -c main.cpp
OscillatorVDP.o: OscillatorVDP.h
	g++ -c OscillatorVDP.cpp
Visualization.o: Visualization.h
	g++ -c Visualization.cpp 