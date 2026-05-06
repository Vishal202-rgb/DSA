class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        vector<vector<char>> ans(n, vector<char>(m, '.'));
        
        for (int r = 0; r < m; r++) {
            int i = n - 1;
            for (int c = n - 1; c >= 0; c--) {
                if (box[r][c] == '#') {
                    ans[i][m - r - 1] = '#';
                    i--;
                }
                else if (box[r][c] == '*') {
                    ans[c][m - r - 1] = '*';
                    i = c - 1;
                }
            }
        } 
        return ans;
    }
};