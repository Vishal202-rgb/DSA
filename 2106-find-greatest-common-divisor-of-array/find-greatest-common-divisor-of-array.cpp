class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minimum = nums[0];
        int maximum = nums[0];

    for (int x : nums) {
        minimum = min(minimum, x);
        maximum = max(maximum, x);
    }
    return __gcd(minimum,maximum);
    }
};