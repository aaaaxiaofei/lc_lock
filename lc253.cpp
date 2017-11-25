253. Meeting Rooms II

Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return 2.

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) 
             {return a.start < b.start;});
        vector<int> room;
        
        for (auto it : intervals) {
            int st = it.start, ed = it.end;
            
            int i = 0; 
            
            while (i < room.size()) {
                if (st >= room[i]) {
                    room[i] = ed;
                    break;
                }
                i++;
            }
            
            if (i == room.size())
                room.push_back(ed);
        }
        
        return room.size();
    }
};