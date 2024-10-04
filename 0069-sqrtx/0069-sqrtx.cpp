class Solution {
public:
    int mySqrt(int x) {
        long long num = 0;
        while(num * num <= x) {
            num = num + 1;
        }
        return num - 1;
    }
};