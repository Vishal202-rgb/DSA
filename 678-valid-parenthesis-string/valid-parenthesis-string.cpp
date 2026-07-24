class Solution {
public:
    bool checkValidString(string s) {
    int n = s.size();
    vector<int>prev(n+1,0);

    prev[0] = 1;
    for (int i = n - 1; i >= 0; i--) {
        vector<int>curr(n+1,0);
        for (int j = 0; j <= n; j++) {
            if (s[i] == '*') {
                if (j + 1 <= n)
                    curr[j] |= prev[j + 1];
                curr[j] |= prev[j];
                if (j > 0)
                    curr[j] |= prev[j - 1];
            }
            else if (s[i] == '(') {
                if (j + 1 <= n)
                    curr[j] |= prev[j + 1];
            }
            else {
                if (j > 0)
                    curr[j] |= prev[j - 1];
            }
        }
        prev=curr;
    }
    return prev[0];
    }
};