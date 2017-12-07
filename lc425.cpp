425. Word Squares

Given a set of words (without duplicates), find all word squares you can build from them.

A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).

For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word reads the same both horizontally and vertically.

b a l l
a r e a
l e a d
l a d y
Note:
There are at least 1 and at most 1000 words.
All words will have the exact same length.
Word length is at least 1 and at most 5.
Each word contains only lowercase English alphabet a-z.
Example 1:

Input:
["area","lead","wall","lady","ball"]

Output:
[
  [ "wall",
    "area",
    "lead",
    "lady"
  ],
  [ "ball",
    "area",
    "lead",
    "lady"
  ]
]

Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
Example 2:

Input:
["abat","baba","atan","atal"]

Output:
[
  [ "baba",
    "abat",
    "baba",
    "atan"
  ],
  [ "baba",
    "abat",
    "baba",
    "atal"
  ]
]

Explanation:
The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
Seen this question in a real interview before?   Yes  

class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        
        unordered_map<string, vector<string>> m;
        for (auto word : words) {
            for (int i = 1; i < word.size(); i++) {
                m[word.substr(0, i)].push_back(word);
            }
        }
        vector<vector<string>> result;
        
        for (auto word : words) {
            int len = 1;
            vector<string> v(1, word);
            dfs(word, len, m, v, result);
        }
        
        return result;
    }
    
    void dfs(string& word, int len, unordered_map<string, vector<string>>& m, vector<string>& v, vector<vector<string>>& result) {
        
        if (len == word.size()) {
            result.push_back(v);
            return;
        }
        
        string s = "";       
        for (int i = 0; i < len; i++) {
            s += v[i][len];
        }
        
        for (auto str : m[s]) {
            v.push_back(str);
            dfs(word, len+1, m, v, result);
            v.pop_back();
        }
    }
    
};