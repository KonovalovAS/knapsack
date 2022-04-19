start: main.o knapsack.o
	g++ main.o knapsack.o -o start

main.o: main.cpp
	g++ -c main.cpp

source.o: knapsack.cpp knapsack.h
	g++ -c knapsack.cpp

clear:
	rm *.o start