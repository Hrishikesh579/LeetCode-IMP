class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        int count = 0, currentSum = 0;
        um[0]++;
        for(int& i : nums){
            currentSum += i;
            if(um.find(currentSum - k) != um.end()) count += um[currentSum - k];
            um[currentSum]++;
        }
        return count;
    }
};