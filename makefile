words: main.o words.o
	g++ -Wall -g main.o words.o -o words

main.o: main.cpp words.h
	g++ -Wall -c main.cpp

words.o: words.cpp words.h
	g++ -Wall -c words.cpp

clean:
	rm -rf words *.o