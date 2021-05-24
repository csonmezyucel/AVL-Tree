# Makefile for AVLTree implemented by Cevat Sonmez Yucel

all: AVLTree clean
CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall # Enable all warnings
DEBUG=-g

OBJECTS = AVLNode.cpp AVLTree.cpp main.cpp

AVLTree: $(OBJECTS)
		$(CXX) $(DEBUG) $(OBJECTS) $(CXXFLAGS)



.PHONY: clean
clean:
	-rm -f *.o *~ AVLTree
