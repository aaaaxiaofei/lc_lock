163. Missing Ranges 

Given a sorted integer array where the range of elements are in the inclusive range [lower, upper], return its missing ranges.

For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        
        vector<string> res;
        
        for (auto num : nums) {
            if (num - lower == 1) res.push_back(to_string(lower));
            else if (num > lower) {
                res.push_back(to_string(lower) + "->" + to_string(num-1));
            }
            lower = num + 1;
            if (num == INT_MAX) return res;
                
        }

        if (lower <= upper) {
            if (upper - lower == 0) res.push_back(to_string(lower));
            else 
                res.push_back(to_string(lower) + "->" + to_string(upper));
        }
        return res;
    }
};


==== Note ====
Be careful to INT_MAX