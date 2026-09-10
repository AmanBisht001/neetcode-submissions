class Solution {
public:
    int solve(int src,int dst,int n,int k,vector<vector<pair<int,int>>>&adj){
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        q.push({0,{0,src}});
        vector<vector<int>>dist(k+2,vector<int>(n,INT_MAX));
        dist[0][src]=0;
        int mini=INT_MAX;
        while(!q.empty()){
            auto it=q.top();
            q.pop();
            int timeTaken=it.first;
            int stops=it.second.first;
            int node=it.second.second;
            if(node==dst){
                return timeTaken;
            }
            if (stops == k + 1)
                continue;
            for(auto neigh:adj[node]){
                int neighNode=neigh.first;
                int neighTime=neigh.second;
                if(dist[stops+1][neighNode]>timeTaken+neighTime){
                    dist[stops+1][neighNode]=timeTaken+neighTime;
                    
                    q.push({dist[stops+1][neighNode],{stops+1,neighNode}});
                }
            }
        }
        return -1;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        return solve(src,dst,n,k,adj);
    }
};
