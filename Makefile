CFLAGS = -Wall -fpic -coverage -lm -std=c99

final:
	g++ final_325.cpp -o final
	
clean:
	rm -f final *.o *.tour