class Solution {
public:
    int maximumSwap(int num) {
        string str = to_string(num);
        int n = str.length();

        // To store the last occurrence of each digit (0-9)
        vector<int> last(10, -1);
        for (int i = 0; i < n; i++) {
            last[str[i] - '0'] = i;
        }

        // Try to find the first pair of digits to swap
        for (int i = 0; i < n; i++) {
            // Check digits greater than str[i] from 9 down to str[i] + 1
            for (int d = 9; d > str[i] - '0'; d--) {
                if (last[d] > i) {
                    swap(str[i], str[last[d]]);
                    return stoi(str);  // Return the result after the first swap
                }
            }
        }

        // If no swap was made, return the original number
        return num;
    }
};
