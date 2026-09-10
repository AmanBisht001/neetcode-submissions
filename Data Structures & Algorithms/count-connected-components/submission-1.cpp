class Solution {
public:
    class DSU{
        public:
        vector<int>par;
        vector<int>rank;
        
        DSU(int n){
            par.resize(n+1);
            rank.resize(n+1,0);
            for(int i=0;i<=n;i++){
                par[i]=i;
            }
        }
        int findUPar(int node){
            if(node==par[node]){
                return node;
            }
            return par[node]=findUPar(par[node]);
        }

        bool unionByRank(int u,int v){
            int uPar_u=findUPar(u);
            int uPar_v=findUPar(v);
            if(uPar_u==uPar_v){
                return false;
            }
            if(rank[uPar_u]>rank[uPar_v]){
                par[uPar_v]=uPar_u;
            }
            else if(rank[uPar_u]<rank[uPar_v]){
                par[uPar_u]=uPar_v;
            }
            else{
                par[uPar_u]=uPar_v;
                rank[uPar_v]++;
            }
            return true;
        }
    };


    int countComponents(int n, vector<vector<int>>& edges) {
       DSU Disjoint(n);
       int res=n;
       for(auto it:edges){
        if(Disjoint.unionByRank(it[0],it[1])){
            res--;
        }
       }
       return res;
    }
};
