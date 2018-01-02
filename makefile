
programa: main.cpp individuo.hpp poblacion.hpp
	g++ main.cpp individuo.hpp poblacion.hpp

clean:
	rm -f *.o *.gch *.out *.exe
