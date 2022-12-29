OBJS	= event.o wampus.o gold.o bats.o pits.o player.o room.o game.o driver.o
SOURCE	= event.cpp wampus.cpp gold.cpp bats.cpp pits.cpp player.cpp room.cpp driver.cpp
HEADER	= event.h wampus.h gold.h bats.h pits.h player.h room.h
OUT	= a.out
CC	 = g++ -std=c++11
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

event.o: event.cpp
	$(CC) $(FLAGS) event.cpp 

wampus.o: wampus.cpp
	$(CC) $(FLAGS) wampus.cpp 

gold.o: gold.cpp
	$(CC) $(FLAGS) gold.cpp 

bats.o: bats.cpp
	$(CC) $(FLAGS) bats.cpp 

pits.o: pits.cpp
	$(CC) $(FLAGS) pits.cpp 

player.o: player.cpp
	$(CC) $(FLAGS) player.cpp 

room.o: room.cpp
	$(CC) $(FLAGS) room.cpp 

game.o: game.cpp
	$(CC) $(FLAGS) game.cpp 

driver.o: driver.cpp
	$(CC) $(FLAGS) driver.cpp 


clean:
	rm -f $(OBJS) $(OUT)