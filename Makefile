prototyp: main.o hero.o	character.o item.o
	g++ -o prototyp main.o hero.o character.o item.o

main.o: main.cpp
	g++ -c main.cpp

hero.o: hero.cpp hero.h
	g++ -c hero.cpp

character.o: character.cpp character.h
	g++ -c character.cpp

item.o: item.cpp item.h
	g++ -c item.cpp

clean:
	rm -f *.o prototyp

