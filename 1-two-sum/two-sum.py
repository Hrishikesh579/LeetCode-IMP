class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        res = []
        um = {}
        for i in range(len(nums)):
            if (target-nums[i]) in um:
                res.append(um[target-nums[i]])
                res.append(i)
                return res
            um[nums[i]] = i
        return res