hangman.out: main.o game.o function.o
	g++ -Wall -Werror -o hangman.out main.o game.o function.o

main.o: main.cpp function.h game.h
	g++ -c main.cpp

game.o: game.cpp function.h
	g++ -c game.cpp

function.o: function.cpp
	g++ -c function.cpp

clean: 
	rm *.o hangman