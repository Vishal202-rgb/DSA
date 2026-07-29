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
     int findHtLeft(TreeNode* node){
        int lh=0;
        while(node){
            lh++;
            node=node->left;
        }
        return lh;
    }
    int findHtRight(TreeNode* node){
         int rh=0;
        while(node){
            rh++;
            node=node->right;
        }
        return rh;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;

        int lh=findHtLeft(root);
        int rh=findHtRight(root);

        if(lh==rh) return (pow(2,lh)-1);
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};