class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int i=0;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        while(i<n){
            int start=intervals[i][0];
            int end=intervals[i][1];
            bool flag=false;
            while(i+1<n&&intervals[i+1][0]<=end){
                end=max(end,intervals[i+1][1]);
                i++;
                flag=true;
            }
            i++;
            
          
            ans.push_back({start,end});
        }
        return ans;
    }
};
