class Solution:
    def plusOne(self, digits: list[int]) -> list[int]:
        carry = False
        n = len(digits)
        if(digits[n-1] == 9):
            digits[n-1] = 0
            carry = True
        else:
            digits[n-1] += 1
            carry = False
        for i in range(1, len(digits)):
            if(carry):
                if((digits[n-i-1]+1)//10 == 1):
                    carry = True
                    digits[n-i-1] += 1
                    digits[n-i-1] %= 10
                else:
                    carry = False
                    digits[n-i-1] += 1
                    digits[n-i-1] %= 10
                    break
        if(carry):
            l = []
            l.append(1)
            for i in digits:
                l.append(i)
            return l
        return digits
            