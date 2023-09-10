#include <iostream>
#include <cmath>
#include <cstdlib> 

int main(int argc, char *argv[]) {
		int num = std::strtol(argv[1], nullptr, 0);
		double sumOfSquares = 0;
		double squareOfSum = 0;
		// The following lines are closed forms of the sums in question, Square of
		// Sum derrived via simple algebra and logic, and the Sum of Squares 
		// derrived via Polynomial Fitting.
		sumOfSquares = pow(num, 3)/3 + pow(num, 2)/2 + num/6;
		squareOfSum = pow( (pow(num, 2) + num)/2, 2);
		std::cout << "The difference is: " << static_cast<int>( squareOfSum - sumOfSquares ) << std::endl;
}
