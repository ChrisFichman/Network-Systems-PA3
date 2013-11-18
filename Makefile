all: clean routedLS

routedLS: routedLS.c
	gcc -Wall routedLS.c -o routedLS

clean:
	rm -f routed_LS
