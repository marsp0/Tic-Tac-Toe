output: main.o Game.o World.o PlayerX.o
	g++ -std=c++14 main.o Game.o World.o PlayerX.o -o output -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -std=c++14 -c main.cpp 

Game.o: Game.cpp Game.hpp
	g++ -std=c++14 -c Game.cpp 

World.o: World.cpp World.hpp
	g++ -std=c++14 -c World.cpp 

PlayerX.o: PlayerX.cpp PlayerX.hpp
	g++ -std=c++14 -c PlayerX.cpp

clean:
	rm *.o output