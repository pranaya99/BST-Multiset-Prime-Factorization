# BST Multiset & Prime Factorization

A C++ implementation of a multiset container using Binary Search Trees, with a practical application for prime number factorization and analysis.

**Academic Project**: ECS 36C - Data Structures & Algorithms  
**Instructor**: Prof. Joël Porquet-Lupine  
**Institution**: UC Davis, Winter Quarter 2025

## Overview

This project consists of two main components:
1. **Custom Multiset Container** - A BST-based multiset implementation from scratch
2. **Prime Factorization Tool** - Command-line utility for analyzing prime factors

## Features

### Multiset Container
- **O(log n) average complexity** for core operations
- **Duplicate key support** with efficient counting
- **Floor/Ceiling operations** for range queries
- **Complete STL-style API** with iterators and standard methods
- **Comprehensive unit testing** with Google Test framework

### Prime Factorization Tool
- **Complete factorization** of composite numbers
- **Interactive queries** (min, max, nearest factors)
- **Efficient factor analysis** using custom multiset
- **Robust error handling** and input validation

## Build & Run

```bash
# Build everything
make

# Run multiset tests
./test_multiset

# Analyze prime factors
./prime_factors 4410 all
./prime_factors 4410 max
./prime_factors 4410 near +5
```

## Usage Examples

### Prime Factorization
```bash
$ ./prime_factors 4410 all
2 (x1), 3 (x2), 5 (x1), 7 (x2), 

$ ./prime_factors 4410 min
2 (x1)

$ ./prime_factors 4410 near -5
3 (x2)
```

### Commands
- `all` - Display all prime factors with counts
- `min` - Show smallest prime factor
- `max` - Show largest prime factor  
- `near <prime>` - Find exact factor
- `near +<prime>` - Find next larger factor
- `near -<prime>` - Find next smaller factor

## Technical Details

- **Language**: C++11
- **Data Structure**: Binary Search Tree (unbalanced)
- **Testing**: Google Test framework
- **Build System**: GNU Make
- **Style**: Google C++ Style Guide compliant

## Project Structure

```
├── multiset.h          # BST multiset implementation
├── test_multiset.cc    # Unit test suite
├── prime_factors.cc    # Main application
├── Makefile           # Build configuration
└── report.pdf         # Technical documentation
```

## Key Algorithms

- **BST Insert/Remove** with duplicate handling
- **Floor/Ceiling** operations for range queries
- **Prime factorization** using trial division
- **Factor analysis** with efficient lookups

Built for **ECS 36C - Data Structures & Algorithms** at UC Davis  
**Course Instructor**: Prof. Joël Porquet-Lupine  
**Quarter**: Winter 2025

---

*This project demonstrates fundamental computer science concepts including binary search trees, algorithm analysis, and software engineering practices through hands-on implementation and testing.*
