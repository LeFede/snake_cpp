output: main.o other.o Food.o Snake.o Game.o 
	g++ bin/main.o bin/other.o bin/Food.o bin/Snake.o bin/Game.o -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o bin/output
	# g++ main.o -o main
	# make clean

main.o: src/main.cpp
	g++ -c src/main.cpp -o bin/main.o

other.o: src/other.cpp include/other.h
	g++ -c src/other.cpp -o bin/other.o

Food.o: src/Food.cpp include/Food.h
	g++ -c src/Food.cpp -o bin/Food.o

Snake.o: src/Snake.cpp include/Snake.h
	g++ -c src/Snake.cpp -o bin/Snake.o

Game.o: src/Game.cpp include/Game.h
	g++ -c src/Game.cpp -o bin/Game.o

clean:
	rm bin/*.o bin/output