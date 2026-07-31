class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int r1=startPos[0],c1=startPos[1];
        int r2=homePos[0],c2=homePos[1];
        int ans=0;

        //move in row
        if(r2>=r1){
            //moving down
            for(int r=r1+1;r<=r2;r++){
                ans+=rowCosts[r];
            }
        }else{
            //moving up
            for(int r=r1-1;r>=r2;r--){
                ans+=rowCosts[r];
            }
        }

        //move in col
        if(c2>=c1){
            //moving right
            for(int c=c1+1;c<=c2;c++){
                ans+=colCosts[c];
            }
        }else{
            //moving left
            for(int c=c1-1;c>=c2;c--){
                ans+=colCosts[c];
            }
        }
        return ans;
    }
};