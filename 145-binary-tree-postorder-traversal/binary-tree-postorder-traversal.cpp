class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;        
    }
private:
    void postorder(TreeNode* node, std::vector<int>& ans) {
        if (node == nullptr) {
            return;
        }
        postorder(node->left, ans);
        postorder(node->right, ans);
       ans.push_back(node->val);
    }    
};