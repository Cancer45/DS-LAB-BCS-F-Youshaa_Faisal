#include <iostream>

void matches(std::string pattern, std::string input)
{
    int pattern_size = pattern.size(), input_size = input.size(), match_count = 0;
    int matches[input_size - pattern_size + 1];
    int badChars[256];
    
    for (int i = 0; i < 256; i++) 
        badChars[i] = -1;
    
    for (int i = 0; i < pattern_size; i++) 
        badChars[pattern[i]] = i;
    
    int shift;
    
    for (int i = 0; i <= input_size - pattern_size;)
    {
        int j;
        for (j = pattern_size - 1; j >= 0; j--)
        {
            if (input[i + j] != pattern[j])
            {
                shift = std::max(1, j - badChars[input[i + j]]);
                i += shift;
                break;
            }
        }
        
        if (j < 0) 
        {
            matches[match_count++] = i;
            i++;
        }
    }
    
    std::cout << "[";
    for (int i = 0; i < match_count; i++)
    {
        std::cout << matches[i];
        if (i != match_count - 1) 
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

int main()
{
    std::string pattern = "the";
    std::string check = "the quick brown fox jumps over the lazy dog.";
    matches(pattern, check);
}