# Specifiy the target OLD MAKE FILE
all: main

# Specify the object files that the target depends on
# Also specify the object files needed to create the executable
#linker
main: main.o user.o restaurant.o heap.o craving.o graph.o
	g++ main.o user.o restaurant.o  heap.o craving.o graph.o -o main

# Specify how the object files should be created from source files
#compiler
main.o: main.cpp user.h 
	g++ -c main.cpp 

user.o: user.cpp user.h restaurant.h
	g++ -c user.cpp

restaurant.o: restaurant.cpp restaurant.h
	g++ -c restaurant.cpp

heap.o: heap.cpp heap.h craving.h
	g++ -c heap.cpp

craving.o: craving.cpp craving.h 
	g++ -c craving.cpp
graph.o: graph.cpp graph.h user.h
	g++ -c graph.cpp
	
# Specify the object files and executables that are generated
# and need to be removed to re-compile the whole thing
clean:
	rm -f *.o main
