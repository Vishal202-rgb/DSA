class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        vector<int>num=nums;

        int totalXor=0;
        bool hasNonZero=false;

        for (int &x:num) {
            totalXor ^= x;
            if (x != 0) hasNonZero = true;
        }
        if (totalXor == 0) { 
            if (!hasNonZero) return 0;
            return num.size() == 1 ? 0 : num.size() - 1;
        } else {
            return num.size();
        }
    }
};
