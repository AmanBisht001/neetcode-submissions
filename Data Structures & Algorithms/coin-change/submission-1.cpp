class Solution {
public:
    int solve(int ind,vector<int>&coins,int target,vector<vector<int>>&dp){
        if(target==0){
            return 0;
        }
        if(ind<0){
            return 1e7;
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }

        int notTake=solve(ind-1,coins,target,dp);
        int Take=1e7;
        if(coins[ind]<=target){
            Take=1+solve(ind,coins,target-coins[ind],dp);
        }
        return dp[ind][target]=min(Take,notTake);

    }

    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans= solve(n-1,coins,amount,dp);
        if(ans>=1e7){
            return -1;
        }
        return ans;
    }
};
