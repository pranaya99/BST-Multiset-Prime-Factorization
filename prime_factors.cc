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
  for (const auto& factor : primeFactors) {
    std::cout << factor.first << " " << factor.second << std::endl;
  }
}

void printMax(const std::map<int, int>& primeFactors) {
  if (!primeFactors.empty()) {
    auto maxFactor = *primeFactors.rbegin();
    std::cout << maxFactor.first << " " << maxFactor.second << std::endl;
  }
}

void printMin(const std::map<int, int>& primeFactors) {
  if (!primeFactors.empty()) {
    auto minFactor = *primeFactors.begin();
    std::cout << minFactor.first << " " << minFactor.second << std::endl;
  }
}

void printNear(const std::map<int, int>& primeFactors, int target, const std::string& mode) {
  auto it = primeFactors.lower_bound(target);
  
  if (mode == "") {
    if (it != primeFactors.end() && it->first == target) {
      std::cout << it->first << " " << it->second << std::endl;
    } else {
      std::cout << "Prime factor not found" << std::endl;
    }
  } else if (mode == "+") {
    if (it != primeFactors.end() && it->first > target) {
      std::cout << it->first << " " << it->second << std::endl;
    } else {
      std::cout << "No larger prime factor" << std::endl;
    }
  } else if (mode == "-") {
    if (it != primeFactors.begin()) {
      --it;
      std::cout << it->first << " " << it->second << std::endl;
    } else {
      std::cout << "No smaller prime factor" << std::endl;
    }
  }
}

int main(int argc, char* argv[]) {
  if (argc < 3) {
    std::cerr << "Usage: " << argv[0] << " <number> <command> [near_arg]" << std::endl;
    return 1;
  }

  int number = std::atoi(argv[1]);
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
      std::cerr << "Usage for 'near': " << argv[0] << " <number> near <prime/+/->" << std::endl;
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
    std::cerr << "Invalid command: " << command << std::endl;
  }

  return 0;
}
