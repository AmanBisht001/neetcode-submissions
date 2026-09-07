class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int time=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto it=q.front();
                q.pop();
                int row=it.first;
                int col=it.second;
                int dr[]={-1,0,1,0};
                int dc[]={0,-1,0,1};
                for(int j=0;j<4;j++){
                    int nrow=row+dr[j];
                    int ncol=col+dc[j];
                    if(nrow>=0&&ncol>=0&&nrow<m&&ncol<n&&grid[nrow][ncol]==1){
                        grid[nrow][ncol]=2;
                        q.push({nrow,ncol});
                    }
                }
            }
            time++;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return time>0?time-1:0;
    }
};
