249. Group Shifted Strings

Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:

"abc" -> "bcd" -> ... -> "xyz"
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.

For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
A solution is:

[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        
        // loop over result vector, if not find same group, push into a new group
        // if one digit, same group
        // if not same length, not same group
        
        vector<vector<string>> result;
        unordered_map<string, vector<string>> m;
        
        for (auto s : strings) {
            string base = root(s);
            
            m[base].push_back(s);
        }
        
        for (auto it = m.begin(); it != m.end(); it++) {
            result.push_back(it->second);
        }
        return result;
        
    }
    
    string root(string s) {
        
        int dist = (s[0] - 'a' + 26) % 26;
        string base = "";
        
        for (int i = 0; i < s.size(); i++) {
            char c = (s[i] - 'a') >= dist ? (s[i] - dist) : (s[i] + 26 - dist);
            base += c;
        }
        
        return base;
    }
};