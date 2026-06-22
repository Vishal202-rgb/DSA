class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>count(26,0);

        for(auto &ch:text){
            int l=ch-'a';
            count[l]++;
        }
        string required="balloon";
        int ans=1e6+7;

        for(auto &ch:required){
            if(ch=='l'||ch=='o'){
                ans=min(ans,count[ch-'a']/2);
            }else{
                ans=min(ans,count[ch-'a']);
            }
        }
        return ans;
    }
};