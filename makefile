output: main.o Game.o World.o PlayerX.o Menu.o Button.o AI.o
	g++ -std=c++14 main.o Game.o World.o PlayerX.o Menu.o Button.o AI.o -o output -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ -std=c++14 -c main.cpp 

Game.o: Game.cpp Game.hpp
	g++ -std=c++14 -c Game.cpp 

World.o: World.cpp World.hpp
	g++ -std=c++14 -c World.cpp 

PlayerX.o: PlayerX.cpp PlayerX.hpp
	g++ -std=c++14 -c PlayerX.cpp

Menu.o: Menu.cpp Menu.hpp
	g++ -std=c++14 -c Menu.cpp

Button.o: Button.cpp Button.hpp
	g++ -std=c++14 -c Button.cpp

AI.o: AI.cpp AI.hpp
	g++ -std=c++14 -c AI.cpp

clean:
	rm *.o output