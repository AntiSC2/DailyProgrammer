//Copyright Jakob Sinclair 2015
#include <iostream>
#include <vector>

bool cell_xor(std::vector<bool> cells, int index = 0) {
	if (cells.size() > 1) {
		if (index > 0 && index < cells.size() - 1) {
			if (cells[index - 1] == 1 && cells[index + 1] != 1) {
				return true;
			}
			else if (cells[index - 1] != 1 && cells[index + 1] == 1) {
				return true;
			}
		} if (index == 0) {
			if (cells[index + 1] == 1) {
				return true;
			}
		} else if (index == cells.size() - 1) {
			if (cells[index - 1] == 1) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	bool cell = false;
	std::vector<bool> cells;
	int count = 0;
	std::cout << "Type in a row consisting of multiple 0 and 1:\n";
	while (true) {
		count = 0;
		char c = '0';
		std::cin.get(c);
		if (c == 's') {
			while (count < 25) {
				std::cout << std::endl;
				std::vector<bool> temp;
				for (int i = 0; i < cells.size(); i++) {
					temp.push_back(cell_xor(cells, i));
					if (cells[i] == true)
						std::cout << 'X';
					else
						std::cout << ' ';
				}
				cells = temp;
				count++;
			}
			std::cout << std::endl;
		} else {
			cell = c == '1';
			cells.push_back(cell);
		}
	}
	return 0;
}