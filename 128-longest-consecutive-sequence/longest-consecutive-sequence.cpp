    class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            unordered_set<int> um(nums.begin(), nums.end());
            int n = nums.size();
            int count = 1, maxCount = 0;
            for (auto& i : um) {
                count = 1;
                if(um.find(i-1) == um.end()){
                    int j = i + 1;
                    while(um.find(j) != um.end()) {
                        count++;
                        j++;
                    }
                }
                // um[nums[i]]++;
                maxCount = max(maxCount, count);
            }
            return maxCount;
        }
    };