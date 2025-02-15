CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11
GTEST_DIR = /opt/homebrew

all: test_multiset prime_factors

test_multiset: test_multiset.cc multiset.h
	$(CXX) $(CXXFLAGS) test_multiset.cc -o test_multiset -I$(GTEST_DIR)/include -L$(GTEST_DIR)/lib -lgtest -lgtest_main -pthread

prime_factors: prime_factors.cc
	$(CXX) $(CXXFLAGS) prime_factors.cc -o prime_factors

clean:
	rm -f test_multiset prime_factors *.o