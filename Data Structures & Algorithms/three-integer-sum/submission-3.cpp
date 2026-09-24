class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++){
            
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int num=nums[i];
            int l=i+1;
            int r=n-1;
            while(l<r){
                int res=nums[l]+nums[r]+num;
                if(res==0){
                    ans.push_back({num,nums[l],nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                }
                else if(res>0){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return ans;
    }
};
