#include <iostream>
#include <string>

class Solution
{
public:
    std::string removeVowels(std::string s)
    {
        const int n = s.size();
        int j = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u')
            {
                s[j] = s[i];
                ++j;
            }
        }

        return s.substr(0, j);
    }
};

void runTest(const std::string& input, const std::string& expected, const std::string& testName)
{
    Solution solution;
    std::string actual = solution.removeVowels(input);
    bool pass = (actual == expected);

    std::cout << "Test: " << testName << '\n'
              << "Input:    \"" << input << "\"\n"
              << "Result:   \"" << actual << "\"\n"
              << "Expected: \"" << expected << "\"\n"
              << (pass ? "[PASS]" : "[FAIL]") << "\n\n";
}

int main()
{
    runTest("leetcodeisacommunityforcoders", "ltcdscmmntyfrcdrs", "Example 1");
    runTest("aeiou", "", "Example 2");

    runTest("", "", "Empty string");
    runTest("a", "", "Single vowel");
    runTest("b", "b", "Single consonant");
    runTest("bcdfghjklmnpqrstvwxyz", "bcdfghjklmnpqrstvwxyz", "All consonants");

    runTest("hello world", "hll wrld", "Hello world");
    runTest("programming", "prgrmmng", "Programming");
    runTest("algorithm", "lgrthm", "Algorithm");
    runTest("beautiful", "btfl", "Beautiful");

    runTest("aeiouaeiou", "", "Only vowels repeated");
    runTest("aaeeiioouu", "", "Only vowels pairs");

    runTest("bcdfg", "bcdfg", "Only consonants");
    runTest("xyz", "xyz", "End consonants");

    runTest("aabbccddee", "bbccdd", "Alternating vowels consonants");
    runTest("abcde", "bcd", "Mixed sequence");

    runTest("aaaaaaaaaab", "b", "Many vowels one consonant");
    runTest("bbbbbbbbbba", "bbbbbbbbbb", "Many consonants one vowel");
}