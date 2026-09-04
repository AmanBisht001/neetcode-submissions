class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int>temp(3,-1);
        for(auto it:triplets){
            if(it[0]<=target[0]&&it[1]<=target[1]&&it[2]<=target[2]){
                temp[0]=max(temp[0],it[0]);
                temp[1]=max(temp[1],it[1]);
                temp[2]=max(temp[2],it[2]);
            }
        }
        if(temp==target){
            return true;
        }
        return false;
    }
};
