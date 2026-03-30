class Solution {
public:
    string largestEven(string s) {
        int n = s.size();
        int idx = n - 1;

        while (idx >= 0) {
            if (s[idx] == '1')
                s.pop_back();
            else
                break;
            idx--;
        }
        return s;
    }
};