class Solution:
    ans = 0
    def recClimbStairs(self, n, curr):
        if(n == curr):
            self.ans = self.ans+1
            return
        if(n < curr):
            return
        self.recClimbStairs(n, curr+1)
        self.recClimbStairs(n, curr+2)
    mem = []
    def dpclimbStairs(self, n, curr):
        if(curr > n):
            return 0
        if(n == curr):
            return 1
        if(self.mem[curr] != -1):
            return self.mem[curr]
        total = self.dpclimbStairs(n, curr+1) + self.dpclimbStairs(n, curr+2)
        self.mem[curr] = total
        return self.mem[curr]
    def climbStairs(self, n: int) -> int:
        # self.recClimbStairs(n, 0)
        arr = []
        for i in range (0, n+1):
            arr.append(-1)
        self.mem = arr
        # self.mem = [-1] * (n+1)
        print(self.mem)
        return self.dpclimbStairs(n, 0)