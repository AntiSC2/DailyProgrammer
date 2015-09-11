//Copyright Jakob Sinclair 2015
#include <iostream>
#include <string>

bool test_word(std::string word) {
	char min = word[0];
	if (min < 97) {
		min += 32;
	}
	for (int i = 1; i < word.size(); i++) {
		char letter = word[i];
		if (letter < 97) {
			letter += 32;
		}
		if (letter < min) {
			return false;
		}
	}
	return true;
}

bool test_word_reverse(std::string word) {
	char min = word[word.size() - 1];
	if (min < 97) {
		min += 32;
	}
	for (int i = word.size() - 2; i >= 0; i--) {
		char letter = word[i];
		if (letter < 97) {
			letter += 32;
		}
		if (letter < min) {
			return false;
		}
	}
	return true;
}

int main() {
	std::string input;
	while (true) {
		std::cin >> input;
		if (input == "exit") {
			break;
		} else {
			if (test_word(input)) {
				std::cout << input << " IS IN ORDER" << std::endl;
			} else if (test_word_reverse(input)) {
				std::cout << input << " IS IN REVERSE ORDER" << std::endl;
			} else {
				std::cout << input << " IS NOT IN ORDER" << std::endl;
			}
		}
	}
	return 0;
}