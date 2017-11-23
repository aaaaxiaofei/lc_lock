247. Strobogrammatic Number II

A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Find all strobogrammatic numbers that are of length = n.

For example,
Given n = 2, return ["11","69","88","96"].

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {

        vector<string> dict = {"0", "1", "8", "6", "9"};
        vector<string> res;
        
        int center;
        if (n % 2 == 0) center = 5;
        else center = 3;
        
        for (int i = 0; i < center; i++) {
            if (n == 2 && i == 0) continue;
            string s = dict[i];
            helper(s, (n-1)/2-1, dict, res, n%2);
        }
        
        
        return res;
        
    }
    
    void helper(string s, int cur, vector<string>& dict, vector<string>& res, int mod) {
        
        if (cur == -1) {
            for (int i = s.size() - 1 - mod; i >= 0; i--) {
                
                if (s[i] == '6') s += "9";
                else if (s[i] == '9') s += "6";
                else s += s[i];
            }
            res.push_back(s);
        }
        else {
            for (int i = 0; i < dict.size(); i++) {
                if (cur == 0 && dict[i] == "0") continue;
                helper(dict[i] + s, cur-1, dict, res, mod);
            }
        }
        
    }
};



// Other's simple solution, add pair to two ends
class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return helper(n , n);
    }
    vector<string> helper(int m, int n){
        if(m == 0) return vector<string>({""});
        if(m == 1) return vector<string>({"0", "1", "8"});
        vector<string> tmp = helper(m - 2, n), res;
        for(int i = 0; i < tmp.size(); i++){
            if(m != n) res.push_back("0" + tmp[i] + "0");
            res.push_back("1" + tmp[i] + "1");
            res.push_back("6" + tmp[i] + "9");
            res.push_back("8" + tmp[i] + "8");
            res.push_back("9" + tmp[i] + "6");
        }
        return res;
    }
};