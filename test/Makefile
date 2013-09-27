CC=clang++ -std=c++11 -stdlib=libc++ -lboost_system-mt -Wfatal-errors -Wall -W -Werror -Wfloat-equal -Wundef -Wendif-labels -I.

all: clean test

test: 
	$(CC) $(LFLAGS) test.cpp -o test

clean:
	rm test