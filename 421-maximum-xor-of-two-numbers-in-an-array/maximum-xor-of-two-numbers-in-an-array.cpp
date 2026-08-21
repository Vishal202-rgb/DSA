class TrieNode {
public:
    TrieNode* child[2];

    TrieNode() {
        child[0] = child[1] = nullptr;
    }
};
class Solution {
public:
    void insert(TrieNode* root, int num) {
        TrieNode* curr = root;

        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (!curr->child[bit])
                curr->child[bit] = new TrieNode();

            curr = curr->child[bit];
        }
    }
    int getMaxXor(TrieNode* root, int num) {
        TrieNode* curr = root;
        int ans = 0;

        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opposite = 1 - bit;

            if (curr->child[opposite]) {
                ans |= (1 << i);
                curr = curr->child[opposite];
            }
            else {
                curr = curr->child[bit];
            }
        }

        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        for (int num : nums)
            insert(root, num);

        int ans = 0;

        for (int num : nums)
            ans = max(ans, getMaxXor(root, num));

        return ans;
    }
};