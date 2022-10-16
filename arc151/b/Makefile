.PHONY: all
all: a.out naive.out

a.out: a.cc
	g++ -I $(HOME)/ac-library $< -Wall

naive.out: naive.cc
	g++ -I $(HOME)/ac-library $< -o $@ -Wall

.PHONY: clean
clean:
	rm -f a.out naive.out

.PHONY: gen-test
gen-test:
	rm -f test/random-*
	oj g/i 'python gen.py'
	oj g/o -c ./naive.out
