class Solution {
public:
    string addBinary(string a, string b) {
        string sum = "";
        int carry = 0;
        int i = a.size() - 1;
        int j = b.length() - 1;
        while(i >= 0 || j >= 0 || carry!=0) {
            if(i >= 0) {
                carry += a[i--] - '0';
            }
            if(j >= 0) {
                carry += b[j--] - '0';
            }
            sum += carry % 2 + '0';
            carry /= 2;
        }
        reverse(sum.begin(), sum.end());
        return sum;
    }
    string addBinary2(string a, string b) {
        long long sum1 = 0, sum2 = 0;
        for(int i = a.size(); i > 0; i--) {
            sum1 = sum1 + ((a[i-1] - '0') * pow(2, a.size() - i));
        }
        for(int i = b.size(); i > 0; i--) {
            sum2 = sum2 + ((b[i-1] - '0') * pow(2, b.size() - i));
        }
        long long sum_int = sum1 + sum2;
        if (sum_int == 0) return "0";
        string sum = "";
        while(sum_int > 0) {
            int remainder = sum_int % 2;
            sum_int = sum_int / 2;
            sum = to_string(remainder) + sum;
        }

        return sum;
    }
};
