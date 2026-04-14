class Solution {
public:
    string removeTrailingZeros(string num) {
        int n=num.size()-1;
        for(int i=0;i<n;i++){
            while(num[n]=='0'){
                num.pop_back();
                n--;
            } 
        }
        return num;
    }
};