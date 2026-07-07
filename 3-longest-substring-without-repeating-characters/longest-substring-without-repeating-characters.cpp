class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        vector<int>res(128,-1);
        int maxlength=0,i=0;

        for(int j=0;j<n;j++){
            if(res[s[j]]>=i) i=res[s[j]]+1;
            res[s[j]]=j;
            maxlength=max(maxlength,j-i+1);
        }
        return maxlength;
    }
};