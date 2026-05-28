class Solution {
public:
    struct TrieNode {
        int idx;
        int child[26];

        TrieNode() {
            idx = 0;
            for(int i = 0; i < 26; i++) {
                child[i] = -1;
            }
        }
    };
    vector<TrieNode> trie;
    void insert(string &word, int index,
        vector<string>& wordsContainer) {

        int node = 0;
        int len = word.size();
        for(int i = len - 1; i >= 0; i--) {
            int c = word[i] - 'a';

            if(trie[node].child[c] == -1) {
                trie[node].child[c] = trie.size();
                trie.push_back(TrieNode());
                trie.back().idx = index;
            }
            node = trie[node].child[c];
            // keep shortest string index
            if(wordsContainer[trie[node].idx].size() > len) {
                trie[node].idx = index;
            }
        }
    }
    int search(string &word) {
        int node = 0;
        int ans = trie[0].idx;

        for(int i = word.size() - 1; i >= 0; i--) {
            int c = word[i] - 'a';

            if(trie[node].child[c] == -1) {
                return ans;
            }
            node = trie[node].child[c];
            ans = trie[node].idx;
        }
        return ans;
    }
    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        int n = wordsContainer.size();
        trie.push_back(TrieNode());

        // root stores shortest word index
        int rootIdx = 0;
        for(int i = 1; i < n; i++) {

            if(wordsContainer[i].size() <
               wordsContainer[rootIdx].size()) {

                rootIdx = i;
            }
        }
        trie[0].idx = rootIdx;

        // build trie
        for(int i = 0; i < n; i++) {
            insert(wordsContainer[i], i, wordsContainer);
        }
        vector<int> ans;

        for(string &q : wordsQuery) {
            ans.push_back(search(q));
        }
        return ans;
    }
};