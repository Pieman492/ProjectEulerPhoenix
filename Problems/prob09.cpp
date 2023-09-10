#include "../Utility/Utility.hpp"
#include <cmath>

long bruteForce(int target, std::vector<int>* squareNumbers) {
	// TODO: Find ways to reduce the amount of computations further.
	int aSquared = 0;
	int bSquared = 0;
	int cSquared = 0;
	// Since c > b > a; we can cut a loop short when we reach the same square
	for (int c = 0; c < squareNumbers->size(); c++) {
		cSquared = squareNumbers->at(c);
		for (int b = 0; b < c; b++) {
			bSquared = squareNumbers->at(b);
			for (int a = 0; a < b; a++) {
				aSquared = squareNumbers->at(a);
				if (aSquared+bSquared == cSquared) {
					if (sqrt(aSquared) + sqrt(bSquared) + sqrt(cSquared) == target)
						return sqrt(aSquared) * sqrt(bSquared) * sqrt(cSquared);
				}
			}
		}
	}
	return 0;
}

int main(int argc, char* argv[]) {
	int target = std::strtol(argv[1], nullptr, 0);
	std::vector<int>* squareNumbers = new std::vector<int>;
	util::Timekeeper* timekeeper	= new util::Timekeeper;
	
	timekeeper->start();
	// TODO: Find an actual upper bound on this instead of making an educated
	// guess.
	for (int i = 1; i*i <= target*target; i++) {
		squareNumbers->push_back(i*i);
	}
	std::cout << "Answer: " << bruteForce(target, squareNumbers) << std::endl;
	timekeeper->stop();
	std::cout << "Time: " << timekeeper->durationMilliseconds() << "ms" << std::endl;
	delete timekeeper;

}
