class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        int n = lcp.size();
        vector<char> ret(n, ' ');
        
        char c = 'a';
        for (int i = 0; i < n; ++i) {
            if (ret[i] != ' ') continue;
                
            if (c > 'z') return "";
            ret[i] = c;
            c += 1;
            
            for (int k = i + 1; k < n; ++k) {
                if (lcp[i][k] != 0) ret[k] = ret[i];
            }
        }
        
        for (int k = 0; k < n; ++k) {
            for (int i = n - 1 - k; i >= 0; --i) {
                int a = 0;
                if (ret[i] == ret[i + k]) {
                    a = 1;
                    if (i + k + 1 < n) a += lcp[i + 1][i + k + 1]; 
                }
                if (lcp[i][i + k] != a or lcp[i + k][i] != a) return "";
            } 
        }
        
        string s;
        for (auto &c: ret) s += c;
        return s;
    }
};