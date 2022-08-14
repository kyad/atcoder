# https://qiita.com/ktateish/items/d350e359d921d174fc28

a.out:
	g++ interactive.cc

fifo:
	mkfifo fifo

.PHONY: test
test: ./a.out fifo
	./a.out < fifo | python judge.py test01.in > fifo
	./a.out < fifo | python judge.py test02.in > fifo
	./a.out < fifo | python judge.py test03.in > fifo
	./a.out < fifo | python judge.py test04.in > fifo
	./a.out < fifo | python judge.py test05.in > fifo

.PHONY: clean
clean:
	rm -f a.out fifo
