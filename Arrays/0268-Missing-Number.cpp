#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
// 268. Missing Number
// Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.
//Complexity Analysis
// Time complexity : O(nlogn). The time complexity is dominated by the O(nlogn) time complexity of the sort operation.
// Space complexity : O(1). No extra space is used.
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for ( size_t i = 0 ; i < nums.size() ; i++ ){
            if ( nums[i] != i ){
                return i;
            }
        }
        return nums.size();
    }
};