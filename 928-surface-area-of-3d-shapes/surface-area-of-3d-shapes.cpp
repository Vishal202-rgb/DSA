class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    // 1. Add area for the current tower: (4 * height) + top + bottom
                    ans += (grid[i][j] * 4) + 2;

                    // 2. Subtract overlap with the tower to the LEFT (i, j-1)
                    if (j > 0) {
                        ans -= min(grid[i][j], grid[i][j - 1]) * 2;
                    }

                    // 3. Subtract overlap with the tower ABOVE (i-1, j)
                    if (i > 0) {
                        ans -= min(grid[i][j], grid[i - 1][j]) * 2;
                    }
                }
            }
        }
        return ans;
    }
};