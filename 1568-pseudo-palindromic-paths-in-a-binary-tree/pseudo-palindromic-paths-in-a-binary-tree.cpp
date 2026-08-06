/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans=0;
    void solve(TreeNode* root,vector<int>&cnt){
        if(!root) return;
        cnt[root->val]++;
        if(root->left==NULL && root->right==NULL){
            int odd=0;
            for(int i=1;i<=9;i++){
                if(cnt[i]%2!=0)
                    odd++;
            }
            if(odd<=1) ans+=1;
        }
        solve(root->left,cnt);
        solve(root->right,cnt);
        cnt[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int>cnt(10,0);
        solve(root,cnt);
        return ans;
    }
};