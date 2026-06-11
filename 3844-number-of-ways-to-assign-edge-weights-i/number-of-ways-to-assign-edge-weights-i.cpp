class Solution {
public:
    int M=1e9+7;
    typedef long long ll;
    ll pow(ll base,ll expo){
        if(expo==0) return 1;
        ll half=pow(base,expo/2);

        ll res=(half*half)%M;

        if(expo%2==1){
            res=(res*base)%M;
        }
        return res;
    }
    int getMaxDepth(unordered_map<int,vector<int>>&adj,int node,int parent){
        int depth=0;

        for(int &ngbr:adj[node]){
            if(ngbr==parent) continue;

            depth=max(depth,getMaxDepth(adj,ngbr,node)+1);
        }
        return depth;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;

        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int d=getMaxDepth(adj,1,-1);

        return pow(2,d-1);
    }
};