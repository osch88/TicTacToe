#declare variables
CC = g++

CFLAGS = -lSDL2main -lSDL2 -lSDL2_image

SRC = src/main.cpp

EXEC = bin/game

all:
# $(CC) -I include $(SRC) $(CFLAGS) -o $(EXEC)
	$(CC) -c src/*.cpp -std=c++14 -m64 -g -Wall -I include && $(CC) *.o -o $(EXEC) $(CFLAGS) && ./$(EXEC)

# g++ -c src/*.cpp -std=c++14 -m64 -g -Wall -I include && g++ *.o -o bin/debug/main -lSDL2main -lSDL2 -lSDL2_image && ./bin/debug/main"