class Solution {
private:
    void hWeight(int* n, int* ans) {
        while(*n != 0 && *n != 1) {
            if(*n % 2 == 1) ++*ans;
            *n = *n / 2;
        }
    }
public:
    int hammingWeight(int n) {
        int *d = &n;
        int a = 0;
        int *ans = &a;
        hWeight(d, ans);
        if(*d == 1) return ++*ans;
        return *ans;
    }
};
