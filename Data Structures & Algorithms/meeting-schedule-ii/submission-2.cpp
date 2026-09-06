/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
         int n=intervals.size();
        sort(intervals.begin(),intervals.end(),[](auto a,auto b){
            return a.start<b.start;
        });
        priority_queue<int,vector<int>,greater<int>>q;
        for(auto it:intervals){
            if(!q.empty()&&q.top()<=it.start){
                q.pop();
            }
            q.push(it.end);
        }
        return q.size();
    }
};
