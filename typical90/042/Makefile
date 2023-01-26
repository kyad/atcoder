.PHONY: all
all: a.out

a.out: a.cc
	g++ -I $(HOME)/ac-library $< -o $@ -Wall -g3

.PHONY: clean
clean:
	rm -f a.out naive.out
