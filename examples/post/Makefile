CC=clang++ -std=c++11 -stdlib=libc++ -lboost_system-mt -Wfatal-errors -Wall -W -Werror -Wfloat-equal -Wendif-labels -I../../external/ 

all: clean frank

frank: 
	$(CC) $(LFLAGS) *.cpp -o frank

clean:
	rm frank