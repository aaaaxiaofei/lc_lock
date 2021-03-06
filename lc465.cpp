465. Optimal Account Balancing

A group of friends went on holiday and sometimes lent each other money. For example, Alice paid for Bills lunch for $10. 
Then later Chris gave Alice $5 for a taxi ride. We can model each transaction as a tuple (x, y, z) which means person x gave person y $z. 
Assuming Alice, Bill, and Chris are person 0, 1, and 2 respectively (0, 1, 2 are the persons ID), 
	the transactions can be represented as [[0, 1, 10], [2, 0, 5]].

Given a list of transactions between a group of people, return the minimum number of transactions required to settle the debt.

Note:

A transaction will be given as a tuple (x, y, z). Note that x ≠ y and z > 0.
Persons IDs may not be linear, e.g. we could have the persons 0, 1, 2 or we could also have the persons 0, 2, 6.
Example 1:

Input:
[[0,1,10], [2,0,5]]

Output:
2

Explanation:
Person #0 gave person #1 $10.
Person #2 gave person #0 $5.

Two transactions are needed. One way to settle the debt is person #1 pays person #0 and #2 $5 each.
Example 2:

Input:
[[0,1,10], [1,0,1], [1,2,5], [2,0,5]]

Output:
1

Explanation:
Person #0 gave person #1 $10.
Person #1 gave person #0 $1.
Person #1 gave person #2 $5.
Person #2 gave person #0 $5.

Therefore, person #1 only need to give person #0 $4, and all debt is settled.

class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        
        // get list of transactions
        // if exist right inverse one, cancel out
        // 
        unordered_map<int, int> m;
        
        for (auto t : transactions) {
            m[t[0]] -= t[2];
            m[t[1]] += t[2];
        }
        
        vector<int> balance;
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it->second)
                balance.push_back(it->second);
        }
        
        int count = 0, cur = 0;
          
        return dfs(balance, cur, count);
    }
    
    int dfs(vector<int>& balance, int cur, int count) {
        
        while (cur < balance.size() && balance[cur] == 0) cur++;
        
        int result = INT_MAX;
        for (int i = cur+1; i < balance.size(); i++) {
            if (balance[cur] * balance[i] < 0) {
                balance[i] += balance[cur];
                result = min(result, dfs(balance, cur+1, count+1));
                balance[i] -= balance[cur];
            }
        }
        return result == INT_MAX ? count : result;
    }
};