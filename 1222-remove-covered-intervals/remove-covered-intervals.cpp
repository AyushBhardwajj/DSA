class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[&](vector<int> &a,vector<int> &b){
            if(a[0] == b[0])return b[1]<a[1];
            return a[0]<b[0];
        });
        int n = intervals.size();
        int ans = 1;
        int l = intervals[0][0];
        int r = intervals[0][1];

        for(int i=1;i<n;i++){
            if(r<intervals[i][1]){
                ans++;
                r = intervals[i][1];
            }
        }

        return ans;
    }
};