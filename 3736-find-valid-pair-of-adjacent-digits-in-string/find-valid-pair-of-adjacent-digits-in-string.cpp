class Solution {
public:
    string findValidPair(string s) {
        if (s.length() < 2) return "";
        vector<int> freq(10, 0);  
        for (char ch : s) {
            freq[ch - '0']++;
        }
        for (int i = 0; i < s.length() - 1; i++) {
            int first = s[i] - '0';
            int second = s[i + 1] - '0';
            
            if (first != second) {
                if (freq[first] == first && freq[second] == second) {
                    return string(1, s[i]) + string(1, s[i + 1]);
                }
            }
        }
        return "";
    }
};