class Solution {
public:
    unordered_set<string>st;
    int n;
    int t[301];
    bool solve(int idx,string &s){
        if(idx>=n) return true;
        if(st.find(s.substr(idx,n-idx))!=st.end()){
            return true;
        }

        if(t[idx]!=-1) return t[idx];
        for(int l=1;l<=n;l++){
            string temp=s.substr(idx,l);
            if(st.find(temp)!=st.end() && solve(idx+l,s)){
                return t[idx]= true;
            }
        }
        return t[idx]= false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.length();

        memset(t,-1,sizeof(t));
        for(string &w:wordDict){
            st.insert(w);
        }
        return solve(0,s);
    }
};