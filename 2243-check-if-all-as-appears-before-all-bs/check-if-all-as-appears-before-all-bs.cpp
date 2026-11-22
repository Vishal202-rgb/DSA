class Solution {
public:
    bool checkString(string s) {
        return is_sorted(begin(s),end(s));
    }
};