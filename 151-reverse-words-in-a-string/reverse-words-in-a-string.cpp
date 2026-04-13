class Solution {
public:
    string reverseWords(string s) {
        int n=s.length();
        string ans="";
        reverse(begin(s),end(s));

        for(int i=0;i<n;i++){
            string word="";
            while(i<n && s[i]!=' '){
                word+=s[i];
                i++;
            }
            reverse(begin(word),end(word));
            if(word.length()>0) ans+=" "+word;
        }
        return ans.substr(1);
    }
};