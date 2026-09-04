class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.length();
        unordered_map<char,int>mpp;
        for(int i=0;i<n;i++){
            mpp[s[i]]=i;
        }
        int i=0;
        vector<int>ans;
        while(i<n){
            
            int end=mpp[s[i]];
            for(int j=i;j<=end;j++){
                end=max(end,mpp[s[j]]);
            }
            int gap=end-i+1;
            ans.push_back(gap);
            i=end+1;
        }
        return ans;
    }
};
