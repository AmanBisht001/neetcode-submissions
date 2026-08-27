class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int res=0;
        int st=0;
        for(int i=0;i<n;i++){
            int l=i;
            int r=i;
            while(l>=0&&r<n&&s[l]==s[r]){
                l--;
                r++;
            }
            if(res<r-l-1){
                res=r-l-1;
                st=l+1;
            }
            l=i;
            r=i+1;
            while(l>=0&&r<n&&s[l]==s[r]){
                l--;
                r++;
            }

            if(res<r-l-1){
                res=r-l-1;
                st=l+1;
            }
        }
        string ans=s.substr(st,res);
        return ans;
    }
};
