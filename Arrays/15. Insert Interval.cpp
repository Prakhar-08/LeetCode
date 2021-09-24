// Leetcode - 57
// You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
// Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
// Return intervals after the insertion.

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        
        vector<int> temp = intervals[0];
        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i][0] <= temp[1]) {
                temp[1] = max(intervals[i][1], temp[1]);
            } else  {
                res.push_back(temp);
                temp = intervals[i];
            }
        }
        
        res.push_back(temp);
        return res;
    }
};