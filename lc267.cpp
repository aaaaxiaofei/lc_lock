267. Palindrome Permutation II

Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.

For example:

Given s = "aabb", return ["abba", "baab"].

Given s = "abc", return [].


class Solution {
public:
    vector<string> generatePalindromes(string s) {
        
        unordered_map<char, int> m;
        vector<string> result;
        int odd = 0;
        
        for (auto c : s) {
            if ((++m[c])%2 == 1) odd++;
            else odd--;
        }
        
        if (odd > 1) return {};
        
        // Start from the center
        string str = "";
        if (odd == 1) {
            for (auto it = m.begin(); it != m.end(); it++) {
                if (it->second%2 == 1) {
                    m[it->first]--;
                    str += it->first;
                    break;
                }
            }
        }
        
        
        
        dfs(str, m, result, s.size());
        
        return result;
    }
    
    void dfs(string s, unordered_map<char, int>& m, vector<string>& result, int n) {
        
        if (s.size() == n) {
            result.push_back(s);
        }
        else {
            for (auto it = m.begin(); it != m.end(); it++) {
                if (it->second > 0) {
                    char c = it->first;
                    string str = c + s + c;
                    m[c] -= 2;
                    dfs(str, m, result, n);
                    m[c] += 2;
                }
            }
        }
        
    }
};


==== Use C++ next_permutation() ======
class Solution {
public:
    vector<string> generatePalindromes(string s) {
		vector<string> palindromes;
        unordered_map<char, int> counts;
        for (char c : s) counts[c]++;
        int odd = 0; char mid; string half;
        for (auto p : counts) {
            if (p.second & 1) {
                odd++, mid = p.first;
				if (odd > 1) return palindromes;
            }
            half += string(p.second / 2, p.first);
        }
        palindromes = permutations(half);
        for (string& p : palindromes) {
            string t(p);
            reverse(t.begin(), t.end());
			if (odd) t = mid + t;
            p += t;
        }
        return palindromes;
    }
private: 
    vector<string> permutations(string& s) {
        vector<string> perms;
        string t(s);
        do {
            perms.push_back(s);
            next_permutation(s.begin(), s.end()); 
        } while (s != t);
        return perms; 
    }
};