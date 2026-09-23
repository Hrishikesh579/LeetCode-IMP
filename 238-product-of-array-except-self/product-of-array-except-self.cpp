class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        int temp = 1;
        for(int i = 1; i < n; i++){
            res[i] = temp*nums[i-1];
            temp *= nums[i-1];
        }
        temp = 1;
        for(int i = n-2; i >= 0; i--){
            res[i] *= temp*nums[i+1];
            temp *= nums[i+1];
        }
        return res;
    }
};