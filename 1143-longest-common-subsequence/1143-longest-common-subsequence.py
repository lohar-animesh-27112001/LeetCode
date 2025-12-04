def lcs(text1, text2, mem, m, n):
    for i in range(1, m+1):
        for j in range(1, n+1):
            if(text1[i-1] == text2[j-1]):
                mem[i][j] = 1 + mem[i-1][j-1]
            else:
                mem[i][j] = max(mem[i-1][j], mem[i][j-1])
    return mem[m][n]
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        m = len(text1)
        n = len(text2)
        mem = [[0] * (n + 1) for _ in range(m + 1)]
        return lcs(text1, text2, mem, m, n)