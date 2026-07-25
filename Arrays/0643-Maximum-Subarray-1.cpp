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
        double current = 0;

        for ( int i = 0 ; i < k ; i++ ){
            current += nums[i];
        }
        double max_average = current/k;

        for ( size_t i = 1 ; i < nums.size()-k+1 ; i++ ){
            current = current - nums[i-1] + nums[i+k-1];
            current /= k;

            if ( current > max_average ){
                max_average = current;
            }
        }
        return max_average;
    }
};
