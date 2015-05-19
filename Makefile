CXX = clang++
LD = clang++ 

CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -Werror -pedantic 
LDFLAGS = -std=c++1y -stdlib=libc++ -lpng -lc++abi


all: poker clean-o





poker : card.o hand.o deck.o game.o main.o
	$(LD) card.o hand.o deck.o game.o main.o $(LDFLAGS) -o poker

card.o : card.cpp
	$(CXX) $(CXXFLAGS) card.cpp

hand.o : hand.cpp
	$(CXX) $(CXXFLAGS) hand.cpp

deck.o : deck.cpp
	$(CXX) $(CXXFLAGS) deck.cpp

game.o : game.cpp
	$(CXX) $(CXXFLAGS) game.cpp

main.o : main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

clean-o:
	rm *.o
clean : 
	rm *.o poker