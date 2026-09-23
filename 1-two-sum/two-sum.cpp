class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> um;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++){
            if(um.find(target - nums[i]) != um.end()) {
                res.push_back(um[target - nums[i]]);
                res.push_back(i);
            }
            um[nums[i]] = i;
        }
        return res;
    }
};