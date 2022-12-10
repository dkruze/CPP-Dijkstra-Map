dijkstra: dijkstra.o
	g++ dijkstra.cpp -o dijkstra

dijkstra.o: dijkstra.cpp
	g++ -c dijkstra.cpp

clean:
	rm *.o
	rm dijkstra

run:
	./dijkstra