CC = clang++
CFLAGS = -Wall -Werror -std=c++20

OBJDIR = obj/
SRCDIR = src/
BINDIR = bin/

SOURCES = $(wildcard $(SRCDIR)*.cpp)
OBJECTS = $(patsubst $(SRCDIR)%.cpp, $(OBJDIR)%.o, $(SOURCES))
TARGET = $(BINDIR)loadbalancer

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)%.o: $(SRCDIR)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

docs:
	doxygen Doxyfile

.PHONY: clean
clean:
	rm -f $(OBJDIR)*.o $(TARGET)
	rm -rf docs

run: $(TARGET)
	./$(TARGET)