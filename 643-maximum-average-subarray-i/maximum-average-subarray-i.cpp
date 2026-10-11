class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0;
        while(j <= k-1){
            sum += nums[j];
            j++;
        }
        double maxAvg = static_cast<double>(sum)/k;
        for(int j = k; j < n; j++, i++){
            sum -= nums[i];
            sum += nums[j];
            maxAvg = max(maxAvg, static_cast<double>(sum)/k);
        }
        return maxAvg;
    }
};