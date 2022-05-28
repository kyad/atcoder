.PHONY: all
all: a.out

a.out: a.cc
	g++ -I ${HOME}/ac-library $< -Wall

.PHONY: clean
clean:
	rm -f a.out
