make:
	gcc loopcmp.c -Wall -o loopcmp
	gcc lencmp.c -Wall -o lencmp
	gcc lexcmp.c -Wall -o lexcmp
	gcc digcmp.c -Wall -o digcmp

clean:
	rm -f lencmp lexcmp digcmp loopcmp