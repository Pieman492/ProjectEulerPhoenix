#include <iostream> 
#include <cmath>

int orderOfMagnitude(int num) {
	int order = 1;
	while(true) {
		if (num < pow(10, order))
			// We're testing if we've overshot, so we go backwards if it succeeds.
			return order - 1;
		order++;
	}
}

int reverse(int num) {
	int flipped = 0;
	int order = orderOfMagnitude(num);
	for (int i = 0; i <= order; i++) {
	  // Get the digits in order from the left and multiply them by the place
		// value of the digits from the right (e.g. for 988001, take 9 and multiply
		// it by 10^0, 8 by 10^1, and so on. Sum these to flip the number.
		flipped += (static_cast<int>(num/pow(10, order - i))) % 10 * pow(10, i);
	}
	return flipped;
	
}

int main() {
	// We're looking for the largest number, so we'll start high
	int factorOne = 999;
	int factorTwo = 999;
	int product;
	int largestPD = 0;
	for (int i = factorOne; i > 0; i--) {
		for (int j = factorTwo; j > 0; j--) {
			product = i*j;
			if (product > largestPD && product == reverse(product) ) {
				largestPD = product;
			}
		}
	}
	std::cout << "Largest Palindrome Product: " << largestPD << std::endl;
	
}
