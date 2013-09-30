CC=clang++ -std=c++11 -stdlib=libc++ -lboost_system-mt -Wfatal-errors -Wall -W -Werror -Wfloat-equal -Wundef -Wendif-labels -I../external/bandit

all: clean test run

run:
	./test

test: 
	$(CC) $(LFLAGS) test.cpp context_test.cpp  -o test

clean:
	rm test