class Solution {
public:
    static constexpr int MOD=1e9+7;
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        vector<int> dp(m, 1);

        for (int i = 2; i <= n; i++) {
            reverse(begin(dp),end(dp));
            int sum = 0;
            for (auto& d : dp)
                sum = (sum + exchange(d, sum)) % MOD;
        }

        return ((accumulate(begin(dp),end(dp), 0LL) % MOD) << 1) % MOD;
    }
};