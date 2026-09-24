class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // vector<vector<int>> res;
        // intervals.push_back(newInterval);
        // sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b){
        //     return a[0] < b[0];
        // });
        // int n = intervals.size();
        // int lowerLimit = intervals[0][0], upperLimit = intervals[0][1];
        // for(int i = 0; i < n; i++){
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
        int n = intervals.size();
        int i = n-1;
        intervals.push_back({100000, 100000});
        while(i >= 0 && intervals[i][0] > newInterval[0]) {
            intervals[i+1] = intervals[i];
            i--;
        }
        vector<vector<int>> res;
        intervals[i+1] = newInterval;
        int lowerLimit = intervals[0][0], upperLimit = intervals[0][1];
        for(i = 0; i < n+1; i++){
            if(intervals[i][0] <= upperLimit){
                upperLimit = max(upperLimit, intervals[i][1]);
            } else{
                res.push_back({lowerLimit, upperLimit});
                lowerLimit = intervals[i][0];
                upperLimit = intervals[i][1];  
            }
        }
        res.push_back({lowerLimit, upperLimit});
        return res;
    }
};