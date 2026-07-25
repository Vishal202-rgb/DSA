class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>>directions={{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>>res;
        res.push_back({rStart,cStart});

        int step=0; // east and west move karega to step ka count bdhate rhenge
        int dir=0; //starting with the east direction

        while(res.size()<rows*cols){
            if(dir==0 || dir==2){
                //0-->east side move karega and 2-->west side move karega
                step++;
            }
            for(int cnt=0;cnt<step;cnt++){
                rStart+=directions[dir][0];
                cStart+=directions[dir][1];

                if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols){
                    res.push_back({rStart,cStart});
                }
            }
            dir=(dir+1)%4;
        }
        return res; 
    }
};
//Time complexity->O(max(row,col)^2)