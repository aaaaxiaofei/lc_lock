356. Line Reflection

Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points.

Example 1:
Given points = [[1,1],[-1,1]], return true.

Example 2:
Given points = [[1,1],[-1,-1]], return false.

Follow up:
Could you do better than O(n2)?

Credits:
Special thanks to @memoryless for adding this problem and creating all test cases.

class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        
        if (points.size() == 0) return true;
        
        
        set<pair<int, int>> s(points.begin(), points.end());
        vector<pair<int, int>> v(s.begin(), s.end());
        
        sort(v.begin(), v.end(), [](pair<int,int>& a, pair<int, int>& b)
             {return (a.first < b.first) || (a.first == b.first && a.second < b.second);});
        
        int n = v.size();
        
        sort(v.begin(), v.begin()+n/2, [](pair<int,int>& a, pair<int, int>& b)
             {return (a.first < b.first) || (a.first == b.first && a.second > b.second);});
        
       // sort(points.begin(), points.end(), 
             // [](pair<int,int>& a, pair<int, int>& b) {return a.first <= b.first;} );
        
        points = v;
        int i = 0, j = n-1;
        int sum = points[0].first + points.back().first;
        
        while (i <= j) {
            
            if (points[i].first*2 == sum) return points[j].first*2 == sum;
            printf("%d, %d, %d, %d, %d \n", points[i].second, points[j].second, points[i].first, points[j].first, sum);
            if (points[i].second != points[j].second || points[i].first + points[j].first != sum)           
                return false;
            
            i++; j--;    
        }
        
        return true;
    }
};