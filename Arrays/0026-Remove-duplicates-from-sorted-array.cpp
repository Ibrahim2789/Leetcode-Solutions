#include <iostream>
#include <vector>
using namespace std;

/** Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.
The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.
**/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        vector<int> non_duplicates;
        int no_of_non_duplicates = 0;
        
        for ( size_t i = 0 ; i < nums.size() ; i++ ){
            int counter = 0;

            for ( size_t j = i+1 ; j < nums.size() ; j++ ){
                if ( nums[i] == nums[j] ){
                    counter++;
                }
                if (counter==1){
                    break;
                }
            }

            if(counter==0){
                non_duplicates.push_back(nums[i]);
                no_of_non_duplicates++;
            }

        }
        
        nums = non_duplicates;
        return no_of_non_duplicates++;
    }
};