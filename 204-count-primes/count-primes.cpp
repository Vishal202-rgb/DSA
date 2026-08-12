class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        vector<bool>visited(n,0);
        int cnt=0;

        for(int i=2;i<n;i++){
            if(!visited[i]){
                cnt++;
            for(long long j=1LL*i*i;j<n;j+=i){
                visited[j]=1;
             }
            }
        }
        return cnt;
    }
};