class Solution {
public:
    int solve(int idx,vector<int>&nums,vector<int>&dp){
        if(idx>=nums.size()){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int one=nums[idx]+solve(idx+1,nums,dp);
        int two=nums[idx]+solve(idx+2,nums,dp);
        return dp[idx]=min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+2,-1);
        return min(solve(0,cost,dp),solve(1,cost,dp));
    }
};
