all:
	gcc bf.c -o bfc
	./bfc test.bf unittests -c
	./unittests
