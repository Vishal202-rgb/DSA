class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int ans=0;
        int count=0;

        for(int i=0;i<moves.length();i++){
            if(moves[i]=='L'){
                ans++;
            }else if(moves[i]=='R'){
                ans--;
            }else{
                count++;
            }
        }
        return max(abs(ans+count),abs(ans-count));
    }
};