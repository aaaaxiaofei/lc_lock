527. Word Abbreviation

Given an array of n distinct non-empty strings, you need to generate minimal possible abbreviations for every word following rules below.

Begin with the first character and then the number of characters abbreviated, which followed by the last character.
If there are any conflict, that is more than one words share the same abbreviation, a longer prefix is used instead of only the first character until making the map from word to abbreviation become unique. In other words, a final abbreviation cannot map to more than one original words.
If the abbreviation doesnt make the word shorter, then keep it as original.
Example:
Input: ["like", "god", "internal", "me", "internet", "interval", "intension", "face", "intrusion"]
Output: ["l2e","god","internal","me","i6t","interval","inte4n","f2e","intr4n"]
Note:
Both n and the length of each word will not exceed 400.
The length of each word is greater than 1.
The words consist of lowercase English letters only.
The return answers should be in the same order as the original array.


class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& dict) {
        unordered_map<int, unordered_map<string, unordered_map<char, int>>> m;
        vector<string> result = dict;
        queue<int> q;
        
        for(int i = 0; i < dict.size(); i++) {
            string word = dict[i];
            int sz = word.length();
            if (sz > 3) {
                m[sz][word.substr(0,1)][word.back()]++;
                q.push(i);
            }
        }
        
        int len = 0;
        while (!q.empty()) {
            int n = q.size();
            len++;
            for (int i = 0; i < n; i++) {
                int cur = q.front(); q.pop();
                string word = result[cur];
                string pre = word.substr(0, len);
                if (m[word.size()][pre][word.back()] == 1) {                    
                    if (word.size()-len > 2)
                        result[cur] = pre + to_string(word.size()-len-1) + word.back();
                }
                else {
                    m[word.size()][word.substr(0, len+1)][word.back()]++;
                    q.push(cur);
                }
            }
        }
        
        return result;
        
    }
};