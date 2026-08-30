class Solution {
public:
    bool solve(int ind,vector<int>&nums,int target,vector<vector<int>>&dp){
        if(target==0){
            return true;
        }
        if(ind<0){
            return false;
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        bool notTake=solve(ind-1,nums,target,dp);
        bool Take=false;
        if(target>=nums[ind]){
            Take=solve(ind-1,nums,target-nums[ind],dp);
        }
        return dp[ind][target]= notTake||Take;
    }

    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        vector<vector<int>>dp(n,vector<int>((sum/2)+1,-1));
        if(solve(n-1,nums,sum/2,dp)){
            return true;
        }
        return false;
    }
};
