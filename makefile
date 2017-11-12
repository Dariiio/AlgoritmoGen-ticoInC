
programa: main.cpp individuo.hpp
	g++ main.cpp individuo.hpp

clean:
	rm -f $(BINARY) $(OBJS) *.gch *.out
