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
    vector<TreeNode*>solve(int n){
        if(n%2==0) return {};
        if(n==1){
            TreeNode* root=new TreeNode(0);
            return {root};
        }
        vector<TreeNode*>ans;
        for(int i=1;i<n;i+=2){
            vector<TreeNode*>leftBST=solve(i);
            vector<TreeNode*>rightBST=solve(n-i-1);

            for(auto &l:leftBST){
                for(auto &r:rightBST){
                    TreeNode* root=new TreeNode(0);
                    root->left=l;
                    root->right=r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return solve(n);
    }
};