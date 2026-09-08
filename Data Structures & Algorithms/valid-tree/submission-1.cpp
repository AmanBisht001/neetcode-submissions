class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        queue<pair<int,int>>q;
        unordered_set<int>st;
        q.push({0,-1});
        st.insert(0);
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int node=it.first;
            int parent=it.second;
            for(int neigh:adj[node]){
                if(neigh==parent){
                    continue;
                }
                if(st.count(neigh)){
                    return false;
                }
                st.insert(neigh);
                q.push({neigh,node});
            }
        }
        return st.size()==n;
    }
};
