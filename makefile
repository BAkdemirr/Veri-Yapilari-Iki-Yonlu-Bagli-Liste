hepsi:derle birlestir calistir

derle:
	g++ -I ./include -c ./src/CircularDoublyLinkedList.cpp -o ./lib/CircularDoublyLinkedList.o
	g++ -I ./include -c ./src/Node.cpp -o ./lib/Node.o
	g++ -I ./include -c ./src/Test.cpp -o ./lib/Test.o

birlestir:
	g++ ./lib/CircularDoublyLinkedList.o ./lib/Node.o ./lib/Test.o  -o ./bin/test.exe
calistir:
	./bin/test