class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int>cntS(26,0),cntT(26,0);

        for(auto &ch:s)
            cntS[ch-'a']++;

        for(auto &ch:target)
            cntT[ch-'a']++;

        int ans=1e6;
        for(int i=0;i<26;i++){
            if(cntT[i]>0)
                ans=min(ans,cntS[i]/cntT[i]);
        }
        return ans;
    }
};