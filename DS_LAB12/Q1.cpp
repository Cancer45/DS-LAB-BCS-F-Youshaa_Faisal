#include <iostream>

void matches(std::string pattern, std::string input)
{
	int pattern_size = pattern.size();
	int input_size = input.size();

	int matches[input_size - pattern_size];
	int match_counter = 0;

	for (int i = 0; i < input_size; i++)
	{
		for (int j = 0; j < pattern_size; j++)
		{
			if (input[i + j] != pattern[j])
			break;

			if (j == pattern_size - 1)
			matches[match_counter++] = i;
		}
	}


	std::cout << "[";
	for (int i = 0; i < match_counter; i++)
	{
		std::cout << matches[i];
		if (i != match_counter - 1) std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

int main ()
{
	std::string patt = "the";
	std::string check = "the quick brown fox jumps over the lazy dog.";

	matches(patt, check);
}
