class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int checker = 0, i = 0;
        bool isSame = false;
        while(i < n){
            if(nums[i] <= checker) i++;
            else{
                if(nums[i] != checker + 1) return checker + 1;
                checker++;
            }
        }
        return checker + 1;
    }
};