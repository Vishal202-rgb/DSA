class Solution {
public:
    int minimumPushes(string word) {
        int ans=0;
        //using map
        unordered_map<int,int>mp;

        int st=2;
        for(char &ch:word){
            if(st>9){
                st=2;
            }
            mp[st]++;
            ans+=mp[st];
            st++;
        }
        return ans;
    }
};