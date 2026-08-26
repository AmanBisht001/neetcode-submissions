class Solution {
public:
    void solve(vector<bool>&vis,vector<int>&nums,vector<int>&temp,vector<vector<int>>&ans){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return ;
        }

        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                temp.push_back(nums[i]);
                vis[i]=true;
                solve(vis,nums,temp,ans);
                temp.pop_back();
                vis[i]=false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n=nums.size();
        vector<bool>vis(n,false);
        solve(vis,nums,temp,ans);
        return ans;
    }
};
