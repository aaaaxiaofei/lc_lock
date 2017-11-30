320. Generalized Abbreviation

Write a function to generate the generalized abbreviations of a word.Example:

Given word = "word", return the following list (order does not matter):
["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]

class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        
        if (word.size() == 0) return {""};
        
        vector<string> result;
        
        for (int len = 0; len <= word.size(); len++) {
            string cur = len == 0 ? "" : to_string(len);
            if (len < word.size()) cur += word[len];
            string remain;
            if (len < word.size() - 1)
                remain = word.substr(len+1);
            
            if (remain.size() > 0) {
                vector<string> after = generateAbbreviations(remain);
                for (auto s : after) {
                    result.push_back(cur + s);
                }
            }
            else 
                result.push_back(cur);
        }
        
        return result;
    }
};


====== Other Solution =======
public List<String> generateAbbreviations(String word) {
    List<String> res = new ArrayList<>();
    DFS(res, new StringBuilder(), word.toCharArray(), 0, 0);
    return res;
}

public void DFS(List<String> res, StringBuilder sb, char[] c, int i, int num) {
    int len = sb.length();  
    if(i == c.length) {
        if(num != 0) sb.append(num);
        res.add(sb.toString());
    } else {
        DFS(res, sb, c, i + 1, num + 1);               // abbr c[i]

        if(num != 0) sb.append(num);                   // not abbr c[i]
        DFS(res, sb.append(c[i]), c, i + 1, 0);        
    }
    sb.setLength(len); 
}