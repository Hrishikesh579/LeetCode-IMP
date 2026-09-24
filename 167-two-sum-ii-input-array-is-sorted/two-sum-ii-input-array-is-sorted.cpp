class Solution {
public:
    int BinarySearch(vector<int>& nums, int left, int right, int target){
        if(left > right) return -1;
        int mid = left + (right - left)/2;

        if(nums[mid] == target) return mid;

        if(nums[mid] > target) return BinarySearch(nums, left, mid - 1, target);

        return BinarySearch(nums, mid + 1, right, target);
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int n = numbers.size();
        for(int i = 0; i < n; i++){
            int temp = BinarySearch(numbers, i+1, n-1, target - numbers[i]);
            if(temp != -1){
                res.push_back(i+1);
                res.push_back(temp + 1);
            }
        }
        return res;
    }
};