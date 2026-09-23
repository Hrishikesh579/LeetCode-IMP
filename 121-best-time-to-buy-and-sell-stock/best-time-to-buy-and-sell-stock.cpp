class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int diff = 0, maxDiff = INT_MIN, minVal = INT_MAX;
        int j = 0;
        int n = prices.size();
        while(j < n){
            minVal = min(minVal, prices[j]);
            diff = prices[j] - minVal;
            maxDiff = max(maxDiff, diff);
            j++;
        }
        return maxDiff;
    }
};