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
    TreeNode* inOrdSucc(TreeNode* root) {
        while (root->left) {
            root = root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;

        if (key > root->val) root->right = deleteNode(root->right,key);
        else if (key < root->val) root->left = deleteNode(root->left,key);
        else { // key == root->val
            if (!root->left && !root->right) { // 0 Children
                return NULL;
            } else if (!root->left) { // 1 Right Child
                return root->right;
            } else if (!root->right) { // 1 Left Child
                return root->left;
            } else {
                TreeNode* IS = inOrdSucc(root->right);
                root->val = IS->val;
                root->right = deleteNode(root->right,IS->val);
            }
        }
        return root;
    }
};