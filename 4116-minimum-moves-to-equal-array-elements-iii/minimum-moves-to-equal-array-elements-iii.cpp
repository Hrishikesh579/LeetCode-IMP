class Solution {
public:
    int minMoves(vector<int>& nums) {
        // int avg = 0;
        // for(int& i : nums){
        //     avg += i;
        // }
        // avg /= nums.size();
        // int count1 = 0, count2 = 0;
        // for(int& i : nums){
        //     count1 += abs(avg - i);
        //     count2 += abs(avg - i + 1);
        // }
        // if(count1 < count2) return count1;
        // else return count2;
        int maxim = 0;
        for(int& i : nums){
            maxim = max(i, maxim);
        }
        int count = 0;
        for(int& i : nums){
            count += abs(maxim - i);
        }
        return count;
    }
};