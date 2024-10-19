class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reversed = 0;
        for (int i = 0; i < 32; i++) {
            reversed <<= 1;
            reversed |= (n & 1);  // Add the least significant bit of n to reversed
            n >>= 1;              // Shift n right to process the next bit
        }
        return reversed;
    }
};
