class Solution {
public:
    bool judgeCircle(string moves) {
        int xAxis=0;
        int yAxis=0;

        for (char &ch:moves){
            if(ch=='U') yAxis++;
            else if(ch=='D') yAxis--;
            else if(ch=='L') xAxis--;
            else xAxis++;
        }
        return (xAxis==0 && yAxis==0);
    }
};