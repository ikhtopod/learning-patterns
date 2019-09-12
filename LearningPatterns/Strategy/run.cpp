#include "run.h"

#include <iostream>
#include <iomanip>
#include <vector>

namespace Strategy {

void SearchForUniqueElements(const std::vector<int>& numbers, BinarySearch<int>& bs) {
	for (size_t i = 0; i < numbers.size(); ++i) {
		std::cout << "bs.Find(" << numbers[i] << ") == " << i << ": " <<
			std::boolalpha << (bs.Find(numbers[i]) == i) << std::endl;
	}
}

void Run() {
	{
		std::cout << "[Test 1]" << std::endl;

		std::vector<int> numbers { 2, 3, 3, 4 };
		BinarySearch<int> bs { numbers };

		const size_t i0 = 0;
		const size_t i1 = 1;
		const size_t i2 = 2;
		const size_t i3 = 3;

		std::cout << "bs.Find(" << numbers[i0] << ") == " << i0 << ": " <<
			std::boolalpha << (bs.Find(numbers[i0]) == i0) << std::endl;

		std::cout << "bs.Find(" << numbers[i1] << ") == " << i1 << ": " <<
			std::boolalpha << (bs.Find(numbers[i1]) == i1) << std::endl;

		std::cout << "bs.Find(" << numbers[i2] << ") == " << i1 << ": " <<
			std::boolalpha << (bs.Find(numbers[i2]) == i1) << std::endl;

		std::cout << "bs.Find(" << numbers[i3] << ") == " << i3 << ": " <<
			std::boolalpha << (bs.Find(numbers[i3]) == i3) << std::endl;
	}

	{
		std::cout << "[Test 2]" << std::endl;

		std::vector<int> numbers { 2, 7, 12, 31, 90, 114 };
		BinarySearch<int> bs { numbers };

		SearchForUniqueElements(numbers, bs);
	}

	{
		std::cout << "[Test 3]" << std::endl;

		std::vector<int> numbers {
			8, 14, 26, 28, 38, 47, 56,
			60, 64, 69, 70, 78, 80, 82,
			84, 87, 90, 92, 98, 108
		};

		BinarySearch<int> bs { numbers };

		SearchForUniqueElements(numbers, bs);
	}
}

} // namespace Strategy
