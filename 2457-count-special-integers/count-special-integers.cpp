class Solution {
public:
    int t[10][2][2][1024];
    int solve(int idx,bool tight,bool st,int mask,string &num){
        if(idx==num.size()){
            if(!st) return 0;
            return 1;
        }
        if(t[idx][tight][st][mask]!=-1){
            return t[idx][tight][st][mask];
        }
        int limit=tight ? num[idx]-'0':9;
        int ans=0;

        for(int digit=0;digit<=limit;digit++){
            bool newTight=tight && (digit==limit);
            if(!st && digit==0){
                ans+=solve(idx+1,newTight,false,mask,num);
            }else{
                if(mask &(1<<digit)) continue;
                ans+=solve(idx+1,newTight,true,mask|(1<<digit),num);
            }
        }
        return t[idx][tight][st][mask]=ans;
    }
    int countSpecialNumbers(int n) {
        string num=to_string(n);
        memset(t,-1,sizeof(t));
        return solve(0,true,false,0,num);
    }
};