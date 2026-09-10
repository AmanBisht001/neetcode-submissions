class Solution {
public:
    class DSU{
        public:
        vector<int>parent;
        vector<int>rank;
        DSU(int n){
            parent.resize(n+1);
            rank.resize(n+1,0);
            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }

        int findUPar(int node){
            if(node==parent[node]){
                return node;
            }
            return parent[node]=findUPar(parent[node]);
        }
        bool unionSet(int u,int v){
            int uPar_u=findUPar(u);
            int uPar_v=findUPar(v);
            if(uPar_u==uPar_v){
                return true;
            }
            if(rank[uPar_u]>rank[uPar_v]){
                parent[uPar_v]=uPar_u;
            }
            else if(rank[uPar_u<rank[uPar_v]]){
                parent[uPar_u]=uPar_v;
            }
            else{
                parent[uPar_u]=uPar_v;
                rank[uPar_v]++;
            }
            return false;
        }
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU dsu(n);
        for(auto it:edges){
            if(dsu.unionSet(it[0],it[1])){
                return {it[0],it[1]};
            }
        }
        return {};
    }
};
