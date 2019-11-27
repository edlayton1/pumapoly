CC = g++
#el compilador (gcc, g++, etc)

CFLAGS = -Wall -std=c++11
#banderas

CFLAGS += -Wextra
#más (+=) banderas

INCLUDES = -I.
#dónde buscar las cabeceras (. significa el directorio actual)

LIBS = 
#aquí van las bibliotecas (p.ej. openmp ldl pthread)

LDFLAGS =  -fopenmp
#aquí van banderas para el enlazador

SOURCES = main.cpp
#aquí ponemos al fuente principal

SOURCES += DLL.cpp Stack.cpp Lugares.cpp Monopoly.cpp 
#aquí ponemos el resto de fuentes (.c)

EXECUTABLE = monopoly.out
#nuestro ejecutable

DEPS = DLL.h Lugares.h Monopoly.h Stack.h
#aquí ponemos las dependencias (.h)

OBJECTS = $(SOURCES:.c=.o)
#convertimos todos los .c en .o

all: $(SOURCES) $(EXECUTABLE) 

$(EXECUTABLE): $(OBJECTS) $(DEPS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) -c $(CFLAGS) $< -o $@


.PHONY: clean run docs

run: all
	./$(EXECUTABLE)

clean:
	rm -rf *.o $(EXECUTABLE) *~

docs:
	doxygen Doxyfile
