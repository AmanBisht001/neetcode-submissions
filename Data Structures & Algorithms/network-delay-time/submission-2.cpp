class Solution {
public:
    int solve(int node,int n,vector<vector<pair<int,int>>>&adj){
        vector<int>dis(n+1,INT_MAX);
       
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
        q.push({0,node});
      
        dis[node]=0;
        while(!q.empty()){
            auto it=q.top();
            q.pop();
            int node=it.second;
            int nodeTime=it.first;
            if(nodeTime>dis[node]){
                continue;
            }
            for(auto neigh:adj[node]){
                int NeighNode=neigh.first;
                int temptime=neigh.second;
                if(temptime+nodeTime<dis[NeighNode]){
                    dis[NeighNode]=temptime+nodeTime;
                    q.push({dis[NeighNode],NeighNode});
                   
                }
            }
        }
        int maxi=INT_MIN;
        for(int i=1;i<=n;i++){
            if(dis[i]==INT_MAX){
                return -1;
            }
            maxi=max(maxi,dis[i]);
        }
        return maxi;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        int totalTime=solve(k,n,adj);
        return totalTime;
    }
};
