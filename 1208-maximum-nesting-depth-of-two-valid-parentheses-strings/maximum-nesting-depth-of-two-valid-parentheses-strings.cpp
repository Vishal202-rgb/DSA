class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.size();
        vector<int>ans(n);
        int depth=0;

        for(int i=0;i<n;i++){
            if(seq[i]=='('){
                depth++;
                ans[i]=(depth%2==0) ? 0 : 1;
            }else{
                ans[i]=(depth%2==0) ? 0 : 1;
                depth--;
            }
        }
        return ans;
    }
};