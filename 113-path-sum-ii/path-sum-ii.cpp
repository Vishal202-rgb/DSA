class Solution {
public:
    vector<vector<int>> res;
    void solve(TreeNode* root, int sum, vector<int>& temp, int targetSum) {
        if (!root) return;

        sum += root->val;
        temp.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (sum == targetSum)
                res.push_back(temp);

            temp.pop_back();
            return;
        }
        solve(root->left, sum, temp, targetSum);
        solve(root->right, sum, temp, targetSum);

        temp.pop_back(); 
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        solve(root, 0, temp, targetSum);
        return res;
    }
};