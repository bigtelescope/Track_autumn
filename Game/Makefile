SOURCE_S = functions.cpp main.cpp
CC = g++
CFLAGS = -Wall -Wextra
RM = /bin/rm -rf

all: main objects clean

main: 
	g++ -c $(SOURCE_S)

objects: 
	g++ functions.o main.o -o go -lsfml-graphics -lsfml-window -lsfml-system

clean:  
	$(RM) *.o pro