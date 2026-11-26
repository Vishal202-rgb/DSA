class Solution {
public:
    bool canAliceWin(int n) {
        int r=10;
        bool aliceTurn=true;
        while(n>=r){
            n-=r;
            r--;
            aliceTurn=!aliceTurn;
        }
        return !aliceTurn;
    }
};