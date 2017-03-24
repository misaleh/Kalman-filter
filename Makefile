main.o: main.cpp kalman.cpp matrix.cpp
	 g++  main.cpp  kalman.cpp matrix.cpp -o main.o 
run: 
	./main.o
