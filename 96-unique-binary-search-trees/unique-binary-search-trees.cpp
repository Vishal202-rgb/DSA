class Solution {
public:
    int numTrees(int n) {
        vector<int>Tree(n + 1, 1);
        for (int nodes = 2; nodes <= n; nodes++) {
            int total = 0;
            for (int root = 1; root <= nodes; root++) {
                total +=Tree[root - 1] * Tree[nodes - root];
            }
            Tree[nodes] = total;
        }
        return Tree[n];        
    }
};