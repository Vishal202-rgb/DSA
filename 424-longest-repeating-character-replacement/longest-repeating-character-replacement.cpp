class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0, r = 0, maxlen = 0;
        int maxf = 0;
        vector<int>cnt(26, 0);

        while (r < n) {
            cnt[s[r] - 'A']++;
            maxf = max(maxf, cnt[s[r] - 'A']);

            if ((r - l + 1) - maxf > k) {
                cnt[s[l] - 'A']--;
                l++;
            }
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};