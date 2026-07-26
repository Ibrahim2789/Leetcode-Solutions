#include <iostream>
#include <vector>

using namespace std;

// Given an integer array nums consisting of n elements, find the contiguous subarray of given length k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.
// Complexity Analysis
// Time complexity : O(n) where n is the number of elements in the array
// Space complexity : O(1) where n is the number of elements in the array
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int current = 0;

        for (int i = 0; i < k; i++)
            current += nums[i];

        int maximum = current;

        for (int i = k; i < nums.size(); i++) {

            current += nums[i];
            current -= nums[i - k];

            maximum = max(maximum, current);
        }

        return (double)maximum / k;
    }
};
