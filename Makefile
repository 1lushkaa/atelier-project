CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

all: atelier

atelier: src/main.cpp
	$(CXX) $(CXXFLAGS) -o atelier src/main.cpp

clean:
	rm -f atelier
