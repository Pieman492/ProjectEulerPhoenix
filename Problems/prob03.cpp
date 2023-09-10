#include <iostream>
#include <vector>
#include <cmath>
#include "../Utility/Utility.hpp"

int main() {
	long num = 600851475143L; // I hate this fucking number now
	int start = 0;
	long gpf = 0;
	std::vector<int> basis = std::vector<int>{ 2, 3, 5, 7, 11, 13, 17 };
	util::Timekeeper time;
	
	time.start();
	util::LoopingLinkedList<int> increments = util::getIncrements(&basis, &start);
	for (long i = 1; i < num; i++) {
		if ( num % i == 0 && util::isPrimeWheel(num / i, start, &basis, &increments) ) {
			gpf = num / i;
			i = num + 1;
		}
	}
	time.stop();

	std::cout << "Final GPF: " << gpf << std::endl;	
	std::cout << "Elapsed time: " << time.durationAuto() << std::endl;

}
