class Solution(object):

    def solve(self,n:int,dp:list)->int:
        if n==1 or n==2:
            return n

        dp[n] = self.solve(n-1, dp) + self.solve(n-2, dp)

        return dp[n] 
        


    
    def climbStairs(self, n:int)->int:

        dp=[-1]*(n+1)
        if n >= 1:
            dp[1] = 1

        if n >= 2:
            dp[2] = 2

        return self.solve(n,dp)
        
       