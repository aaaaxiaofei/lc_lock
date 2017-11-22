244. Shortest Word Distance II

This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters. How would you optimize it?

Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list.

For example,
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Given word1 = “coding”, word2 = “practice”, return 3.
Given word1 = "makes", word2 = "coding", return 1.

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.



class WordDistance {
public:
    WordDistance(vector<string> words) {
        for (int i = 0; i < words.size(); i++) {
            m[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        if (result[word1][word2] != 0) return result[word1][word2];
        
        int min_dist = INT_MAX;
        
        int i = 0, j = 0;
        
        while (i < m[word1].size() && j < m[word2].size()) {
            min_dist = min(min_dist, std::abs(m[word1][i] - m[word2][j]));
            m[word1][i] < m[word2][j] ? i++ : j++;
        }
        
        
        result[word1][word2] = min_dist;
        result[word2][word1] = min_dist;
        
        return min_dist;
    }
    
private:
    unordered_map<string, vector<int>> m;
    unordered_map<string, unordered_map<string, int>> result;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */