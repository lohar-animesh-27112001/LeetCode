class Solution {
private:
    int* count(int* x) {
        int* c = new int(0);
        int num = *x;
        while(num != 0) {
            num /= 10;
            ++*c;
        }
        return c;
    }

    int* getDivider(int* index) {
        int* d = new int(1);
        int* i = index;
        while(*i > 1) {
            *d *= 10;
            --*i;
        }
        return d;
    }

    int* getNum(int* num, int* index) {
        int* val = new int(*num);
        int* idx = new int(*index);
        int* d = getDivider(idx);
        *val /= *d;
        *val %= 10;
        delete d;
        delete idx;
        return val;
    }

    bool check(int* x) {
        int* c = count(x);
        int* i = new int(1);
        int* j = new int(*c);
        while(*j > *i) {
            int* left = getNum(x, j);
            int* right = getNum(x, i);
            cout << "left:" << *left << ", right:" << *right
            << ", c:" << *c << "[END]";
            if(*left != *right) {
                delete c;
                delete i;
                delete j;
                delete left;
                delete right;
                return false;
            }
            delete left;
            delete right;
            ++*i;
            --*j;
        }
        delete c;
        delete i;
        delete j;
        return true;
    }

public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        return check(&x);
    }
};
