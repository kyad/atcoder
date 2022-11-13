.PHONY: all
all: wa.out

wa.out: wa.cc
	g++ -I $(HOME)/ac-library $< -o $@ -Wall -g3

ac.out: a.cc
	g++ -I $(HOME)/ac-library $< -o $@ -Wall -g3

.PHONY: clean
clean:
	rm -f a.out ac.out

.PHONY: gen-test
gen-test:
	rm -f test/random-*
	oj g/i 'python gen.py'
	oj g/o -c ./ac.out
