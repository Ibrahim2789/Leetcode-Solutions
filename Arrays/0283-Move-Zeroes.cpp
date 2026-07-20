#include <vector>
#include <iostream>

using namespace std;
// 283. Move Zeroes
// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
// Note that you must do this in-place without making a copy of the array.
//Complexity Analysis
// Time complexity : O(n). We traverse the array containing n elements only once.
// Space complexity : O(1). No extra space is used.
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int write = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[write], nums[i]);
                write++;
            }
        }
    }
};