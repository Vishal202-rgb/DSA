class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int>vec;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                vec.push_back(grid[i][j]);
            }
        }
        int L=vec.size();
        sort(begin(vec),end(vec));
        int tar=vec[L/2];
        int ans=0;

        for(int &num:vec){
            if(num%x!=tar%x){
                return -1;
            }
            ans+=abs(tar-num)/x;
        }
        return ans;
    }
};