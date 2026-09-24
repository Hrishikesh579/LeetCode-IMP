class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [&](vector<int> a, vector<int> b) { return a[0] < b[0]; });
        vector<vector<int>> res;
        int n = intervals.size();
        if (n == 0)
            return res;
        int lowerHand = intervals[0][0], upperHand = intervals[0][1];
        for (int i = 0; i < n; i++) {
            // if(i != n-1){
            if (intervals[i][0] <= upperHand) {
                upperHand = max(upperHand, intervals[i][1]);
            } else {
                res.push_back({lowerHand, upperHand});
                lowerHand = intervals[i][0];
                upperHand = intervals[i][1];
                // }
            }
        }
        // if (res.empty()) {
            res.push_back({lowerHand, upperHand});
        // }
        return res;
    }
};