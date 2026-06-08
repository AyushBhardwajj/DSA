class Solution {
public:
    bool solve(vector<int> &wt,int mid,int days){
        int curr = 0;
        int d = 1;

        for(int i=0;i<wt.size();i++){
            curr += wt[i];

            if(curr>mid){
                d++;
                curr = wt[i];
            }

            if(d>days)return false;
        }

        return d<=days;


    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);

        int ans = high;

        while(low<=high){
            int mid = low + (high-low)/2;

            bool flag = solve(weights,mid,days);

            if(flag){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return ans;
    }
};