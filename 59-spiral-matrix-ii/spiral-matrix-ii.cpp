class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n==0) return {};
         int m=n;
         vector<vector<int>>matrix(m,vector<int>(n));

        int top = 0;
        int down = m - 1;
        int left = 0;
        int right = n - 1;

        int dir=0;
        /*
        0->left to right
        1->top to down
        2->right to left
        3->down to top
        */
        int cnt=1;
        while(top <= down && left <= right){
            if(dir==0){
                //left to right
                //const:row(top)
                for(int i=left;i<=right;i++){
                    // ans.push_back(mat[top][i]);
                    matrix[top][i]=cnt++;
                }
                top++;
            }
            if(dir==1){
                //top to down
                //const:col(right)
                for(int i=top;i<=down;i++){
                    // ans.push_back(mat[i][right]);
                    matrix[i][right]=cnt++;
                }
                right--;
            }
            if(dir==2){
                //right to left
                //const:row(down)
                for(int i=right;i>=left;i--){
                    // ans.push_back(mat[down][i]);
                    matrix[down][i]=cnt++;
                }
                down--;
            }
            if(dir==3){
                //down to top
                //const:col(left)
                for(int i=down;i>=top;i--){
                    // ans.push_back(mat[i][left]);
                    matrix[i][left]=cnt++;
                }
                left++;
            }
            dir = (dir+1)%4;
        }
        return matrix;
    }
};