class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        vector<int>inDegree(n,0);
        vector<bool>Suspicious(n,false);
        
        for(auto &edge:invocations){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }
        queue<int>que;
        que.push(k);
        Suspicious[k]=true;

        while(!que.empty()){
            int temp=que.front();
            que.pop();
            
            for(int &ngbr:adj[temp]){
                inDegree[ngbr]--;
                if(!Suspicious[ngbr]){
                    que.push(ngbr);
                    Suspicious[ngbr]=true;
                }
            }
        }
        vector<int>res;
        bool cannotRemove=false;
        for(int i=0;i<n;i++){
            if(Suspicious[i] && inDegree[i]>0){
                cannotRemove=true;
                break;
            }
            if(!Suspicious[i])
                res.push_back(i);
        }
        if(cannotRemove){
            vector<int>vec(n);
            for(int i=0;i<n;i++){
                vec[i]=i;
            }
            return vec;
        }
        return res;
    }
};