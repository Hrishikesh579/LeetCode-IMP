class Solution:
    def longestCommonPrefix(self, strs: list[str]) -> str:
        res = strs[0]
        for i in strs:
            if(i == res):
                continue
            elif (i == ""):
                return ""
            else:
                uq = False
                sz = min(len(res), len(i))
                for j in range(min(len(i), len(res))):
                    if(i[j] != res[j]):
                        uq = True
                        break
                    else:
                        uq = False
                if not uq:
                    if(len(res) > len(i)):
                        res = i
                else:
                    res = res[:j]
        return res
        