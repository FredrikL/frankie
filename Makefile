CC=clang++ -std=c++11 -stdlib=libc++ -lboost_system-mt -Wfatal-errors -Wall -W -Werror -Wfloat-equal -Wendif-labels -Iexternal/ 

all: clean frank

frank: 
	$(CC) $(LFLAGS) frankie.cpp -o frank

clean:
	rm frank