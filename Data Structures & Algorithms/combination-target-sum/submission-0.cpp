class Solution {
public:
    void solve(int idx,vector<int>&nums,int target,vector<vector<int>>&ans,vector<int>&temp){
        if(idx<0){
            return ;
        }
        if(target==0){
            ans.push_back(temp);
            return ;
        }

        if(target-nums[idx]>=0){
            temp.push_back(nums[idx]);
            solve(idx,nums,target-nums[idx],ans,temp);
            temp.pop_back();
        }
        solve(idx-1,nums,target,ans,temp);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n=nums.size();
        solve(n-1,nums,target,ans,temp);
        return ans;

    }
};
