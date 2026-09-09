class Solution {
public:

    void solve(int node,vector<bool>&vis,vector<vector<int>>&adj){
        queue<int>q;
        q.push(node);
        vis[node]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int neigh:adj[node]){
                if(!vis[neigh]){
                    vis[neigh]=true;
                    q.push(neigh);
                }
                
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        vector<bool>vis(n,false);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                solve(i,vis,adj);
                ans++;
            }
        }
        return ans;
    }
};
