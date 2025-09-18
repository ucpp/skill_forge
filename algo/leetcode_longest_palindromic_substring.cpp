#include <iostream>
#include <string>

class Solution
{
public:
    std::string longestPalindrome(std::string s)
    {
        const int n = s.size();
        int start = 0;
        int maxLength = 1;

        for (int i = 0; i < n; i++)
        {
            expandFromCenter(s, i, i, start, maxLength);
            expandFromCenter(s, i, i + 1, start, maxLength);
        }

        return s.substr(start, maxLength);
    }

private:
    void expandFromCenter(const std::string& s, int left, int right, int& start, int& maxLength)
    {
        const int n = s.size();

        while (left >= 0 && right < n && s[left] == s[right])
        {
            const int currentLength = right - left + 1;
            if (currentLength > maxLength)
            {
                start = left;
                maxLength = currentLength;
            }
            left--;
            right++;
        }
    }
};

void runTest(const std::string& s, const std::string& expected, const std::string& testName)
{
    Solution solution;
    std::string input = s;
    std::string actual = solution.longestPalindrome(input);
    bool pass = (actual == expected);

    std::cout << "Test: " << testName << '\n'
              << "Input:    \"" << s << "\"\n"
              << "Result:   \"" << actual << "\"\n"
              << "Expected: \"" << expected << "\"\n"
              << (pass ? "[PASS]" : "[FAIL]") << "\n\n";
}

int main()
{
    runTest("babad", "bab", "Example 1");
    runTest("cbbd", "bb", "Example 2");

    runTest("a", "a", "Single character");
    runTest("aa", "aa", "Two same characters");
    runTest("ab", "a", "Two different characters");
    runTest("", "", "Empty string");

    runTest("racecar", "racecar", "Odd length palindrome");
    runTest("abcba", "abcba", "Another odd palindrome");

    runTest("abba", "abba", "Even length palindrome");
    runTest("aabbaa", "aabbaa", "Another even palindrome");

    runTest("abcde", "a", "No palindrome longer than 1");
    runTest("aabcdcb", "bcdcb", "Mixed case 1");
    runTest("abcdcba", "abcdcba", "Full string palindrome");

    runTest("aaaaaaaaaa", "aaaaaaaaaa", "All same characters");
    runTest("abababababa", "abababababa", "Alternating pattern");

    runTest("abcda", "a", "Palindrome at beginning/end");
    runTest("xabay", "aba", "Palindrome in middle");
}