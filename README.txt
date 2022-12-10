INSTRUCTIONS FOR DIJKSTRA's ALGORITHM:

	This program will provide a map representing a graph given by the attached image file, where points marked by letters are represented numerically with corresponding integers. It will then give the user details about the map and use a version of Dijkstra's algorithm to compute the shortest distance from point 1 (A) to point 16 (P) using neighbors. The run this program, you have two options:
		TESLA: use winSCP to upload the program and the makefile to tesla. Then, simply run the following commands:
				>>make
				>>make run
			 Note that this will require you to rename your makefile.mak to simply "makefile" in order to function.
		LOCAL: place program into preferred directory on g++/makefile compatible computer. Either modify your makefile so that "./a.out" reads "./a.exe", or run the following commands:
				>>g++ dijkstra.cpp
				>>./a.exe
			This will provide the proper output, and is the recommended method. Either way, it is highly recommended that all included files in this package be compiled according to C++23 standards.
				
	Note that the given image file represents the real map that the algorithm is intended to compute distances for. Each point on the map has its position indicated in the program by an integer 1-16 that corresponds to a letter in that position in the alphabet. The alphabetical character is included in the picture.