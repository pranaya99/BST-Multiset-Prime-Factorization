
CXXFLAGS = -Wall -Werror -std=c++11

all: test_multiset prime_factors

test_multiset: test_multiset.cc multiset.h
	g++  -Wall -Werror -std=c++11 test_multiset.cc -o test_multiset -I/usr/local/include -L/usr/local/lib -lgtest -lgtest_main -pthread

prime_factors: prime_factors.cc
g++  -Wall -Werror -std=c++11 prime_factors.cc -o prime_factors

clean:
	rm -f test_multiset prime_factors *.o
