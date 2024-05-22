class Solution(object):
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        self.s = s
        self.n = len(s)
        self.dp = [[0] * self.n for _ in range(self.n)]
        print(self.dp)
        self.ans = []
        
        for i in range(self.n):
            self.dp[i][i] = 1
        
        for i in range(self.n-1):
            self.dp[i][i+1] = int(s[i]==s[i+1])
        
        for length  in range(3, self.n+1):
            for i in range(self.n-length +1):
                j = i+length -1
                if s[i]==s[j]:
                    self.dp[i][j] = self.dp[i+1][j-1]
                else:
                    self.dp[i][j] = 0
        
        ans_ = []
        self.dfs(0, ans_)
        
        return self.ans
    
    def dfs(self, i, ans_):
        if i==self.n:
            self.ans.append(ans_[:])
            return
        
        for j in range(i, self.n):
            if self.dp[i][j]:
                ans_.append(self.s[i:j+1])
                self.dfs(j+1, ans_)
                ans_.pop()
                
# dp + dfs.
# Reference from 【每日一题】131. Palindrome Partitioning, 5/9/2021, https://youtu.be/OqYHNDmG13g.