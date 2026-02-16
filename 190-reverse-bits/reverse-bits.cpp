class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++) {
            int bit = n & 1;       //  least significant bit
            ans = (ans << 1) | bit; // Append the bit to the result
            n = n >> 1;           // Right-shift n to process the next bit
        }
        return ans;
    }
};