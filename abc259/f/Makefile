.PHONY: all
all: a.out

a.out: a.cc
	scl enable devtoolset-9 'g++ -I ${HOME}/ac-library $< -Wall -o $@ -std=c++17'

.PHONY: clean
clean:
	rm -f a.out
