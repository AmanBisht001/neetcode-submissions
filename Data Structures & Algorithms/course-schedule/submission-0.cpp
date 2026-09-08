class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>inorder(numCourses,0);
        vector<vector<int>>adj(numCourses);
        for(auto it:prerequisites){
            inorder[it[1]]++;
            adj[it[0]].push_back(it[1]);
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(inorder[i]==0){
                q.push(i);
            }
        }
        int finish=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            finish++;
            for(int neigh:adj[node]){
                inorder[neigh]--;
                if(inorder[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        return finish==numCourses;
    }
};
