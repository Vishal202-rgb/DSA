class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int>freq(26, 0);

        for (char &ch:s)
            freq[ch -'a']++;
        string l= "",m= "";

        for (int i=0;i<26;i++) {
            l.append(freq[i]/2,char('a'+i));
            if(freq[i]%2)
                m=char('a'+i);
        }
        string r=l;
        reverse(begin(r),end(r));

        return (l+m+r);
    }
};