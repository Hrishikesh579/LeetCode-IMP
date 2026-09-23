// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         unordered_set<int> um(nums.begin(), nums.end());
//         int n = nums.size();
//         int count = 1, maxCount = 0;
//         for (int i = 0; i < n; i++) {
//             count = 1;
//             if(um.find(nums[i] - 1) == um.end()){
//                 int j = nums[i] + 1;
//                 while(um.find(j) != um.end()) {
//                     count++;
//                     j++;
//                 }
//             }
//             // um[nums[i]]++;
//             maxCount = max(maxCount, count);
//         }
//         return maxCount;
//     }
// };
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;

        for (int num : numSet) {
            // Check if this is the start of a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;

                // Count consecutive numbers going forward
                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum++;
                    currentStreak++;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};