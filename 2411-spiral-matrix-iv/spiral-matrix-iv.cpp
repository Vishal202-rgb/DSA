/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
         vector<vector<int>>matrix(m,vector<int>(n,-1));

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
        while(top <= down && left <= right){
            if(dir==0){
                //left to right
                //const:row(top)
                for(int i=left;head != NULL && i<=right;i++){
                    // ans.push_back(mat[top][i]);
                    matrix[top][i]=head->val;
                    head=head->next;
                }
                top++;
            }
            if(dir==1){
                //top to down
                //const:col(right)
                for(int i=top;head != NULL && i<=down;i++){
                    // ans.push_back(mat[i][right]);
                    matrix[i][right]=head->val;
                    head=head->next;
                }
                right--;
            }
            if(dir==2){
                //right to left
                //const:row(down)
                for(int i=right;head != NULL && i>=left;i--){
                    // ans.push_back(mat[down][i]);
                    matrix[down][i]=head->val;
                    head=head->next;
                }
                down--;
            }
            if(dir==3){
                //down to top
                //const:col(left)
                for(int i=down;head != NULL && i>=top;i--){
                    // ans.push_back(mat[i][left]);
                    matrix[i][left]=head->val;
                    head=head->next;
                }
                left++;
            }
            dir = (dir+1)%4;
        }
        return matrix;
    }
};