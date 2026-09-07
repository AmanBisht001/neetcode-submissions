class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                q.push({0,i});
            }
            if(board[m-1][i]=='O'){
                q.push({m-1,i});
            }
        }
        for(int i=0;i<m;i++){
            if(board[i][n-1]=='O'){
                q.push({i,n-1});
            }
            if(board[i][0]=='O'){
                q.push({i,0});
            }
        }
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int row=it.first;
            int col=it.second;
             board[row][col]='F';
            int dr[]={-1,0,1,0};
            int dc[]={0,-1,0,1};
            for(int i=0;i<4;i++){
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow>=0&&ncol>=0&&nrow<m&&ncol<n&&board[nrow][ncol]=='O'){
                   
                    q.push({nrow,ncol});
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='F'){
                    board[i][j]='O';
                }
            }
        }

        
    }
};
