class Solution {
public:
    static bool comp(string w1,string w2){
        return w1.size()<w2.size();
    }
    bool isPredecessor(string w1,string w2){
        if(w1.size()+1!=w2.size()) return 0;
        int i=w1.size()-1,j=w2.size()-1;

        while(i>=0 && j>=0){
            if(w1[i]==w2[j]){
                i--;
                j--;
            }else
                j--;
        }
        return i<0;
    }
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(begin(words),end(words),comp);
        vector<int>LCS(n,1);
        int maxLen=1;

        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(isPredecessor(words[j],words[i]))
                LCS[i]=max(LCS[i],1+LCS[j]);
            }
            maxLen=max(maxLen,LCS[i]);
        }
        return maxLen;
    }
};