class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int leftProduct=1;
        int rightProduct=1;
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            leftProduct*=nums[i];
            maxi=max(maxi,leftProduct);
            if(leftProduct==0){
                leftProduct=1;

            }
            
        }
        for(int i=n-1;i>=0;i--){
            rightProduct*=nums[i];
            maxi=max(maxi,rightProduct);
            if(rightProduct==0){
                rightProduct=1;
            }
            
        }
        return maxi;
    }
};
