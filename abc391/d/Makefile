.PHONY: all

# テストケース生成用のリファレンス
REFERENCE=naive
#REFERENCE=tle
#REFERENCE=ac

#all: a.out
all: a.out $(REFERENCE).out

.SUFFIXES: .out .cc
.cc.out:
	g++ -g3 -O0 -I HOME/ac-library -Wall $< -o $@

.PHONY: clean
clean:
	rm -f a.out $(REFERENCE).out

.PHONY: gen-test
gen-test:
	rm -f test/random-*
	oj g/i 'python gen.py'
	oj g/o -c ./$(REFERENCE).out
