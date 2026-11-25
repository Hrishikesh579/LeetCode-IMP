class Solution:
    def generate(self, numRows: int) -> list[list[int]]:
        if(numRows == 1):
            return [[1]]
        elif numRows == 2:
            return [[1], [1,1]]
        else:
            res = [[1], [1,1]]
            for i in range(2, numRows):
                l = [1]
                for j in range(1, i):
                    l.append(res[i-1][j-1] + res[i-1][j])
                l.append(1)
                res.append(l)
            return res
        