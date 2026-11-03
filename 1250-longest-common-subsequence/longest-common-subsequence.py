class Solution:

    def solve(self,i:int,j:int,text1: str, text2: str , dp)->int:
        if i==len(text1) or j== len(text2):
            return 0
        if dp[i][j]!=-1:
            return dp[i][j]
        pick=0
        if text1[i]==text2[j]:
            pick = 1+ self.solve(i+1,j+1,text1,text2,dp)
        npick1 = self.solve(i+1,j,text1,text2,dp)
        npick2 = self.solve(i,j+1,text1,text2,dp)
        dp[i][j] =max(pick , npick1,npick2)
        return dp[i][j]
        



    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n=len(text1)
        m = len(text2)
        dp = [[-1]*m for i in range(n)]
        return self.solve(0,0,text1 , text2,dp)
        