.PHONY: all
all: a.out

a.out: suffix_array.cc
	g++ -I $(HOME)/ac-library $< -Wall

.PHONY: clean
clean:
	rm -f a.out
