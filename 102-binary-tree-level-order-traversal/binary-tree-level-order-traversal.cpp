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
    void solve(TreeNode* root,vector<vector<int>>&res,int count){
        if(root==NULL) return;
        if(res.size()==count) res.push_back({});
        res[count].push_back(root->val);

        solve(root->left,res,count+1);
        solve(root->right,res,count+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        solve(root,res,0);
        return res;

    }
};