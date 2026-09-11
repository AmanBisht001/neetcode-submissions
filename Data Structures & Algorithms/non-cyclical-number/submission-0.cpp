class Solution {
public:
    int findSum(int n){
        int sum=0;
        while(n>0){
            int last=n%10;
            sum+=(last*last);
            n=n/10;
        }
        return sum;
    }

    bool isHappy(int n) {
        unordered_set<int>st;
        while(st.find(n)==st.end()){
            st.insert(n);
            n=findSum(n);
            if(n==1){
                return true;
            }
        }
        return false;
    }
};
