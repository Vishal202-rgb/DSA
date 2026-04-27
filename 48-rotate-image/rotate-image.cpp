class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=m;

        for(int i=0;i<m;i++){
            for(int j=i;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<m;i++){
            reverse(begin(matrix[i]),end(matrix[i])); 
        }
    }
};