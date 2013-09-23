CLANG=clang++ -std=c++11 -stdlib=libc++

all: clean frankie

frankie: frankie.o
	$(CLANG) frankie.o -o frankie

frankie.o:
	$(CLANG) -c frankie.cpp

clean:
	rm frankie *.o