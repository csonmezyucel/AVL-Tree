# Makefile for AVLTree implemented by Cevat Sonmez Yucel
all: AVLTree clean
CXX=clang++

OBJECTS = AVLNode.cpp AVLTree.cpp main.cpp

AVLTree: $(OBJECTS)
		$(CXX) $(OBJECTS)

.PHONY: clean
clean:
	-rm -f *.o *~ AVLTree