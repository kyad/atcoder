.PHONY: all
all: a.out

a.out: a.cc
	g++ -I $(HOME)/ac-library $< -Wall -g3

naive.out: naive.cc
	g++ -I $(HOME)/ac-library $< -Wall -g3

.PHONY: clean
clean:
	rm -f a.out naive.out

.PHONY: gen-test
gen-test:
	rm -f test/random-*
	oj g/i 'python gen.py'
	oj g/o -c ./naive.out
