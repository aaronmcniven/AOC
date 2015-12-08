#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

bool load(std::vector<std::vector<int>> &values) {
	
	std::ifstream file("input.txt");

	if (file.is_open()) {
		std::string line;
		while (getline(file, line)) {
			std::string value;
			std::stringstream ss(line);
			std::vector<int> x;
			while (getline(ss, value, 'x')) {
				x.push_back(atoi(value.c_str()));
			}
			std::sort(std::begin(x), std::end(x));
			values.push_back(x);
		}
		file.close();
	}
	else {
		return false;
	}
	return true;
}

int main() {

	std::vector<std::vector<int>> presents;

	int total = 0;

	if (load(presents)) {

		for (int i = 0; i < presents.size(); ++i) {
			std::vector<int> &present = presents[i];
			total += 2 * (present[0] * present[1]);
			total += 2 * (present[1] * present[2]);
			total += 2 * (present[2] * present[0]);
			total += present[0] * present[1];
		}
	}
	
	printf("Result: %i\n", total);
	system("PAUSE");

	return 0;
}