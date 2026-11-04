class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> low, high;
        long long sumLow = 0, sumHigh = 0;
        auto rebalance = [&]() {
            while (high.size() > low.size() + 1) {
                int val = *high.begin();
                high.erase(high.begin());

                sumHigh -= val;
                low.insert(val);
                sumLow += val;
            }
            while (low.size() > high.size()) {
                int val = *low.rbegin();
                low.erase(prev(low.end()));

                sumLow -= val;
                high.insert(val);
                sumHigh += val;
            }
        };
        auto insert = [&](int val) {
            if (high.empty() || val >= *high.begin()) {
                high.insert(val);
                sumHigh += val;
            } 
            else {
                low.insert(val);
                sumLow += val;
            }

            rebalance();
        };
        auto erase = [&](int val) {
            auto it = low.find(val);

            if (it != low.end()) {
                low.erase(it);
                sumLow -= val;
            } 
            else {
                it = high.find(val);
                high.erase(it);
                sumHigh -= val;
            }

            rebalance();
        };
        auto getCost = [&]() -> long long {
            long long median = *high.begin();

            long long leftCost =
                median * (long long)low.size() - sumLow;

            long long rightCost =
                sumHigh - median * (long long)high.size();

            return leftCost + rightCost;
        };
        vector<long long> moves(n - x + 1);

        for (int i = 0; i < x; i++) {
            insert(nums[i]);
        }

        moves[0] = getCost();

        for (int i = x; i < n; i++) {
            erase(nums[i - x]);
            insert(nums[i]);

            moves[i - x + 1] = getCost();
        }
        const long long INF = LLONG_MAX / 4;

        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];
                if (i >= x && dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(
                        dp[i][j],
                        moves[i - x] + dp[i - x][j - 1]
                    );
                }
            }
        }
        return dp[n][k];
    }
};