#main.make

main:main.o algs.o
	g++ main.o algs.o -o main 
	
main.o:main.cpp
	g++ -c main.cpp -o main.o
algs.o:algs.cpp ./include/algs.h
	g++ -c algs.cpp -o algs.o

clean:
	rm *.o
clear:
	rm main *.o

