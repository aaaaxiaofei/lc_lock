360. Sort Transformed Array

Given a sorted array of integers nums and integer values a, b and c. Apply a quadratic function of the form f(x) = ax2 + bx + c to each element x in the array.

The returned array must be in sorted order.

Expected time complexity: O(n)

Example:
nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,

Result: [3, 9, 15, 33]

nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5

Result: [-23, -5, 1, 7]
Credits:
Special thanks to @elmirap for adding this problem and creating all test cases.

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        
        // max/min point is -2*a/b
        // if a < 0, it is max point; if a > 0, it is min point
        
        // find extreme point floor(-2*a/b)
        // two cur, i to left and j to right
         
        int i = 0, j = nums.size() - 1;
        vector<int> result;
        
        while (i <= j) {
            int v1 = f(a, b, c, nums[i]);
            int v2 = f(a, b, c, nums[j]);
            
            if (a >= 0) {
                if (v1 > v2) {
                    result.push_back(v1);
                    i++;
                }
                else {
                    result.push_back(v2);
                    j--;
                }
            }
            else {
                if (v1 > v2) {
                    result.push_back(v2);
                    j--;
                }
                else {
                    result.push_back(v1);
                    i++;
                }
            }
        }
        if (a >= 0) reverse(result.begin(), result.end());
        

        return result;        
    }
    
    int f(int a, int b, int c, int x) {
        return a*x*x + b*x + c;
    }
};