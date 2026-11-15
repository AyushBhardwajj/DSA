class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newIntervals) {

        int n = intervals.size();

        vector<vector<int>> ans;

        if(n==0){
            ans.push_back(newIntervals);
            return ans;
        }



        int ind = 1;
        int start = intervals[0][0], end = intervals[0][1];
        bool flag = true;
        if(newIntervals[0]<start){
            start = newIntervals[0];
            end = newIntervals[1];
            flag = false;
            ind = 0;
        }

        while(ind<n){
            if(flag){
                if(newIntervals[0]<=intervals[ind][0]){
                    if(newIntervals[0]>end){
                        ans.push_back({start,end});
                        start = newIntervals[0];
                        end = max(end,newIntervals[1]);
                    }
                    else{
                        end = max(end,newIntervals[1]);
                    }

                    flag = false;
                }
            }
            if(end<intervals[ind][0]){
                ans.push_back({start,end});
                start = intervals[ind][0];
                end = intervals[ind][1];
            }
            else{
                end = max(intervals[ind][1],end);
            }
            ind++;
        }

        // ans.push_back({start,end});

        if(flag){
            if(end>=newIntervals[0]){
                end = max(end,newIntervals[1]);
                flag = false;
            }
    
        }

        ans.push_back({start,end});
        if(flag){
            ans.push_back({newIntervals[0],newIntervals[1]});
        }

        return ans;
    }
};