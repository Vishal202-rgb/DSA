class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
          vector<vector<int>> pp = grid;

        int m = pp.size();
        int n = pp[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));

        // Helper lambdas for score and cost
        auto getScore = [&](int val) {
            if (val == 1) return 1;
            if (val == 2) return 2;
            return 0;
        };

        auto getCost = [&](int val) {
            if (val == 1 || val == 2) return 1;
            return 0;
        };

        dp[0][0][0] = 0; // Starting point

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int c = 0; c <= k; c++) {
                    if (dp[i][j][c] == -1) continue;

                    // Try moving right
                    if (j + 1 < n) {
                        int nc = c + getCost(pp[i][j + 1]);
                        if (nc <= k)
                            dp[i][j + 1][nc] = max(dp[i][j + 1][nc],
                                                   dp[i][j][c] + getScore(pp[i][j + 1]));
                    }

                    // Try moving down
                    if (i + 1 < m) {
                        int nc = c + getCost(pp[i + 1][j]);
                        if (nc <= k)
                            dp[i + 1][j][nc] = max(dp[i + 1][j][nc],
                                                   dp[i][j][c] + getScore(pp[i + 1][j]));
                    }
                }
            }
        }

        int ans = -1;
        for (int c = 0; c <= k; c++) {
            ans = max(ans, dp[m - 1][n - 1][c]);
        }

        return ans;
    }
};