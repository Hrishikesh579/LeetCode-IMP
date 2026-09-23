class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxSum = INT_MIN;
        int n = nums.size();
        int i = 0, j = 0;
        while(j < n){
            if(sum < 0){
                i = j;
                sum = nums[j++];
            } else{
                sum += nums[j];
                j++;
            }
            maxSum = max(sum, maxSum);
        }
        return maxSum;
    }
};