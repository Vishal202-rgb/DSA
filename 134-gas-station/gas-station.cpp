class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgas=0,totalcost=0;

        for(int val : gas){
            totalgas+=val;
        }
        for(int val : cost){
            totalcost+=val;
        }
        if(totalgas < totalcost){
            return -1;
        }
        //unique solution
        int start=0,currentGas=0;

        for(int i=0;i<gas.size();i++){
            currentGas+=(gas[i]-cost[i]);
             
             if(currentGas<0){
                start=i+1;
                currentGas=0;
             }
        }
        return start;
    }
};