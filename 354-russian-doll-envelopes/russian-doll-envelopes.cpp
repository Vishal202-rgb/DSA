class Solution {
public:
    static bool comp(vector<int>first,vector<int>second){
        if(first[0]==second[0])
            return first[1]>second[1];
        return first[0]<second[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        sort(begin(envelopes),end(envelopes),comp);
        vector<int>temp(1,envelopes[0][1]);

        for(int i=1;i<n;i++){
            int idx=lower_bound(begin(temp),end(temp),envelopes[i][1])-begin(temp);

            if(idx==temp.size()){
                temp.push_back(envelopes[i][1]);
            }else{
                temp[idx]=envelopes[i][1];
            }
        }
        return temp.size();
    }
};