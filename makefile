CC=g++
CFLAGS=-c -Wall -std=c++11
SOURCES=main.cpp app.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=app.out

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o && clear
