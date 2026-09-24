class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //-----------------------------------------------------Dummy Element Approach--------------------------------------------------------
        // int n = intervals.size();
        // int i = n-1;
        // intervals.push_back({100001, 100001});
        // while(i >= 0 && intervals[i][0] > newInterval[0]) {
        //     intervals[i+1] = intervals[i];
        //     i--;
        // }
        // vector<vector<int>> res;
        // intervals[i+1] = newInterval;
        // int lowerLimit = intervals[0][0], upperLimit = intervals[0][1];
        // for(i = 0; i < n+1; i++){
        //     if(intervals[i][0] <= upperLimit){
        //         upperLimit = max(upperLimit, intervals[i][1]);
        //     } else{
        //         res.push_back({lowerLimit, upperLimit});
        //         lowerLimit = intervals[i][0];
        //         upperLimit = intervals[i][1];  
        //     }
        // }
        // res.push_back({lowerLimit, upperLimit});
        // return res;
        
        // On The Fly approach
        vector<vector<int>> res;
        int i = 0, n = intervals.size();

        // 1. Add all intervals that come completely before the new interval
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);
            i++;
        }

        // 2. Merge all overlapping intervals with newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval); // Add the merged new interval

        // 3. Add all remaining intervals that come after
        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};