class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int>mpp;
        sort(hand.begin(),hand.end());
        int n=hand.size();
        if(n%groupSize!=0){
            return false;
        }
        for(int i=0;i<hand.size();i++){
            mpp[hand[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mpp.find(hand[i])==mpp.end()){
                continue;
            }
            if(mpp.find(hand[i]-1)==mpp.end()){
                int num=hand[i];
                for(int j=0;j<groupSize;j++){
                    if(mpp.find(num+j)!=mpp.end()){
                        mpp[num+j]--;
                        if(mpp[num+j]==0){
                            mpp.erase(num+j);
                        }
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
