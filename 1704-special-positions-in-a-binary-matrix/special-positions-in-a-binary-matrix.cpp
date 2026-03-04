class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans= 0;
        int m = mat.size();
        int n = mat[0].size();
        
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (mat[row][col] == 0) {
                    continue;
                }
                
                bool spc = true;
                //Check Row
                for (int r = 0; r < m; r++) {
                    if (r != row && mat[r][col] == 1) {
                        spc = false;
                        break;
                    }
                }
                
                //Check Col
                for (int c = 0; c < n; c++) {
                    if (c != col && mat[row][c] == 1) {
                        spc = false;
                        break;
                    }
                }  
                if (spc==true) {
                    ans++;
                }
            }
        } 
        return ans;
    }
};