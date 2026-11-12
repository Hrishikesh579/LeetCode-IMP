class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        bool series = false;
        int n = nums.size();
        if(n == 1) return 1;
        int maxim = 1;
        int i = 0, j = 1;
        while(j < n){
            if(nums[j-1] < nums[j]){
                if(!series) i = j-1;
                series = true;
            } else{
                if(series) maxim = max(j-i, maxim);
                series = false;
            }
            j++;
        }
        if(series) maxim = max(j-i, maxim);
        i = 0, j = 1;
        series = false;
        while(j < n){
            if(nums[j-1] > nums[j]){
                if(!series) i = j-1;
                series = true;
            } else{
                if(series) maxim = max(j-i, maxim);
                series = false;
            }
            j++;
        }
        if(series) maxim = max(j-i, maxim);
        return maxim;
    }
};