make:

	gcc lencmp.c -Wall -o lencmp
	gcc lexcmp.c -Wall -o lexcmp
	gcc digcmp.c -Wall -o digcmp

clean:
	rm -f lencmp lexcmp digcmp