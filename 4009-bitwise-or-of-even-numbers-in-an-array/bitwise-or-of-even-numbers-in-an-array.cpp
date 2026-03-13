class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int n=nums.size();
        int ans = 0;
        for (int i = 1; i <= 6; i++) {
            for (int num : nums) {
                if ((~num & 1) & ((num >> i) & 1)) {
                    ans |= (1 << i);
                    break;
                }
            }
        }
        return ans;
    }
};