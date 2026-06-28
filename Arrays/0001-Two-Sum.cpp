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