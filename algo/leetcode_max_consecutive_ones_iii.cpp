#include <iostream>
#include <vector>
#include "leetcode_utils.h"

class Solution
{
public:
    int longestOnes(std::vector<int>& nums, int k)
    {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int zeroCount = 0;
        int maxLength = 0;

        while(right < n)
        {
            if(nums[right] == 0)
            {
                ++zeroCount;
            }

            while(zeroCount > k)
            {
                if(nums[left] == 0)
                {
                    --zeroCount;
                }
                ++left;
            }

            maxLength = std::max(maxLength, right - left + 1);
            ++right;
        }

        return maxLength;
    }
};

void runTest(const std::vector<int>& nums, int k, int expected, const std::string& testName)
{
    Solution solution;
    std::vector<int> input = nums;
    const int actual = solution.longestOnes(input, k);
    const bool pass = (actual == expected);

    std::cout << "Test: " << testName << '\n'
              << "Input array: " << nums << '\n'
              << "k: " << k << '\n'
              << "Result:   " << actual << '\n'
              << "Expected: " << expected << '\n'
              << (pass ? "[PASS]" : "[FAIL]") << "\n\n";
}

int main()
{
    runTest({1,1,1,0,0,0,1,1,1,1,0}, 2, 6, "Example 1");
    runTest({0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1}, 3, 10, "Example 2");

    runTest({1,1,1,1,1}, 0, 5, "All ones, k=0");
    runTest({0,0,0,0,0}, 2, 2, "All zeros, k=2");
    runTest({0,0,0,0,0}, 5, 5, "All zeros, k=5");
    runTest({1,0,1,0,1}, 1, 3, "Alternating, k=1");
    runTest({1,0,1,0,1}, 2, 5, "Alternating, k=2");
    runTest({1}, 0, 1, "Single one, k=0");
    runTest({0}, 1, 1, "Single zero, k=1");
    runTest({0}, 0, 0, "Single zero, k=0");
    runTest({}, 0, 0, "Empty array");
}