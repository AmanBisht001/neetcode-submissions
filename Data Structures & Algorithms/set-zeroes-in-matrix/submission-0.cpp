class Solution {
public:
    void solve(int row,int col,vector<vector<int>>&matrix){
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            if(matrix[i][col]==0){
                continue;
            }
            matrix[i][col]=-1;
        }
        for(int i=0;i<n;i++){
            if(matrix[row][i]==0){
                continue;
            }
            matrix[row][i]=-1;
        }

    }

    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    solve(i,j,matrix);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==-1){
                    matrix[i][j]=0;
                }
            }
        }
        
    }
};
