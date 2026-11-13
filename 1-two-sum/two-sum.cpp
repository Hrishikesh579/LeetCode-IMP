class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        vector<int> res;
        int i = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(um.find(target - nums[i]) != um.end()){
                res.push_back(um[target-nums[i]]);
                res.push_back(i);
                return res;
            }
            um[nums[i]] = i;
        }
        return res;
    }
};