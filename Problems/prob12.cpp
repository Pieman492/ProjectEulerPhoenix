#include <cmath>
#include <iostream>
#include "../Utility/Utility.hpp"

int main() {
	int divisorCount = 0;
	int target = 500;
	int triangleNumber = 0;
	int triangleSqrt = 0;
	util::Timekeeper time;
	
	time.start();
	for (int n = 1; divisorCount <= target; n++) {
			divisorCount = 2;
			triangleNumber += n;
			triangleSqrt = std::sqrt(triangleNumber);
			for (int i = 2; i <= triangleSqrt; i++) {
				if (triangleNumber % i == 0) {
					if (triangleNumber / i == triangleSqrt) {
						divisorCount += 1;
					} else {
						divisorCount += 2;
					}
				}
			} 
	}
	time.stop();

	std::cout << "First Triangle Number with over " << target << " Divisors: " << triangleNumber << std::endl;
	std::cout << "Time elapsed: " << time.durationAuto() << std::endl;

}
