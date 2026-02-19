
class Solution {
public:
    int countBinarySubstrings(string s) {
        int cur = 1, pre = 0, res = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) cur++;
            else {
                res += min(cur, pre);
                pre = cur;
                cur = 1;
            }
        }
        return res + min(cur, pre);
    }
    /* sliding window 
    int countBinarySubstrings(string s) {
        int i = 0, j = 1, n = s.size();
        int zero = 0, one = 0;
        int ans = 0;
        for( ;j < n; j++){
            if( s[j] == '0' ) zero++;
            else one++; 
            while( i < j && zero != one ){

            }
            if(zero == one) ans++;
        }
        return 0;
    }
    */
};