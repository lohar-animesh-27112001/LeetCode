#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int kMax = 1000;
        vector<int> primes = sieveEratosthenes(kMax);
        int prevNum = 0;
        for (int& num : nums) {
            auto it = lower_bound(primes.begin(), primes.end(), num - prevNum);
            if (it != primes.begin()) {
                --it;
                num -= *it;
            }
            if (num <= prevNum) return false;
            prevNum = num;
        }
        return true;
    }

    vector<int> sieveEratosthenes(int n) {
        vector<int> primes;
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i < n; i++)
            if (isPrime[i])
                for (int j = i * i; j < n; j += i)
                    isPrime[j] = false;
        for (int i = 2; i < n; ++i)
            if (isPrime[i])
                primes.push_back(i);
        return primes;
    }
};
