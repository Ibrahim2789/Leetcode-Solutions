#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for ( unsigned i = 0 ; i < nums.size() ; i++){
            for ( unsigned j = i+1 ; j < nums.size() ; j++){
                if ( nums[i] + nums[j] == target){
                    return { (int)i, (int)j};
                }
            }
        }
        return {};
    }
};

//If given array is sorted then we can use two pointer approach to solve the problem in O(n) time complexity and O(1) space complexity.
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;

        while (left < right){
            int sum = nums[left] + nums[right];

            if ( sum > target){
                right--;
            }
            else if ( sum < target ){
                left++;
            }
            else{
                return {left,right};
            }
        }
        return {};
    }
};