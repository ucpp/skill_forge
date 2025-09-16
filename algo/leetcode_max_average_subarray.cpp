#include <iostream>
#include <vector>
#include <algorithm>
#include "leetcode_utils.h"

class Solution
{
public:
    double findMaxAverage(std::vector<int>& nums, int k)
    {
        const size_t n = nums.size();
        const size_t windowSize = static_cast<size_t>(k);

        double windowSum = 0;
        for (size_t i = 0; i < windowSize; ++i)
        {
            windowSum += nums[i];
        }

        double maxSum = windowSum;

        for (size_t i = windowSize; i < n; ++i)
        {
            windowSum += nums[i] - nums[i - windowSize];
            maxSum = std::max(maxSum, windowSum);
        }

        return maxSum / static_cast<double>(k);
    }
};

void runTest(const std::vector<int>& nums, int k, double expected, const std::string& testName)
{
    Solution solution;
    std::vector<int> input = nums;
    const double actual = solution.findMaxAverage(input, k);
    const bool pass = std::abs(actual - expected) < 1e-5;

    std::cout << "Test: " << testName << '\n'
              << "Input array: " << nums << '\n'
              << "k: " << k << '\n'
              << "Result:   " << actual << '\n'
              << "Expected: " << expected << '\n'
              << (pass ? "[PASS]" : "[FAIL]") << "\n\n";
}

int main()
{
    runTest({1, 12, -5, -6, 50, 3}, 4, 12.75, "Basic test");
    runTest({5}, 1, 5.0, "Single element");
    runTest({0, 1, 1, 3, 3}, 2, 3.0, "Repeated values");
    runTest({-1, -2, -3, -4, -5}, 3, -2.0, "All negatives");
    runTest({1, 2, 3, 4, 5}, 5, 3.0, "Full array average");
}