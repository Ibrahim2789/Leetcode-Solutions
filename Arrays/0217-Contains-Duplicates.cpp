#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
// 217. Contains Duplicate
// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
//Complexity Analysis
// Time complexity : O(nlogn). The time complexity is dominated by the O(nlogn) time complexity of the sort operation.
// Space complexity : O(1). No extra space is used.
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1])
                return true;
        }

    return false;
    }
};