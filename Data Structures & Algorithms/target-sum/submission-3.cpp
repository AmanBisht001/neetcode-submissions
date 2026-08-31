class Solution {
public:
    
    int solve(int ind,int target,vector<int>&nums,vector<vector<int>>&dp){
        if(ind==0){
            if(target==0){
                if(nums[0]==0){
                    return 2;
                }
                
            }
            if(target==0||target==nums[0]){
                    return 1;
            }
            return 0;
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        
        int notpick=solve(ind-1,target,nums,dp);
        int Pick=0;
        if(nums[ind]<=target){
            Pick=solve(ind-1,target-nums[ind],nums,dp);
        }
        return dp[ind][target]= notpick+Pick;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum-target<0 || (sum-target)%2){
            return false;
        }
        int req = (sum - target) / 2; int n = nums.size(); vector<vector<int>> dp(n, vector<int>(req + 1, -1));
        return solve(n-1,(sum-target)/2,nums,dp);
    }
};