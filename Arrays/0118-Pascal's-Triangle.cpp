#include <vector>
#include <iostream>

using namespace std;
// 118. Pascal's Triangle


// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it
//Complexity Analysis
// Time complexity : O(numRows^2). We are using two nested loops.
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;  // Starts empty

    for (int i = 0; i < numRows; i++) {
        // Build the entire row FIRST
        vector<int> row(i + 1, 1);
    
        // Fill middle values (if any)
        for (size_t j = 1; j < row.size() - 1; j++) {
            row[j] = result[i-1][j-1] + result[i-1][j];
        }
    
        // THEN add row to result
        result.push_back(row);
    }
    return result;
    }
};