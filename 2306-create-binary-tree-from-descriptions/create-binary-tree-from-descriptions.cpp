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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>nodes;
        unordered_set<int>children;

        for(auto &d:descriptions){
            int p=d[0];
            int c=d[1];
            int l=d[2];

            if(!nodes.count(p)) nodes[p]=new TreeNode(p);
            if(!nodes.count(c)) nodes[c]=new TreeNode(c);
            if(l) nodes[p]->left=nodes[c];
            else
                nodes[p]->right=nodes[c];

                children.insert(c);
        }
        for(auto &d:descriptions){
            int p=d[0];
            if(!children.count(p)) return nodes[p];
        }
        return nullptr;
    }
};