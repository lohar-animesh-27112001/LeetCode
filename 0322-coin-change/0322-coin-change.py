class Solution:
    ans = -1
    def recCoinChange(self, coins, amount, curr, num_of_coins):
        if(curr > amount or num_of_coins == self.ans):
            return
        if(curr == amount):
            if(self.ans != -1):
                self.ans = min(self.ans, num_of_coins)
            else:
                self.ans = num_of_coins
            return
        for coin in coins:
            self.recCoinChange(coins, amount, curr+coin, num_of_coins+1)
    mem = []
    def dpCoinChange(self, coins, amount, curr):
        if(curr > amount):
            return float('inf')
        if(curr == amount):
            return 0
        if(self.mem[curr] != -1):
            return self.mem[curr]
        number_of_coins = float('inf')
        for coin in coins:
            number_of_coins = min(number_of_coins, 1+self.dpCoinChange(coins, amount, curr+coin))
        self.mem[curr] = number_of_coins
        return number_of_coins
    def coinChange(self, coins: List[int], amount: int) -> int:
        if(amount == 0):
            return 0
        if(len(coins) == 0):
            return -1
        # self.recCoinChange(coins, amount, 0, 0)
        arr = []
        for i in range (0, amount):
            arr.append(-1)
        self.mem = arr
        result = self.dpCoinChange(coins, amount, 0)
        return -1 if result == float('inf') else result