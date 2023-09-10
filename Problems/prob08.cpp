#include <iostream>
#include <deque>
#include <chrono>

int main() {
	// God has come to reap the sinners.
	std::string satan = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";
	// The upper bound for this is 9^13, this fits *uncomfortably* in a long.
	long product = 1;
	long largestProduct = 1;
	int digitInt;
	// We're going to snake through the string, converting each character to a
	// digit only a single time and then adding it to a runnng product. This is
	// lightning quick, but we need to keep track of numbers we've gone through
	// so we can divide them out as well as have special handling for zero
	std::deque<int>* digitQueue = new std::deque<int>;
	auto start = std::chrono::high_resolution_clock::now();
	for (char digitChar : satan) {
		// Update largest product if we've got something bigger. Doing it now is
		// oppertune since any time later the product actually incorporates 14
		// digits instead of 13
		largestProduct = std::max(largestProduct, product);
		// Remove ascii ofset to turn char into int digit
		digitInt = digitChar - '0';
		product *= digitInt;
		digitQueue->push_front(digitInt);
		
		// We're good to go unless we've hit our limit for digits in the product
		if (digitQueue->size() < 14)
			continue;
		
		if (digitQueue->back() == 0) {
			// Quietly remove the zero then recalculate the product of the current
			// 13 digits, now that the running total shouldn't be zeroed out.
			digitQueue->pop_back();
			product = 1;
			for (int digit : *digitQueue) 
				product *= digit;
		} else {
			// Simply divide out the oldest digit then remove it.
			product = product / digitQueue->back();
			digitQueue->pop_back();
		}

	}
	auto stop = std::chrono::high_resolution_clock::now();
	auto timeTaken = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	std::cout << "Largest product of consecutive digits: " << largestProduct << std::endl;
	std::cout << "Time taken: " << timeTaken.count() << " microseconds" << std::endl;
	delete digitQueue;
}
