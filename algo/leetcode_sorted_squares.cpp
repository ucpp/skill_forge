#include <iostream>
#include <vector>
#include <cmath>
#include "leetcode_utils.h"

class Solution
{
public:
    std::vector<int> sortedSquares(std::vector<int>& nums)
    {
        const int n = nums.size();
        std::vector<int> result(n);
        int left = 0;
        int right = n - 1;
        
        for (int i = n - 1; i >= 0; --i)
        {
            if (std::abs(nums[left]) > std::abs(nums[right]))
            {
                result[i] = nums[left] * nums[left];
                ++left;
            }
            else
            {
                result[i] = nums[right] * nums[right];
                --right;
            }
        }
        
        return result;
    }
};

void runTest(const std::vector<int>& input, const std::vector<int>& expected, const std::string& testName)
{
    Solution solution;
    std::vector<int> actualInput = input;
    std::vector<int> actual = solution.sortedSquares(actualInput);

    bool pass = (actual == expected);

    std::cout << "Test: " << testName << '\n'
        << "Input:    " << input << '\n'
        << "Result:   " << actual << '\n'
        << "Expected: " << expected << '\n'
        << (pass ? "[PASS]" : "[FAIL]") << "\n\n";
}

int main()
{
    runTest({ -4, -1, 0, 3, 10 }, { 0, 1, 9, 16, 100 }, "Mixed positive and negative");
    runTest({ -7, -3, 2, 3, 11 }, { 4, 9, 9, 49, 121 }, "All negatives and positives");
    runTest({ -5, -3, -2, -1 }, { 1, 4, 9, 25 }, "All negatives");
    runTest({ 1, 2, 3, 4, 5 }, { 1, 4, 9, 16, 25 }, "All positives");
    runTest({ 0 }, { 0 }, "Single zero");
    runTest({}, {}, "Empty input");
}