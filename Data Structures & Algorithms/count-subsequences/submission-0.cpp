class Solution {
public:
    int solve(int ind1,int ind2,string s,string t,vector<vector<int>>&dp){
        if(ind2<0){
            return 1;
        }
        if(ind1<0||ind2<0){
            return 0;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        int notTake=solve(ind1-1,ind2,s,t,dp);
        int take=0;
        if(s[ind1]==t[ind2]){
            take=solve(ind1-1,ind2-1,s,t,dp);
        }
        return dp[ind1][ind2]= take+notTake;

    }

    int numDistinct(string s, string t) {
        int sn=s.length();
        int tn=t.length();
        vector<vector<int>>dp(sn,vector<int>(tn,-1));
        return solve(sn-1,tn-1,s,t,dp);
    }
};
