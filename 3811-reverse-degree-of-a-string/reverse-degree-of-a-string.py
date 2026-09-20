class Solution:
    def reverseDegree(self, s: str) -> int:
        sum = 0
        for i in range(len(s)):
            sum += (122-ord(s[i])+1)*(i+1)
        return sum