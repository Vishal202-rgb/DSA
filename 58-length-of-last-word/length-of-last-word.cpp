class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        int i=n-1;

        while(i>=0 && s[i]==' ') i--;
        int l=0;
        while(i>=0 && s[i]!=' '){
            i--;
            l++;
        }
        return l;
    }
};