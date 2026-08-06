class Solution {
public:
    bool scramble(string s1, string s2,unordered_map<string,bool>&dp){
        if(s1==s2) return true;
        int n=s1.size();

        string k=s1+s2;
        if(dp.find(k)!=dp.end())
            return dp[k];

        vector<int>freq(26,0);

        for(int i=0;i<n;i++){
            freq[s1[i]-'a']++;
            freq[s2[i]-'a']--;
        }
        for(int cnt:freq){
            if(cnt) return 0;
        }
        for(int i=1;i<n;i++){
            bool noSwap=scramble(s1.substr(0,i),s2.substr(0,i),dp)&&scramble(s1.substr(i),s2.substr(i),dp);
            if(noSwap) return dp[k]=true;

            bool swap=scramble(s1.substr(0,i),s2.substr(n-i),dp)&&scramble(s1.substr(i),s2.substr(0,n-i),dp);
            if(swap) return dp[k]=true;
        }
        return dp[k]=false;
    }
    bool isScramble(string s1, string s2) {
        unordered_map<string,bool>dp;
        return scramble(s1,s2,dp);
    }
};