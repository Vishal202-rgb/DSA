class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>ans(128,-1);
        int maxLength=0,i=0;

        for(int j=0;j<s.size();j++){
            if(ans[s[j]]>=i) i=ans[s[j]]+1;
            ans[s[j]]=j;
            maxLength=max(maxLength,j-i+1);
        }
        return maxLength;
    }
};