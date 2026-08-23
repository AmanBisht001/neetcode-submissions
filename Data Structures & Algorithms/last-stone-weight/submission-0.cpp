class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>q;
        for(int num:stones){
            q.push(num);
        }
        while(q.size()>1){
            int one=q.top();
            q.pop();
            int two=q.top();
            q.pop();
            if(one==two){
                continue;
            }
            if(one>two){
                int add=abs(one-two);
                q.push(add);
            }
        }
        if(q.size()==1){
            return q.top();
        }
        return 0;
    }
};
