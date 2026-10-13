class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        transform(nums.begin(), nums.end(), nums.begin(), [](int x){
            return x*x;
        });
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long res = 0;
        int addStart = n/2;
        for(int i = 0; i < addStart; i++){
            res -= nums[i];
        }
        for(int i = addStart; i < n; i++){
            res += nums[i];
        }
        return res;
    }
};