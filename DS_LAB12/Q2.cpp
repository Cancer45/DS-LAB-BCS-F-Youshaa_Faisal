#include <iostream>
#include <cmath>

int hash(std::string input)
{
	int base = 257, hash = 0;
	int modulus = pow(10, 9) + 7;
	int input_length = input.length();

	for (int i = 0; i < input_length; i++)
	hash += (input[i] * ((int)pow(base, input_length - i - 1)) % modulus);

	return hash;
}

void matches(std::string pattern, std::string input)
{
	int pattern_size = pattern.size();
	int input_size = input.size();
	int pattern_hash = hash(pattern);


	int matches[input_size - pattern_size];
	int match_counter = 0;
	std::string sample;

	for (int i = 0; i <= input_size - pattern_size; i++)
	{
		sample.clear();
		for (int j = 0; j < pattern_size; j++)
		sample.push_back(input[i + j]);

		if (hash(sample) != pattern_hash)
		continue;

		for (int j = 0; j < pattern_size; j++)
		{
			if (input[i + j] != pattern[j]) break;

			if (j == pattern_size - 1) matches[match_counter++] = i;
		}
	}

	std::cout << "[";
	for (int i = 0; i < match_counter; i++)
	{
		std::cout << matches[i];

		if (i != match_counter - 1)
		std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

int main ()
{
	std::string pattern = "the";
	std::string check = "the quick brown fox jumps over the lazy dog.";
	matches(pattern, check);
}
