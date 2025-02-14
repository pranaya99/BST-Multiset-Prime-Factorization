#include <iostream>
#include <map>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>

std::map<int, int> getPrimeFactors(int n) {
  std::map<int, int> primeFactors;
  for (int i = 2; i <= std::sqrt(n); i++) {
    while (n % i == 0) {
      primeFactors[i]++;
      n /= i;
    }
  }
  if (n > 1) {
    primeFactors[n]++;
  }
  return primeFactors;
}

void printAll(const std::map<int, int>& primeFactors) {
  for (auto it = primeFactors.begin(); it != primeFactors.end(); ++it) {
    std::cout << it->first << " (x" << it->second << ")";
    if (std::next(it) != primeFactors.end()) {
      std::cout << ", ";
    } else {
      std::cout << ",";
    }
  }
  std::cout << std::endl;
}

void printMax(const std::map<int, int>& primeFactors) {
  if (!primeFactors.empty()) {
    auto maxFactor = *primeFactors.rbegin();
    std::cout << maxFactor.first << " (x" << maxFactor.second << ")" << std::endl;
  }
}


void printMin(const std::map<int, int>& primeFactors) {
  if (!primeFactors.empty()) {
    auto minFactor = *primeFactors.begin();
    std::cout << minFactor.first << " (x" << minFactor.second << ")" << std::endl;
  }
}


void printNear(const std::map<int, int>& primeFactors, int target, const std::string& mode) {
  auto it = primeFactors.lower_bound(target);
  
  if (mode == "") {
    if (it != primeFactors.end() && it->first == target) {
      std::cout << it->first << " (x" << it->second << ")" << std::endl;
    } else {
      std::cout << "Prime factor not found" << std::endl;
    }
  } else if (mode == "+") {
  if (it == primeFactors.end()) {
    std::cout << "No match" << std::endl;
  } else {
    if (it->first == target) {
      ++it;
    }
    if (it != primeFactors.end()) {
      std::cout << it->first << " (x" << it->second << ")" << std::endl;
    } else {
      std::cout << "No match" << std::endl;
    }
  }
}


int main(int argc, char* argv[]) {
  if (argc < 3) {
    std::cerr << "Usage: " << argv[0] << " <number> <command> [<args>]" << std::endl;
    return 1;
  }

  int number = std::atoi(argv[1]);
  
  // Validate the number
  if (number <= 1) {
    std::cerr << "Invalid number" << std::endl;
    return 1;
  }

  std::string command = argv[2];
  std::map<int, int> primeFactors = getPrimeFactors(number);

  if (command == "all") {
    printAll(primeFactors);
  } else if (command == "max") {
    printMax(primeFactors);
  } else if (command == "min") {
    printMin(primeFactors);
  } else if (command == "near") {
    if (argc < 4) {
      std::cerr << "Command 'near' expects another argument: [+/-]prime" << std::endl;
      return 1;
    }

    std::string nearArg = argv[3];
    if (nearArg[0] == '+') {
      printNear(primeFactors, std::atoi(nearArg.substr(1).c_str()), "+");
    } else if (nearArg[0] == '-') {
      printNear(primeFactors, std::atoi(nearArg.substr(1).c_str()), "-");
    } else {
      printNear(primeFactors, std::atoi(nearArg.c_str()), "");
    }
  } else {
    std::cerr << "Command '" << command << "' is invalid" << std::endl;
    std::cerr << "Possible commands are: all|min|max|near" << std::endl;
  }

  return 0;
}
