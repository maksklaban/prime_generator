CC=g++
CFLAGS=-c -Wall
SOURCES=main.cpp prime.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=prime

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
