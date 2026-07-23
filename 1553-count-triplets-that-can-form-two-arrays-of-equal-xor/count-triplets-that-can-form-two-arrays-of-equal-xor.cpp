class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int>prefixXor(begin(arr),end(arr));
    //starting me cummulative xor '0' rahega issliye hum isko pahle hi store kr liye hai taki badd me edge case miss na ho
        prefixXor.insert(prefixXor.begin(),0);
        int n=prefixXor.size();
    //why we loop starting with 1-->because 0 can store in prefixXor
        for(int i=1;i<n;i++){
            prefixXor[i]^=prefixXor[i-1];
        }
        int triplet=0;
        for(int i=0;i<n;i++){
            for(int k=i+1;k<n;k++){
                //k-i-1 issliye kyuki hum ek sure me bdha diye the 
                if(prefixXor[k]==prefixXor[i]) triplet+=k-i-1;
            }
        }
        return triplet;
    }
};