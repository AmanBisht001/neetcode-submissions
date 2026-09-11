class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        vector<int>ans;
        int rem=0;
        digits[n-1]+=1;
        for(int i=n-1;i>=0;i--){
            int num=(digits[i]+rem)%10;
            ans.push_back(num);
            rem=(digits[i]+rem)/10;
        }
        if(rem){
            ans.push_back(rem);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
