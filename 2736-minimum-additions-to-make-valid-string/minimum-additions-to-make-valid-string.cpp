class Solution {
public:
    int addMinimum(string word) {
        int n=word.size();
        int i=0,ans=0;

        while(i<n){
            int cnt=0;
            if(i<n && word[i]=='a'){
                cnt++;
                i++;
            }
            if(i<n && word[i]=='b'){
                cnt++;
                i++;
            }
            if(i<n && word[i]=='c'){
                cnt++;
                i++;
            }
            ans+=3-cnt;
        }
        return ans;
    }
};