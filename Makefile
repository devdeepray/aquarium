.PHONY: cleanall cleanexe simplecpp all

all:
	make simplecpp;
	make build;

build: src/*
	./simplecpp/s++ -o aquarium src/*.cpp


cleanall:
	rm aquarium;
	rm -rf simplecpp;

cleanexe:
	rm aquarium;

simplecppex:
	tar xf simplecpp.tar

simplecpp: simplecppex
	cd simplecpp;\
	./configure.sh;\
	cd ..;
