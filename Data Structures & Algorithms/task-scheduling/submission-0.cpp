class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    
        priority_queue<int>pq;

        vector<int>ch(27,0);
        for(char task:tasks){
            ch[task-'A']++;
        }
        for(int i=0;i<27;i++){
            if(ch[i]>0){
                pq.push(ch[i]);
            }
        }
        int ans=0;
        while(!pq.empty()){
            vector<int>temp;
            int i=0;
            for(;i<n+1;i++){
                if(!pq.empty()){
                    int num=pq.top()-1;
                    pq.pop();
                    temp.push_back(num); 
                }
            }
            for(int i=0;i<temp.size();i++){
                if(temp[i]>0){
                    pq.push(temp[i]);
                }
            }
            if(pq.empty()){
                ans+=temp.size();
            }
            else{
                ans+=n+1;
            }
        }
        return ans;
    }
};
