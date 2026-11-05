class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();

        priority_queue<vector<int>> pq;

        int ans = 1;
        int l = intervals[0][0],r = intervals[0][1];
        pq.push(intervals[0]);

        for(int i=1;i<n;i++){
            if(intervals[i][0]<r){
                if(intervals[i][1]<r){
                    pq.pop();
                    pq.push(intervals[i]);
                    r = intervals[i][1];
                }
            }
            else {
                ans++;
                r = intervals[i][1];
            }
        }

        return intervals.size()-ans;
    }
};