#include <iostream>

int main() {
	int prevNum = 1;
	int currentNum = 2;
	int tempValue = 0;
	int total = 0;

	while ( currentNum <= 4000000 )	{
		if ( currentNum % 2 == 0 ) {
			total += currentNum;
		}
		tempValue = currentNum;
		currentNum = currentNum + prevNum;
		prevNum = tempValue;
	}
	std::cout << total;
}
