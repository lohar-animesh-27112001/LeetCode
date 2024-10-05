class Solution {
public:
    int climbStairs(int n) {
        long long prev1 = 1, prev2 = 2;
        if(n == 1) {
            return 1;
        } else if(n == 2) {
            return 2;
        }
        long long sum = 2;
        for(int i=3; i<=n; i++) {
            sum = prev1 + prev2;
            int temp = prev2;
            prev2 = sum;
            prev1 = temp;
        }
        return sum;
    }

    int climbStairs2(int n) {
        if(n == 1) {
            return 1;
        } else if(n == 2) {
            return 2;
        }
        return climbStairs(n-1) + climbStairs(n-2);
    }
};