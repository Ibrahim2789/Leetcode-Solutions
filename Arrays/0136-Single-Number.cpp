#include <vector>
#include <iostream>

using namespace std;

/*Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {

        for ( size_t i = 0 ; i < nums.size() ; i++){
            int count = 0;
            for ( size_t j = 0 ; j < nums.size() ; j++){
                if ( nums[i] == nums[j] ){
                    count++;
                }
                if ( count > 1 ){
                    break;
                }
            }
            if ( count == 1 ){
                return nums[i];
            }
        }
        return -1;
    }
};