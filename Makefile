CXX = g++
CFLAGS = -Wall -g -O3

SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(patsubst %.cpp,%.o,$(SOURCES))

TARGET = bin/tsm

all: $(TARGET)

$(TARGET): build $(OBJECTS) 
	$(CXX) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -rf bin
	rm src/*.o

build:
	@mkdir -p bin
