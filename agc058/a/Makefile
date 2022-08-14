.PHONY: test
test:
	oj g/i 'python gen.py'
	for i in `seq 0 99`; do id=`printf "random-%03d" "$${i}"`; ./a.out <test/$${id}.in > test/$${id}.txt; done
	python valid.py

.PHONY:
clean:
	rm -f test/random-*
