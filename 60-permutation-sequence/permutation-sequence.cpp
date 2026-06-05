class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>ans;
        int fact = 1;
        
        for (int i = 1; i <= n; i++) {
            ans.push_back(i);
            if (i < n) fact *= i;
        }
        k--;
        string result = "";
        
        for (int i = 0; i < n; i++) {
            int idx = k / fact;
            result += to_string(ans[idx]);
            ans.erase(begin(ans) + idx);
            
            if (ans.size() > 0) {
                k %= fact;
                fact /= ans.size();
            }
        } 
        return result;
    }
};