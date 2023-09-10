#include "../Utility/Utility.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>

int main(int argc, char *argv[]) {
	int max = std::strtol(argv[1], nullptr, 0);
	std::vector<int>* primes = util::genPrimes(max);
	std::vector<int>* factorStack = new std::vector<int>;
	int product = 1;
	for(int i = 2; i <= max; i++) {
		if (util::isPrime(i))
			factorStack->push_back(i);
		else {
			for ( int prime : *primes) {
				if (util::isPower(i, prime)) 
					factorStack->push_back(prime);
			}
		}
	}	
	for (int factor : *factorStack) {
		std::cout << factor << std::endl;
		product *= factor;
	}
	std::cout << "Lowest number divisible by numbers up to " << max << " is " << product << std::endl;
}
