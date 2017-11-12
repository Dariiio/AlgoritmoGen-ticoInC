
OBJS = main.o individuo.o
BINARY = programa

#programa: $(OBJS)
	#g++ -o $(BINARY) $(OBJS)

#main.o: main.cpp
	#g++ -c main.cpp

#individuo.o: individuo.cpp
	#g++ -c individuo.cpp

clean:
	rm -f $(BINARY) $(OBJS) *.gch *.out *.exe

programa: main.cpp individuo.hpp
	g++ main.cpp individuo.hpp
