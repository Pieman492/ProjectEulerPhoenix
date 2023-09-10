#include "../Utility/Utility.hpp"
#include <cassert>

int main(int argc, char *argv[]) {
	long target = std::stoi(argv[1]);
	int start = 0;	
	long sum = 0;
	std::vector<int> basis = std::vector<int>{ 2, 3, 5, 7, 11, 13, 17 };
	util::Timekeeper time = util::Timekeeper();

	time.start();
	util::LoopingLinkedList<int> increments = util::getIncrements(&basis, &start);

	for (long i=2; i < target; i++) {
		if ( util::isPrimeWheel(i, start, &basis, &increments) )	{
			sum += i;
		}
	}
	time.stop();

	std::cout << "Sum of primes below " << target << ": " << sum << std::endl;
	std::cout << "Elapsed Time: " << time.durationSeconds() << std::endl;
}
