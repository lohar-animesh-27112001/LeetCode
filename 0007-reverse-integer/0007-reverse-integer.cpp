class Solution {
private:
    int* numCount(int *num) {
        int* count = new int(0);
        int* temp = num;
        while (*temp / 10 != 0) {
            ++*count;
            *temp /= 10;
        }
        return count;
    }

    int* power(int *cDigit) {
        int* result = new int(1);
        int* temp = cDigit;
        while (*temp > 0) {
            *result *= 10;
            --*temp;
        }
        return result;
    }

    void reverseHelper(int *x) {
        int* tempNum = new int(*x);
        int* result = new int(0);
        int* countDigit = numCount(tempNum);
        int* mul = power(countDigit);
        while (*x / 10 != 0) {
            long l = (long)*result + ((long)(*mul)) * (long)(*x % 10);
            if(l > (long)INT_MAX || l < (long)INT_MIN) {
                *x = 0;
                return;
            }
            *result += (*mul) * (*x % 10);
            *x /= 10;
            *mul /= 10;
        }
        *result += (*mul) * (*x);
        *x = *result;
        delete tempNum;
        delete result;
        delete countDigit;
        delete mul;
    }

public:
    int reverse(int x) {
        int* rev = new int(x);
        reverseHelper(rev);
        int result = *rev;
        delete rev;
        return result;
    }
};