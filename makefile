all: Archivo.o
	g++ principal.cpp Archivo.o -o principal
Archivo.o:
	g++ -c Archivo.cpp
clean:
	RM *.o core principal