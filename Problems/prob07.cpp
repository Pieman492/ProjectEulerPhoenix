#include <iostream>
#include <vector>
#include <cstdlib>
#include "../Utility/Utility.hpp"
int main(int argc, char *argv[]) {
	int whichPrime = std::strtol(argv[1], nullptr, 0);
	std::vector<int>* primes = util::genPrimesCount(whichPrime);
	std::cout << whichPrime << "st prime is: " << primes->back() << std::endl;
}
