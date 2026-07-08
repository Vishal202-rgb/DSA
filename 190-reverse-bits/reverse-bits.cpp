class Solution {
public:
    int reverseBits(int n) {
        if (n == 0) return 0;
    
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            ans <<= 1;   //Left shift ans by 1.
            ans = (ans | (n & 1)); //This line copies the last bit of n into ans.
            
            n >>= 1;
        }
        return ans;
    }
};
