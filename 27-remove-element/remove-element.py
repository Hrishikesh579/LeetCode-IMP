class Solution:
    def removeElement(self, nums: list[int], val: int) -> int:
        if not nums:
            return 0
        
        slow = 0
        slowShift = True
        for fast in range(0, len(nums)):
            if(nums[fast] != val):
                nums[slow] = nums[fast]
                slow += 1
            fast += 1
        return slow


        