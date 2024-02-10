all: main.o HashTable.o ../ArrayList/ArrayList.o
	g++ main.o HashTable.o ../ArrayList/ArrayList.o -o HashTable

main.o: main.cpp
	g++ -c main.cpp -o main.o

HashTable.o: HashTable.cpp
	g++ -c HashTable.cpp -o HashTable.o

../ArrayList/ArrayList.o: ../ArrayList/ArrayList.cpp
	g++ -c ../ArrayList/ArrayList.cpp -o ../ArrayList/ArrayList.o

clean:
	rm -f *.o ../ArrayList/ArrayList.o HashTable