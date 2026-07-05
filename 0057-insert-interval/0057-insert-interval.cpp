class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        intervals.push_back(newInterval);   // add newInterval to the list
        sort(intervals.begin(), intervals.end());   // sort by start value

        int start1 = intervals[0][0];
        int end1 = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            int start2 = intervals[i][0];
            int end2 = intervals[i][1];

            if (end1 >= start2) {
                // overlapping, merge
                end1 = max(end1, end2);
                continue;
            }

            // no overlap, push current merged interval and move on
            res.push_back({start1, end1});
            start1 = start2;
            end1 = end2;
        }

        res.push_back({start1, end1}); // push the last merged interval
        return res;
    }
};