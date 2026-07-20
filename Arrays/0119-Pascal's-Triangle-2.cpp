#include <vector>
#include <iostream>

using namespace std;
// 119. Pascal's Triangle II
// Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
// In Pascal's triangle, each number is the sum of the two numbers directly above it
//Complexity Analysis
// Time complexity : O(rowIndex^2). We are using two nested loops.

class Solution {
public:
    vector<int> getRow(int rowIndex) {
    vector<int> previous_row;
    for (int i = 0; i <= rowIndex ; i++) {
        // Build the entire row FIRST
        vector<int> new_row(i + 1, 1);
    
        // Fill middle values (if any)
        for (size_t j = 1; j < new_row.size() - 1; j++) {
            new_row[j] = previous_row[j-1] + previous_row[j];
        }
    
        // THEN add row to result
        previous_row = new_row;
    }
    return previous_row;
    }
};