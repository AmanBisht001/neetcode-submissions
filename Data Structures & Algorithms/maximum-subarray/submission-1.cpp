class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int leftSum=0;
        int rightSum=0;
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            leftSum+=nums[i];
            maxi=max(maxi,leftSum);
            if(leftSum<0){
                leftSum=0;
            }
        }
        for(int i=n-1;i>=0;i--){
            rightSum+=nums[i];
            maxi=max(maxi,rightSum);
            if(rightSum<0){
                rightSum=0;
            }
        }
        return maxi;
    }
};
