class Solution {
public:
    int t[501][501];
    int canSolve(int i,int j,string &a,string &b){
        if(i==a.size()||j==b.size()) return 0;
        if(t[i][j]!=-1) return t[i][j];
        if(a[i]==b[j]){
            return t[i][j]=1+canSolve(i+1,j+1,a,b);
        }
        return t[i][j]=max(canSolve(i+1,j,a,b),canSolve(i,j+1,a,b));
    }
    int minDistance(string word1, string word2) {
        memset(t,-1,sizeof(t));
        int lcs=canSolve(0,0,word1,word2);
        return word1.size()+word2.size()-2*lcs;
    }
};