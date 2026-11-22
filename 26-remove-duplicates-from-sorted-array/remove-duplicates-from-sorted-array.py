class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        if(len(nums) == 1):
            return len(nums)
        i = 1
        j = 1
        while j in range(len(nums)):
            if(nums[i-1] != nums[j]):
                nums[i] = nums[j]
                i += 1
            j += 1
        k = i
        # nums = nums[:i]
        return k

        