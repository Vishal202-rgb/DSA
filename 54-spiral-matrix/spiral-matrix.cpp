class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        int dir=0;

        int top = 0;
        int down = m - 1;
        int left = 0;
        int right = n - 1;
        /*
        0->left to right
        1->top to bottom
        2->right to left
        3->bottom to top
        */
        vector<int>ans;

        while(top <= down && left <= right){
            if(dir==0){
                //left to right
                //const:row(top)
                for(int i=left;i<=right;i++){
                    ans.push_back(mat[top][i]);
                }
                top++;
            }
            if(dir==1){
                //top to bottom
                //const:col(right)
                for(int i=top;i<=down;i++){
                    ans.push_back(mat[i][right]);
                }
                right--;
            }
            if(dir==2){
                //right to left
                //const:row(down)
                for(int i=right;i>=left;i--){
                    ans.push_back(mat[down][i]);
                }
                down--;
            }
            if(dir==3){
                //bottom to top
                //const:col(left)
                for(int i=down;i>=top;i--){
                    ans.push_back(mat[i][left]);
                }
                left++;
            }
            dir = (dir+1)%4;
        }
        return ans;
    }
};