class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mn=*min_element(begin(nums),end(nums));
        int mx=*max_element(begin(nums),end(nums));

        return __gcd(mn,mx);
    }
};