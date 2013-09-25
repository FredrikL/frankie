CC=clang++ -std=c++11 -stdlib=libc++ -lboost_system-mt

all: clean frankie

frankie: 
	$(CC) $(LFLAGS) frankie.cpp -o frankie

clean:
	rm frankie