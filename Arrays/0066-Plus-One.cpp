#include <vector>
#include <iostream>
using namespace std;

/*You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {

        int size = digits.size()-1;
        int carry = 1;

        for (size_t i = size+1 ; i > 0 ; i--){

            int sum = digits[i-1] + carry;
            digits[i-1] = sum % 10;
            carry = sum / 10;

            if ( carry == 0 ){
                break;
            }
        }

        if ( carry == 1){
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};