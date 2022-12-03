.PHONY: all
all: a.out

a.out: dfs_recursive.cc
	g++ -g3 $<

test.in:
	python test.py > $@

.PHONY: test
test: ./a.out test.in
	ulimit -s 1048576; ./a.out < test.in
