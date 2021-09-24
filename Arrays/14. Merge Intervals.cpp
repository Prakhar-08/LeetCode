// Leetcode - 56
//Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        
        sort(intervals.begin(), intervals.end());
        vector<int> temp = intervals[0];
        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i][0] <= temp[1]) {
                temp[1] = max(intervals[i][1], temp[1]);
            }
            else {
                res.push_back(temp);
                temp = intervals[i];
            }
        }
        
        res.push_back(temp);
        return res;
    }
};