269. Alien Dictionary

There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.

Example 1:
Given the following words in dictionary,

[
  "wrt",
  "wrf",
  "er",
  "ett",
  "rftt"
]
The correct order is: "wertf".

Example 2:
Given the following words in dictionary,

[
  "z",
  "x"
]
The correct order is: "zx".

Example 3:
Given the following words in dictionary,

[
  "z",
  "x",
  "z"
]
The order is invalid, so return "".

Note:
You may assume all letters are in lowercase.
You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
If the order is invalid, return an empty string.
There may be multiple valid order of letters, return any one of them is fine.

class Solution {
public:
    string alienOrder(vector<string>& words) {
        // find the immediate follower of each char, in unordered_map<char, vector<char>> map1
        // keep track of how many immediate chars are before a char unordered_map<char, int> map2
        
        // while loop:
        //      put all chars without any char before it in a stack
        //      remove this char from the dict, put in the final string
        //      update map2, put new chars which have no pre-char in to the stack
        // exit when the stack is empty
        
        // return string, or "" if string size is less than the map size
        
        
        unordered_map<char, set<char>> follow;
        unordered_map<char, set<char>> num_pre;
        unordered_map<char, int> all_char;
        
        // Get all chars in the dict
        for (auto word : words) 
            for (auto c : word)
                all_char[c] = 1;
        
        // Find pre and after relationship of all chars
        construct_map(words, follow, num_pre);
        
        // printf("%d, %d \n", follow.size(), num_pre.size());
        
        
        // Put leading chars in stack
        stack<char> stk;      
        for (auto it = all_char.begin(); it != all_char.end(); it++) {
            char c = it->first;
            if (num_pre[c].size() == 0)
                stk.push(it->first);
        }
        // printf("%d \n", stk.size());
        
        string result = "";
        
        while (!stk.empty()) {
            char cur = stk.top();
            stk.pop();
            result += cur;
            
            for (auto it = follow[cur].begin(); it != follow[cur].end(); it++) {
                num_pre[*it].erase(cur);
                if (num_pre[*it].empty())
                    stk.push(*it);
            }
            
        }
        
        // printf("%s \n", result.c_str());
        
        return result.size() == all_char.size() ? result : "";
        
    }
    
    void construct_map(vector<string>& words, unordered_map<char, set<char>>& follow, unordered_map<char, set<char>>& num_pre) {
        
        unordered_map<char, vector<string>> m;

        if (words.size() > 1) {
            char cur = words[0][0];
            if (words[0].size() > 1)
                m[cur].push_back(words[0].substr(1));
            
            for (int i = 1; i < words.size(); i++) {
                char c = words[i][0];
                if (c != cur) {
                    follow[cur].insert(c);
                    num_pre[c].insert(cur);
                    cur = c;
                }
                if (words[i].size() > 1)
                    m[c].push_back(words[i].substr(1));
            }
            
            for (auto it = m.begin(); it != m.end(); it++) {
                construct_map(it->second, follow, num_pre);
            }
        }
    }
};



======== Other Better Solution ========
string alienOrder(vector<string>& words) {
    map<char, set<char>> suc, pre;
    set<char> chars;
    string s;
    for (string t : words) {
        chars.insert(t.begin(), t.end());
        for (int i=0; i<min(s.size(), t.size()); ++i) {
            char a = s[i], b = t[i];
            if (a != b) {
                suc[a].insert(b);
                pre[b].insert(a);
                break;
            }
        }
        s = t;
    }
    set<char> free = chars;
    for (auto p : pre)
        free.erase(p.first);
    string order;
    while (free.size()) {
        char a = *begin(free);
        free.erase(a);
        order += a;
        for (char b : suc[a]) {
            pre[b].erase(a);
            if (pre[b].empty())
                free.insert(b);
        }
    }
    return order.size() == chars.size() ? order : "";
}