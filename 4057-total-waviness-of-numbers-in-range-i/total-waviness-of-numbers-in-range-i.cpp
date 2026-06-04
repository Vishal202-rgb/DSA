class Solution {
public:
    int waviness(int i){
        string s=to_string(i);
        int cnt=0;

        for(int j=1;j<s.size()-1;j++){
            if((s[j]>s[j-1] && s[j]>s[j+1]) || (s[j]<s[j-1] && s[j]<s[j+1])) cnt++;
        }
        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        long long res=0;
        for(int i=num1;i<=num2;i++){
            res+=waviness(i);
        }
        return res;
    }
};