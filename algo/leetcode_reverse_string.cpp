#include <iostream>
#include <vector>
#include <string>
#include <utility>

class Solution
{
public:
    void reverseString(std::vector<char>& s)
    {
        int start = 0;
        int end = static_cast<int>(s.size()) - 1;

        while (start < end)
        {
            std::swap(s[start], s[end]);
            ++start;
            --end;
        }
    }
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
{
    os << "{";

    auto it = v.begin();
    auto end = v.end();

    if (it != end)
    {
        os << *it;
        while (++it != end)
        {
            os << ", " << *it;
        }
    }

    os << "}";
    return os;
}

void runTest(const std::vector<char>& input, const std::vector<char>& expected, const std::string& testName)
{
    Solution solution;
    std::vector<char> actual = input;
    solution.reverseString(actual);

    bool pass = (actual == expected);

    std::cout << "Test: " << testName << '\n'
        << "Input:    " << input << '\n'
        << "Result:   " << actual << '\n'
        << "Expected: " << expected << '\n'
        << (pass ? "[PASS]" : "[FAIL]") << "\n\n";
}

int main()
{
    runTest({ 'a','b','c','d','e' }, { 'e','d','c','b','a' }, "Odd length");
    runTest({ 'h','e','l','l','o' }, { 'o','l','l','e','h' }, "Even length");
    runTest({ 'A' }, { 'A' }, "Single char");
    runTest({}, {}, "Empty input");
}
