/*Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.*/
#include <vector>

// O(n^2) time complexity
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maxCountNumber = 0;
        for ( size_t i = 0 ; i < nums.size() ; i++){
            int count = 0;
            for ( size_t j = 0 ; j < nums.size() ; j++){
                if ( nums[i] == nums[j] ){
                    count++;
                }
            }
            if ( count >= (nums.size()/2)){
                return  nums[i];

            }
        }    
        return -1;
    }

};

// O(n) time complexity using Boyer-Moore Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int count = 0;
        for (int num : nums) {
            if ( count == 0 ){
                candidate = num;
                count = 1;
            }
            else if ( num == candidate ){
                count++;
            }
            else{
                count--;
            }
        }
    return candidate;
    }
};