all: Queue clean

Stack: instantiation.cpp Lab5.o Queue.o Student.o
	g++ -o Queue instantiation.cpp

Lab4.o: Lab5.cpp
	g++ -c Lab5.cpp Queue.cpp Student.cpp

clean:
	rm -rf *o
