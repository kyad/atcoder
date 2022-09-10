.PHONY: test
test:
	for i in `ls test/*.in`; do ./a.out < $$i > $$i.txt; done
	for i in `ls test/*.in`; do cat $$i $$i.txt | python valid.py; done

.PHONY: gen-test
gen-test:
	rm -f test/random-*
	oj g/i 'python gen.py'

.PHONY: clean
clean:
	rm -f test/random-*
