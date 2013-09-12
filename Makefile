all:
	gcc bf.c -o build/bfc
	build/bfc test/test.bf narc
