.PHONY: all
#all: a.out
all: a.out naive.out

a.out: a.cc
	g++ -I $(HOME)/ac-library $< -o $@ -Wall -g3

naive.out: naive.cc
	g++ -I $(HOME)/ac-library $< -o $@ -Wall -g3

.PHONY: clean
clean:
	rm -f a.out naive.out

.PHONY: gen-test
gen-test: naive.out
	rm -f test/random-*
	oj g/i 'python gen.py'
	oj g/o -c ./naive.out
