clear: compile
	rm *.o

compile: object
	g++ -o  main *.o -lSDL2 && ./main
	
object:
	g++ -c  main.cpp implementation/*.cpp 
