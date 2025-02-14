CXX = g++
CXXFLAGS = -Wall -Werror -std=c++14

all: test_multiset prime_factors

test_multiset: test_multiset.cc multiset.h
	$(CXX) $(CXXFLAGS) -o test_multiset test_multiset.cc -I/usr/local/include -L/usr/local/lib -lgtest -lgtest_main -pthread

prime_factors: prime_factors.cc
	$(CXX) $(CXXFLAGS) -o prime_factors prime_factors.cc

clean:
	rm -f test_multiset prime_factors *.o
