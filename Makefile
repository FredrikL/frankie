CC=clang++ -std=c++11 -stdlib=libc++ -lboost_system-mt

all: clean frank

frank: 
	$(CC) $(LFLAGS) frankie.cpp -o frank

clean:
	rm frank