CC=gcc
CXX=g++
CFLAGS= -Wall -Wconversion -ansi -pedantic -O0
CXXFLAGS=$(CFLAGS)
TARGET=main
SOURCES=$(wildcard *.cpp) $(wildcard */*.cpp) $(wildcard */*/*.cpp)
OBJS=$(SOURCES:.cpp=.o)


$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET) .depends
