class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs[0].size();
        string ans="";

        for(int i=0;i<n;i++){
            for(auto &it:strs){
                if(it[i]!=strs[0][i]) return ans;
            }
            ans+=strs[0][i];
        }
        return ans;
    }
};