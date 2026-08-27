class Solution {
public:
    int solve(int ind,vector<int>&nums,vector<int>&dp){
        if(ind<0){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int take=solve(ind-1,nums,dp);
        int notTake=nums[ind]+solve(ind-2,nums,dp);
        
        return dp[ind]=max(take,notTake);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int>temp(nums.begin(),nums.end()-1);
        int n=nums.size()-1;
        vector<int>dp(n+1,-1);
        int first=solve(n-1,temp,dp);
        // temp.erase();
        temp=vector<int>(nums.begin()+1,nums.end());
        dp=vector<int>(n+1,-1);
        int second=solve(n-1,temp,dp);
        return max(first,second);
        
    }
};
