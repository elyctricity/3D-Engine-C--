all: compile link

compile:
	g++ -Isrc/include -c main.cpp Cube.cpp Camera.cpp Projection.cpp

link:
	g++ main.o Cube.o Camera.o Projection.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system

# Test code
# # Compiler
# CXX = g++

# # Compiler flags
# CXXFLAGS = -std=c++11 -Wall

# # Linker flags for Windows (linking against SFML and OpenGL)
# LDFLAGS = -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system -lopengl32

# # Source files
# SRCS = test.cpp

# # Object files
# OBJS = $(SRCS:.cpp=.o)

# # Executable name
# EXEC = test

# # Default target
# all: compile link

# compile:
# 	$(CXX) $(CXXFLAGS) -Isrc/include -c $(SRCS)

# link:
# 	$(CXX) $(OBJS) -o $(EXEC) $(LDFLAGS)