class Solution {
public:
    void explore(vector<vector<int>>& graph, int n, int cur, vector<bool>& visited, vector<int>& island) {
        if(visited[cur]) return;
        
        visited[cur]=true;
        
        island.push_back(cur);
        for(auto neighbour:graph[cur]) {
            explore(graph, n, neighbour, visited, island);
        }
        
        return;
    }
    
    vector<vector<int>> findIslands(vector<vector<int>>& graph, int n) {
        vector<vector<int>> islands;
        
        vector<bool> visited(n, false);
        
        for(int i=0; i<n ;i++) {
            if(!visited[i]) {
                vector<int> island;
                explore(graph, n, i, visited, island);
                islands.push_back(island);
            }
        }
        
        return islands;
    }
    
    vector<vector<int>> makeGraph(vector<vector<int>>& allowedSwaps, int n) {
        vector<vector<int>> graph(n);
        
        for(auto swap:allowedSwaps) {
            graph[swap[0]].push_back(swap[1]);
            graph[swap[1]].push_back(swap[0]);
        }
        
        return graph;
    }
    
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        vector<vector<int>> graph=makeGraph(allowedSwaps, source.size());

        vector<vector<int>> islands=findIslands(graph, source.size());
        
        int count=0;
        for(auto island:islands) {
            map<int, int> uncommon;
            for(int i=0; i<island.size(); i++) {
                uncommon[source[island[i]]]++;
                uncommon[target[island[i]]]--;
            }
            
            for(auto pair:uncommon) {
                count+=abs(pair.second);
            }
        }
        
        return count/2;
    }
};