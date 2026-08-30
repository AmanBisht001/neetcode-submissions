class Solution {
public:
    int solve(int ind1,int ind2,string text1,string text2,vector<vector<int>>&dp){
        if(ind1>=text1.length()||ind2>=text2.length()){
            return 0;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        int notTake=max(solve(ind1-1,ind2,text1,text2,dp),solve(ind1,ind2-1,text1,text2,dp));
        int take=0;
        if(text1[ind1]==text2[ind2]){
            take=1+solve(ind1-1,ind2-1,text1,text2,dp);
        }
        return dp[ind1][ind2]= max(notTake,take);
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.length();
        int n2=text2.length();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return solve(n1-1,n2-1,text1,text2,dp);
    }
};
