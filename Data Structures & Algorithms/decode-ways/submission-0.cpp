class Solution {
public:
    int solve(int ind,string& s,vector<int>&dp){
        if(ind==s.length()){
            return 1;
        }
        if(s[ind]=='0'){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int ways=solve(ind+1,s,dp);
        int two=0;
        if(ind+1<s.length()){
            int num=(s[ind]-'0')*10+(s[ind+1]-'0');
            if(num>0&&num<=26){
                two=solve(ind+2,s,dp);
            }
        }
        return dp[ind]=ways+two;
    }

    int numDecodings(string s) {
        int n=s.length();   
        vector<int>dp(n+1,-1);
        return solve(0,s,dp);

    }
};
