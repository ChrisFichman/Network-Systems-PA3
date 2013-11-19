all: clean routedLS

routedLS: routed_LS.c
	gcc -Wall routed_LS.c -o routedLS

clean:
	rm -f routed_LS
