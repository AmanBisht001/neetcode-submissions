class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        int i=0;
        while(i<n&&i<=maxi){
            maxi=max(maxi,i+nums[i]);
            i++;
        }
        if(i<n){
            return false;
        }
        return true;
    }
};
