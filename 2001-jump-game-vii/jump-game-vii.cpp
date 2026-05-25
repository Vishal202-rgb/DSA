class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n=s.length();
        vector<int>st(n,0);

        st[0]=1;
        int cnt=0;
        for(int j=1;j<=n-1;j++){
            if(j-minJump>=0) cnt+=st[j-minJump];
            if(j-maxJump-1>=0) cnt-=st[j-maxJump-1];
            if(cnt>0 && s[j]=='0') st[j]=1;
        }
        return st[n-1]>0;
    }
};