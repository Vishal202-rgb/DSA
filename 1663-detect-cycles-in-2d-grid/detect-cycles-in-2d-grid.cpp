class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    bool cycleDetectDFS(int r, int c, int prev_r, int prev_c, 
                    vector<vector<char>>& grid, vector<vector<bool>>& visited ) {

        if(visited[r][c]) {
            return true;
        }
        visited[r][c] = true;
        //explore neighbours
        for(auto &dir : directions) {
            int new_r = r + dir[0]; 
            int new_c = c + dir[1];

            if(new_r >= 0 && new_r < m && new_c >= 0 && new_c < n
                && grid[new_r][new_c] == grid[r][c]) {
                    if(new_r == prev_r && new_c == prev_c)
                        continue;
                    
                    if(cycleDetectDFS(new_r, new_c, r, c, grid, visited)) {
                        return true;
                    }
                }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && cycleDetectDFS(i, j, i, j, grid, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};
