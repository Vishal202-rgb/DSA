class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();

        if(t.length() > n)
            return "";

        unordered_map<char,int> mp;

        for(char &ch : t) {
            mp[ch]++;
        }

        int cnt = t.length();
        int i = 0, j = 0;

        int windowsize = INT_MAX;
        int start_i = 0;

        while(j < n) {
            char ch = s[j];

            if(mp[ch] > 0)
                cnt--;

            mp[ch]--;

            while(cnt == 0) {
                int currWs = j - i + 1;

                if(currWs < windowsize) {
                    windowsize = currWs;
                    start_i = i;
                }
                mp[s[i]]++;

                if(mp[s[i]] > 0)
                    cnt++;
                i++;
            }
            j++;
        }
        return windowsize == INT_MAX ? "" : s.substr(start_i, windowsize);
    }
};