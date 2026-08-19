class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_set<int>>mp;

        for(auto &reservedSeat:reservedSeats){
            int row=reservedSeat[0];
            int seat=reservedSeat[1];

            mp[row].insert(seat);
        }
        int res=(n-mp.size())*2;
        for(auto &[row,bookedseat]:mp){

            auto availableseat=[&](int seat){
                return bookedseat.find(seat)==bookedseat.end();
            };
            bool groupA=availableseat(2)&&availableseat(3)&&availableseat(4)&&availableseat(5);
            bool groupB=availableseat(4)&&availableseat(5)&&availableseat(6)&&availableseat(7);
            bool groupC=availableseat(6)&&availableseat(7)&&availableseat(8)&&availableseat(9);

            if(groupA && groupC){
                res+=2;
            }else if(groupA || groupB || groupC){
                res+=1;
            }
        }
        return res;
    }
};