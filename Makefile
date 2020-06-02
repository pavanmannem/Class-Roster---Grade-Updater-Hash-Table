OBJ = main.o CSVEditor.o
MAIN = main

$(MAIN): $(OBJ)
	g++ -std=c++11 -o $(MAIN) $(OBJ)

main.o: main.cpp HashTable.hpp
	g++ -std=c++11 -c main.cpp

CSVEditor.o: CSVEditor.cpp CSVEditor.hpp
	g++ -std=c++11 -c CSVEditor.cpp

clean: 
	rm -f $(OBJ) $(MAIN)
